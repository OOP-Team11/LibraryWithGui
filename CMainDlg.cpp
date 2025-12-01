// CMainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CMainDlg.h"
#include "CMyDlg.h"
#include "CManagerDlg.h"


// CMainDlg 대화 상자

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CMainDlg::setManager(MainManager* ptr) {
	this->m_pMainManager = ptr;
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_BOOKNAME, &CMainDlg::OnEnChangeEditBookname)
	ON_EN_CHANGE(IDC_EDIT_WRITER, &CMainDlg::OnEnChangeEditWriter)
	ON_CBN_SELCHANGE(IDC_COMBO_CATEGORY, &CMainDlg::OnCbnSelchangeComboCategory)
	ON_BN_CLICKED(IDC_BUTTON_MY, &CMainDlg::OnBnClickedButtonMy)
	ON_BN_CLICKED(IDC_BUTTON_GETBOOKS, &CMainDlg::OnBnClickedButtonGetbooks)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHBOOK, &CMainDlg::OnBnClickedButtonSearchbook)
	ON_BN_CLICKED(IDC_BUTTON_DOLOAN, &CMainDlg::OnBnClickedButtonDoloan)
	ON_BN_CLICKED(IDC_BUTTON_MANAGE, &CMainDlg::OnBnClickedButtonManage)
	ON_LBN_SELCHANGE(IDC_LIST_BOOKS, &CMainDlg::OnLbnSelchangeListBooks)
END_MESSAGE_MAP()


// CMainDlg 메시지 처리기

void CMainDlg::OnEnChangeEditBookname()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnEnChangeEditWriter()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnCbnSelchangeComboCategory()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnBnClickedButtonMy()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// MyPage 창 실행
	CMyDlg myDlg;
	myDlg.setManager(m_pMainManager);
	INT_PTR myResult = myDlg.DoModal();

}

void CMainDlg::OnBnClickedButtonGetbooks()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnBnClickedButtonSearchbook()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnBnClickedButtonDoloan()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnBnClickedButtonManage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// Manager 페이지 생성
	// 실제로는 권한 검사도 해야함.
	CManagerDlg managerDlg;
	managerDlg.setManager(m_pMainManager);
	INT_PTR managerResult = managerDlg.DoModal();
}

void CMainDlg::OnLbnSelchangeListBooks()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
