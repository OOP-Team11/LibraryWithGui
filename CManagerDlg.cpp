// CManagerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CManagerDlg.h"


// CManagerDlg 대화 상자

IMPLEMENT_DYNAMIC(CManagerDlg, CDialogEx)

CManagerDlg::CManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MANAGER, pParent)
{

}

CManagerDlg::~CManagerDlg()
{
}

void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CManagerDlg::setManager(MainManager* ptr) {
	this->m_pMainManager = ptr;
}


BEGIN_MESSAGE_MAP(CManagerDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CManagerDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CManagerDlg::OnEnChangeEdit2)
	ON_CBN_SELCHANGE(IDC_COMBO_CATEGORY, &CManagerDlg::OnCbnSelchangeComboCategory)
	ON_BN_CLICKED(IDC_BUTTON_INSERTBOOK, &CManagerDlg::OnBnClickedButtonInsertbook)
	//ON_BN_CLICKED(IDC_BUTTON_DELETEBOOK, &CManagerDlg::OnBnClickedButtonDeletebook)
END_MESSAGE_MAP()


// CManagerDlg 메시지 처리기

void CManagerDlg::OnEnChangeEdit1() 
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CManagerDlg::OnEnChangeEdit2() 
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CManagerDlg::OnCbnSelchangeComboCategory() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CManagerDlg::OnBnClickedButtonInsertbook()
{
    if (m_pMainManager == nullptr) return;

    // 입력값 가져오기
    CString cname, cwriter;
    GetDlgItemText(IDC_EDIT1, cname);   // 책 제목 입력 칸
    GetDlgItemText(IDC_EDIT2, cwriter); // 작가 입력 칸

    // 변환
    CT2A convName(cname);
    CT2A convWriter(cwriter);
    string name = string(convName);
    string writer = string(convWriter);

    // 카테고리
    CComboBox* pCat = (CComboBox*)GetDlgItem(IDC_COMBO_CATEGORY);
    int sel = pCat->GetCurSel();

    BookCategory category;
    switch (sel)
    {
    case 0: category = BookCategory::All; break;
    case 1: category = BookCategory::General; break;
    case 2: category = BookCategory::Philosophy; break;
    case 3: category = BookCategory::Religion; break;
    case 4: category = BookCategory::SocialSci; break;
    case 5: category = BookCategory::NaturalSci; break;
    case 6: category = BookCategory::Technology; break;
    case 7: category = BookCategory::Arts; break;
    case 8: category = BookCategory::Language; break;
    case 9: category = BookCategory::Literature; break;
    case 10: category = BookCategory::History; break;
    default: category = BookCategory::General;
    }

    // MainManager → BookManager insert 호출
    m_pMainManager->insertBook(name, writer, category);

    AfxMessageBox(L"도서가 등록되었습니다.");
}


/*void CManagerDlg::OnBnClickedButtonDeletebook()
{
    if (m_pMainManager == nullptr) return;

    
    int bookId; //임시로 id 선언
    int userId = m_pMainManager->getUserId();

    try {
        m_pMainManager->deleteBook(bookId,userId);
        AfxMessageBox(L"도서 삭제 완료!");
    }
    catch (const std::exception& e) {
        CString msg(e.what());
        AfxMessageBox(msg); //userId가 관리자Id(1234)가 아니면 에러를 catch해서 에러메시지 그대로 띄우기
    }

    AfxMessageBox(L"도서 삭제 요청 완료");
}*/

