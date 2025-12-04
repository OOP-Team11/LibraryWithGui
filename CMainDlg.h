#pragma once
#include "afxdialogex.h"
#include "mainManager.h"


// CMainDlg 대화 상자

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMainDlg();
	void setManager(MainManager* ptr);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

private:
	MainManager* m_pMainManager; // 포인터로 보관
	int selectedBookId;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditBookname();
	afx_msg void OnEnChangeEditWriter();
	afx_msg void OnCbnSelchangeComboCategory();
	afx_msg void OnBnClickedButtonMy();
	afx_msg void OnBnClickedButtonGetbooks();
	afx_msg void OnBnClickedButtonSearchbook();
	afx_msg void OnBnClickedButtonDoloan();
	afx_msg void OnBnClickedButtonManage();
	afx_msg void OnLbnSelchangeListBooks();
	afx_msg void OnBnClickedButtonDeletebook();
	afx_msg void OnCbnSelchangeEdit1();
};
