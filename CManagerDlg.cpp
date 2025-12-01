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
	ON_BN_CLICKED(IDC_BUTTON_DELETEBOOK, &CManagerDlg::OnBnClickedButtonDeletebook)
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CManagerDlg::OnBnClickedButtonDeletebook() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
