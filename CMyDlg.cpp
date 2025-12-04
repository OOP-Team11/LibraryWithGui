// CMyDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CMyDlg.h"

// CMyDlg 대화 상자

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MY, pParent), selectedLoanId(-1)
{
}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CMyDlg::setManager(MainManager* ptr) {
	this->m_pMainManager = ptr;
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_LOANS, &CMyDlg::OnLbnSelchangeListLoans)
	ON_EN_CHANGE(IDC_EDIT_USERNAME, &CMyDlg::OnEnChangeEditUsername)
	ON_BN_CLICKED(IDC_BUTTON_EXTEND, &CMyDlg::OnBnClickedButtonExtend)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &CMyDlg::OnBnClickedButtonReturn)
	ON_BN_CLICKED(IDC_BUTTON_DELETEME, &CMyDlg::OnBnClickedButtonDeleteme)
END_MESSAGE_MAP()


// CMyDlg 메시지 처리기

void CMyDlg::OnLbnSelchangeListLoans()
{
	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_LOANS);
	int sel = pList->GetCurSel();
	if (sel == LB_ERR) return;

	CString text;
	pList->GetText(sel, text);

	// text 예: "LoanID:3 | BookID:2 | 2024-02-05 ~ 2024-02-12"
	int id;
	swscanf_s(text, L"LoanID:%d", &id);

	selectedLoanId = id;
}

void CMyDlg::OnEnChangeEditUsername() 
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMyDlg::OnBnClickedButtonExtend() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (selectedLoanId == -1) {
		AfxMessageBox(L"연장할 대출을 선택하세요.");
		return;
	}

	m_pMainManager->extendLoan(selectedLoanId);

	AfxMessageBox(L"대출 기간이 7일 연장되었습니다.");

	updateLoanList();
}

void CMyDlg::OnBnClickedButtonReturn() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (selectedLoanId == -1) {
		AfxMessageBox(L"반납할 대출을 선택하세요.");
		return;
	}

	m_pMainManager->returnLoan(selectedLoanId);

	AfxMessageBox(L"도서가 성공적으로 반납되었습니다.");

	selectedLoanId = -1;

	updateLoanList();
}

void CMyDlg::OnBnClickedButtonDeleteme() 
{	
	// 성공한 경우
	if (this->m_pMainManager->deleteMe()) {
		AfxMessageBox(L"탈퇴가 성공적으로 완료되었습니다.");
	}
	else AfxMessageBox(L"탈퇴에 실패하였습니다.");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMyDlg::updateLoanList()
{
	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_LOANS);
	pList->ResetContent();

	vector<Loan> myLoans = m_pMainManager->getMyLoans();

	for (auto& l : myLoans) {
		CString item;
		sys_days s = l.getStartDate();
		sys_days e = l.getEndDate();

		year_month_day sd{ s };
		year_month_day ed{ e };

		item.Format(
			L"LoanID:%d | BookID:%d | %04d-%02d-%02d ~ %04d-%02d-%02d",
			l.getId(),
			l.getBookId(),
			(int)sd.year(), (unsigned)sd.month(), (unsigned)sd.day(),
			(int)ed.year(), (unsigned)ed.month(), (unsigned)ed.day()
		);

		pList->AddString(item);
	}
}

BOOL CMyDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// 사용자 이름 표시
	CString username(m_pMainManager->getUserName().c_str());
	SetDlgItemText(IDC_EDIT_USERNAME, username);

	// 내 대출 목록 불러와서 리스트에 표시
	updateLoanList();

	return TRUE;
}
