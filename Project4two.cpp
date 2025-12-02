
// Project4two.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다. 
//

#include "pch.h"
#include "framework.h"
#include "Project4two.h" 
//#include "Project4twoDlg.h"
#include "CLoginDlg.h" 
#include "CJoinSuccessDlg.h" 
#include "CJoinFailDlg.h" 
#include "CLoginFailDlg.h" 
#include "CMainDlg.h" 
#include "mainManager.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 메인 매니저 
MainManager mainManager; 

// CProject4twoApp

BEGIN_MESSAGE_MAP(CProject4twoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CProject4twoApp 생성

CProject4twoApp::CProject4twoApp()
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CProject4twoApp 개체입니다.

CProject4twoApp theApp;


// CProject4twoApp 초기화

BOOL CProject4twoApp::InitInstance() 
{
	// Windows XP에서는 InitCommonControlsEx()를 필요로 합니다.
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 대화 상자에 셸 트리 뷰 또는
	// 셸 목록 뷰 컨트롤이 포함되어 있는 경우 셸 관리자를 만듭니다.
	CShellManager *pShellManager = new CShellManager;

	// MFC 컨트롤의 테마를 사용하기 위해 "Windows 원형" 비주얼 관리자 활성화
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 애플리케이션 마법사에서 생성된 애플리케이션"));

	/*CProject4twoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 [확인]을 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 여기에 [취소]를 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "경고: 대화 상자를 만들지 못했으므로 애플리케이션이 예기치 않게 종료됩니다.\n");
		TRACE(traceAppMsg, 0, "경고: 대화 상자에서 MFC 컨트롤을 사용하는 경우 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS를 수행할 수 없습니다.\n");
	}*/

	// ============================ 
   // 1) 로그인 창 실행 
   // ============================ 
	CLoginDlg loginDlg; 
	loginDlg.setManager(&mainManager); 
	INT_PTR loginResult = loginDlg.DoModal(); 

	if (loginResult != IDOK) { 
		// 로그인 실패 또는 취소 → 프로그램 종료 
		if (pShellManager != nullptr) 
			delete pShellManager; 
		return FALSE; 
	} 

	// ============================ 
	// 2) 로그인 성공 → MainDlg 실행 
	// ============================ 
	CMainDlg mainDlg; 
	mainDlg.setManager(&mainManager); 
	m_pMainWnd = &mainDlg; 

	INT_PTR mainResult = mainDlg.DoModal(); 
	 
	if (pShellManager != nullptr) 
		delete pShellManager; 

	// 메인 다이얼로그가 닫히면 그냥 앱 종료 
	// (OK로 닫든 Cancel로 닫든 여기까지 오면 종료) 
	mainManager.Exit(); 
	return FALSE; 
}

