// CLoginFailDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CLoginFailDlg.h"


// CLoginFailDlg 대화 상자

IMPLEMENT_DYNAMIC(CLoginFailDlg, CDialogEx)

CLoginFailDlg::CLoginFailDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGINFAIL, pParent)
{

}

CLoginFailDlg::~CLoginFailDlg()
{
}

void CLoginFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginFailDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginFailDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLoginFailDlg 메시지 처리기

void CLoginFailDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
