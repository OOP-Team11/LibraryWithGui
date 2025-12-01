#include "pch.h"
#include "loanManager.h"
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;


LoanManager::LoanManager() {
    loanCount = 0;
}

LoanManager::LoanManager(string filename) {
    loanCount = 1;

    ifstream fin(filename);
    if (!fin.is_open()) return;

    int id, bookId, memberId;
    string start, end;

    while (fin >> id >> bookId >> memberId >> start >> end) {
        loans.emplace_back(id, bookId, memberId, start, end);
        if (id >= loanCount) loanCount = id + 1;
    }
    fin.close();
}

void LoanManager::addLoan(const Loan& loan) { // txt 파일에서 읽어서 추가 or 대출 시 추가
    loans.push_back(loan);
}

bool LoanManager::removeLoan(int id) { // 삭제 성공 시 true 반환
    for (auto it = loans.begin(); it != loans.end(); ++it) {
        if (it->getId() == id) {
            loans.erase(it);
            return true;
        }
    }
    return false;
}

Loan* LoanManager::findLoan(int id) { // 포인터 반환 -> 없으면 nullptr
    for (auto& l : loans) {
        if (l.getId() == id)
            return &l;
    }
    return nullptr;
}

Loan* LoanManager::findLoanByMember(int memberId) {
    for (auto& l : loans) {
        if (l.getMemberId() == memberId)
            return &l;
    }
    return nullptr;
}

void LoanManager::save(string filename) {
    ofstream fout(filename);

    for (auto& l : loans) {
        sys_days s = l.getStartDate();
        sys_days e = l.getEndDate();

        year_month_day sd{ s };
        year_month_day ed{ e };

        fout << l.getId() << " "
            << l.getBookId() << " "
            << l.getMemberId() << " "
            << int(sd.year()) << "-" << unsigned(sd.month()) << "-" << unsigned(sd.day()) << " "
            << int(ed.year()) << "-" << unsigned(ed.month()) << "-" << unsigned(ed.day())
            << "\n";
    }

    fout.close();
}

void LoanManager::loan(int memberId, int bookId) {// 도서 대출 : 이 함수 안에서 Loan() 생성자 호출 -> 이후 addLoan에 인수로 넣기. 대출 기간은 7일.
    auto today = floor<days>(system_clock::now());
    auto end = today + days{ 7 };

    Loan newLoan(loanCount, bookId, memberId, today, end);
    loanCount++;

    addLoan(newLoan);
}

void LoanManager::extendLoan(int loanId) {
    Loan* l = findLoan(loanId);
    if (l == nullptr) return;

    l->extendEndDate(); // Loan 객체 내부에서 7일 연장
}
void LoanManager::returnLoan(int loanId) {// 도서 반납
    removeLoan(loanId);
}

vector<Loan> LoanManager::getAllLoansOfMe(int memberId) const {// 내 대출 목록 보기 : findLoanByMember 이용하기
    vector<Loan> result;

    for (const auto& l : loans) {
        if (l.getMemberId() == memberId)
            result.push_back(l);
    }

    return result;
}