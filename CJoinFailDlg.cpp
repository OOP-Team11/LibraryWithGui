// CJoinFailDlg.cpp: 구현 파일 
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CJoinFailDlg.h"


// CJoinFailDlg 대화 상자

IMPLEMENT_DYNAMIC(CJoinFailDlg, CDialogEx)

CJoinFailDlg::CJoinFailDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_JOINFAIL, pParent)
{

}

CJoinFailDlg::~CJoinFailDlg()
{
}

void CJoinFailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CJoinFailDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CJoinFailDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CJoinFailDlg 메시지 처리기

void CJoinFailDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
