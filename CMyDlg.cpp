// CMyDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CMyDlg.h"


// CMyDlg 대화 상자

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MY, pParent)
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
}

void CMyDlg::OnBnClickedButtonReturn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMyDlg::OnBnClickedButtonDeleteme()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
