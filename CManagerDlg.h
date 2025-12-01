#pragma once
#include "afxdialogex.h"
#include "mainManager.h"


// CManagerDlg 대화 상자

class CManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerDlg)

public:
	CManagerDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CManagerDlg();
	void setManager(MainManager* ptr);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MANAGER };
#endif

private:
	MainManager* m_pMainManager; // 포인터로 보관
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnCbnSelchangeComboCategory();
	afx_msg void OnBnClickedButtonInsertbook();
	afx_msg void OnBnClickedButtonDeletebook();
};
