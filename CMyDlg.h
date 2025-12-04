#pragma once
#include "afxdialogex.h"
#include "mainManager.h"


// CMyDlg 대화 상자

class CMyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg)

public:
	CMyDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyDlg();
	void setManager(MainManager* ptr);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MY };
#endif

private:
	MainManager* m_pMainManager; // 포인터로 보관
	int selectedLoanId;
	void updateLoanList();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeListLoans();
	afx_msg void OnEnChangeEditUsername();
	afx_msg void OnBnClickedButtonExtend();
	afx_msg void OnBnClickedButtonReturn();
	afx_msg void OnBnClickedButtonDeleteme();
};
