#pragma once
#pragma once
#include "loan.h"
#include <string>
#include <vector>
using namespace std;

class LoanManager {
private:
	int loanCount; // 1로 초기화. 무조건 증가만. txt 파일에서 읽을때는 '제일 큰 id' 가 Count 변수가 됨.
	vector<Loan> loans;

	// 실제 내부 작동 functions
	void addLoan (const Loan& loan); // txt 파일에서 읽어서 추가 or 대출 시
	bool removeLoan(int id); // 삭제 성공 시 true 반환

public:
	// constructor
	LoanManager(); // memberCount = 0 으로 초기화 해야함.
	LoanManager(string filename);

	// 내부 기능 functions
	Loan* findLoan(int id); // 포인터 반환 -> 없으면 nullptr
	Loan* findLoanByMember(int memberId);
	//vector<Loan> getAllLoans() const;
	void save(string filename);

	// 외부 기능 functions
	void loan(int memberId, int bookId); // 도서 대출 : 이 함수 안에서 Loan() 생성자 호출 -> 이후 addLoan에 인수로 넣기. 대출 기간은 7일.
	void extendLoan(int loanId); // 대출 연장
	void returnLoan(int loanId); // 도서 반납
	vector<Loan> getAllLoansOfMe(int memberId) const; // 내 대출 목록 보기 : findLoanByMember 이용하기
	
	// 자동 반납 (나중에 서영이 할 예정)
};