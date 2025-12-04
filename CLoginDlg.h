#pragma once
#include "afxdialogex.h"
#include "mainManager.h"


// CLoginDlg 대화 상자

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLoginDlg();
	void setManager(MainManager* ptr);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

private :
	MainManager* m_pMainManager = nullptr; // 포인터로 보관
	/* 프라이빗 멤버변수 추가 */
	CString m_password;
	CString m_nickname;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditNickname();
	afx_msg void OnBnClickedButtonJoin();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnBnClickedButtonLogin();
};
