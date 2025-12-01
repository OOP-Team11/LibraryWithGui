#pragma once
#include "afxdialogex.h"


// CJoinFailDlg 대화 상자

class CJoinFailDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJoinFailDlg)

public:
	CJoinFailDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CJoinFailDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JOINFAIL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
