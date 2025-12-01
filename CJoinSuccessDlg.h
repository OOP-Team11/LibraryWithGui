#pragma once
#include "afxdialogex.h"


// CJoinSuccessDlg 대화 상자

class CJoinSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJoinSuccessDlg)

public:
	CJoinSuccessDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CJoinSuccessDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JOINSUCCESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
