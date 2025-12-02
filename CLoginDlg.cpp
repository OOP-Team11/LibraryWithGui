// CLoginDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"
#include <atlstr.h>
#include <string>
#include <atlconv.h>




// CLoginDlg 대화 상자

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent),
	m_pMainManager(nullptr)
{	

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NICKNAME, m_nickname);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
}

void CLoginDlg::setManager(MainManager* ptr) {
	this->m_pMainManager = ptr;
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NICKNAME, &CLoginDlg::OnEnChangeEditNickname)
	ON_BN_CLICKED(IDC_BUTTON_JOIN, &CLoginDlg::OnBnClickedButtonJoin)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CLoginDlg::OnEnChangeEditPassword)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CLoginDlg 메시지 처리기

void CLoginDlg::OnEnChangeEditNickname() 
{
}

void CLoginDlg::OnBnClickedButtonJoin() 
{
	USES_CONVERSION;
	UpdateData(TRUE); // ★ Edit -> CString 자동 복사

	if (m_nickname.IsEmpty() || m_password.IsEmpty()) {
		AfxMessageBox(L"닉네임과 비밀번호를 입력하세요.");
		return;
	}

	// CString -> string 변환
	CW2A nicknameConv(m_nickname, CP_UTF8);
	CW2A passwordConv(m_password, CP_UTF8);
	std::string nickname(nicknameConv);
	std::string password(passwordConv);

	m_pMainManager->join(nickname, password);
	AfxMessageBox(L"회원가입이 완료되었습니다.");

	EndDialog(IDOK);
}

void CLoginDlg::OnEnChangeEditPassword() 
{
}

void CLoginDlg::OnBnClickedButtonLogin() 
{
	USES_CONVERSION;
	UpdateData(TRUE); // ★ Edit -> CString 자동 복사

	if (m_nickname.IsEmpty() || m_password.IsEmpty()) {
		AfxMessageBox(L"닉네임과 비밀번호를 입력하세요.");
		return;
	}


	CW2A nicknameConv(m_nickname, CP_UTF8);
	CW2A passwordConv(m_password, CP_UTF8);
	std::string nickname(nicknameConv);
	std::string password(passwordConv);

	bool result = m_pMainManager->login(nickname, password);

	if (result)
		AfxMessageBox(L"로그인이 완료되었습니다.");
	else
		AfxMessageBox(L"로그인에 실패하였습니다.");

	EndDialog(IDOK);
}
