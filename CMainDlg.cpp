// CMainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Project4two.h"
#include "afxdialogex.h"
#include "CMainDlg.h"
#include "CMyDlg.h"
#include "CManagerDlg.h"


// CMainDlg 대화 상자

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CMainDlg::setManager(MainManager* ptr) {
	this->m_pMainManager = ptr;
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_BOOKNAME, &CMainDlg::OnEnChangeEditBookname)
	ON_EN_CHANGE(IDC_EDIT_WRITER, &CMainDlg::OnEnChangeEditWriter)
	ON_CBN_SELCHANGE(IDC_COMBO_CATEGORY, &CMainDlg::OnCbnSelchangeComboCategory)
	ON_BN_CLICKED(IDC_BUTTON_MY, &CMainDlg::OnBnClickedButtonMy)
	ON_BN_CLICKED(IDC_BUTTON_GETBOOKS, &CMainDlg::OnBnClickedButtonGetbooks)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHBOOK, &CMainDlg::OnBnClickedButtonSearchbook)
	ON_BN_CLICKED(IDC_BUTTON_DOLOAN, &CMainDlg::OnBnClickedButtonDoloan)
	ON_BN_CLICKED(IDC_BUTTON_MANAGE, &CMainDlg::OnBnClickedButtonManage)
	ON_LBN_SELCHANGE(IDC_LIST_BOOKS, &CMainDlg::OnLbnSelchangeListBooks)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_DELETEBOOK, &CMainDlg::OnBnClickedButtonDeletebook)
    ON_CBN_SELCHANGE(IDC_EDIT1, &CMainDlg::OnCbnSelchangeEdit1)
END_MESSAGE_MAP()


// CMainDlg 메시지 처리기

void CMainDlg::OnEnChangeEditBookname() 
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnEnChangeEditWriter() 
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnCbnSelchangeComboCategory() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMainDlg::OnBnClickedButtonMy() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// MyPage 창 실행
	CMyDlg myDlg;
	myDlg.setManager(m_pMainManager);
	INT_PTR myResult = myDlg.DoModal();

}

// BookCategory를 영어 문자열(Enum 이름 그대로)로 변환하는 함수
CString GetCategoryName(BookCategory category) {
    switch (category) {
    case BookCategory::All:         return L"All";
    case BookCategory::General:     return L"General";
    case BookCategory::Philosophy:  return L"Philosophy";
    case BookCategory::Religion:    return L"Religion";
    case BookCategory::SocialSci:   return L"SocialSci";
    case BookCategory::NaturalSci:  return L"NaturalSci";
    case BookCategory::Technology:  return L"Technology";
    case BookCategory::Arts:        return L"Arts";
    case BookCategory::Language:    return L"Language";
    case BookCategory::Literature:  return L"Literature";
    case BookCategory::History:     return L"History";
    default:                        return L"Unknown";
    }
}

void CMainDlg::OnBnClickedButtonGetbooks()
{
	if (m_pMainManager == nullptr) return;

	// MainManager에서 전체 리스트 가져오기
	vector<Book> list = m_pMainManager->getAllBooks();

	// 리스트박스 초기화
	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_BOOKS);
	pList->ResetContent();

    // 출력
    for (auto& b : list) {
        CString item;
        // [수정] 카테고리:%d -> %s 로 변경하고 GetCategoryName 함수 사용
        item.Format(L"[ID:%d] %S / %S / %s",
            b.getId(),
            b.getName().c_str(),
            b.getWriter().c_str(),
            GetCategoryName(b.getCategory()) // 숫자가 아닌 문자열 반환
        );
        pList->AddString(item);
    }
}


void CMainDlg::OnBnClickedButtonSearchbook()
{
    if (m_pMainManager == nullptr) return;

    // GUI에서 입력값 가져오기

    // 이름, 작가 텍스트 가져오기
    CString cname, cwriter;
    GetDlgItemText(IDC_EDIT_BOOKNAME, cname);
    GetDlgItemText(IDC_EDIT_WRITER, cwriter);

    // 공백 제거 (사용자가 실수로 스페이스바만 누른 경우 등 처리)
    cname.Trim();
    cwriter.Trim();

    // CString -> string 변환
    CT2A convName(cname);
    CT2A convWriter(cwriter);
    string name = string(convName);
    string writer = string(convWriter);

    // 콤보박스 카테고리 가져오기
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_EDIT1);
    int catIndex = pCombo->GetCurSel(); // 선택된 순서(0, 1, 2...)

    // 콤보박스 인덱스 -> 실제 BookCategory 값으로 변환
    BookCategory category;
    switch (catIndex)
    {
    case 0: category = BookCategory::All; break;
    case 1: category = BookCategory::General; break;
    case 2: category = BookCategory::Philosophy; break;
    case 3: category = BookCategory::Religion; break;
    case 4: category = BookCategory::SocialSci; break;
    case 5: category = BookCategory::NaturalSci; break;
    case 6: category = BookCategory::Technology; break;
    case 7: category = BookCategory::Arts; break;
    case 8: category = BookCategory::Language; break;
    case 9: category = BookCategory::Literature; break;
    case 10: category = BookCategory::History; break;
    default: category = BookCategory::All; break;
    }


    // 매니저에게 검색 요청 (SearchBook 메서드 활용)
    vector<Book> list = m_pMainManager->searchBook(name, writer, category);


    // 결과 리스트박스에 출력
    CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_BOOKS);
    pList->ResetContent(); // 기존 목록 싹 지우기

    for (auto& b : list) {
        CString item;

        // %s로 포맷팅하고 GetCategoryName 함수 사용 (영어 문자열 출력)
        item.Format(L"[ID:%d] %S / %S / %s",
            b.getId(),
            b.getName().c_str(),
            b.getWriter().c_str(),
            GetCategoryName(b.getCategory())
        );
        pList->AddString(item);
    }

    // 결과가 없을 때만 사용자에게 알림
    if (list.empty()) {
        AfxMessageBox(L"검색 결과가 없습니다.");
    }
}


void CMainDlg::OnBnClickedButtonDoloan() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMainDlg::OnBnClickedButtonManage() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// Manager 페이지 생성
	// 실제로는 권한 검사도 해야함.
    if (m_pMainManager == nullptr) return;

    // 관리자 권한 확인
    if (m_pMainManager->getUserRole()!=Role::Admin) {
        AfxMessageBox(L"관리자 권한이 없습니다. 접근할 수 없습니다.");
        return;   // 관리자 아니면 페이지 안 열림
    }

	CManagerDlg managerDlg;
	managerDlg.setManager(m_pMainManager);
	INT_PTR managerResult = managerDlg.DoModal();
}

void CMainDlg::OnLbnSelchangeListBooks() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMainDlg::OnBnClickedButtonDeletebook()
{
    if (m_pMainManager == nullptr) return;

    // 관리자 권한 확인
    if (m_pMainManager->getUserRole() != Role::Admin) {
        AfxMessageBox(L"관리자 권한이 없습니다. 접근할 수 없습니다.");
        return;   // 관리자 아니면 페이지 안 열림
    }

    // 리스트박스 제어권 가져오기
    CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST_BOOKS);
    if (pList == nullptr) return;

    // 현재 선택된 항목의 인덱스 확인
    int nSel = pList->GetCurSel();
    if (nSel == LB_ERR) {
        AfxMessageBox(L"삭제할 도서를 목록에서 선택해주세요.");
        return;
    }

    // 선택된 항목의 텍스트 가져오기
    CString strItem;
    pList->GetText(nSel, strItem);

    // 문자열 파싱하여 Book ID 추출
    int bookId = -1;

    // 성공하면 1을 반환함
    if (swscanf_s(strItem, L"[ID:%d]", &bookId) != 1) {
        AfxMessageBox(L"도서 정보를 읽을 수 없습니다. (ID 파싱 실패)");
        return;
    }

    // 삭제 실행, 예외 처리
    try {
        int userId = m_pMainManager->getUserId();

        // 삭제 요청 (ID가 없으면 예외 발생)
        m_pMainManager->deleteBook(bookId, userId);

        // 성공 시 리스트박스에서도 해당 항목 즉시 삭제
        pList->DeleteString(nSel);
        AfxMessageBox(L"도서 삭제 완료!");
    }
    catch (const std::exception& e) {
        // 에러 발생 시 메시지 출력
        CString msg;
        msg.Format(L"삭제 실패: %S", e.what());
        AfxMessageBox(msg);
    }
}



void CMainDlg::OnCbnSelchangeEdit1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
