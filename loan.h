#pragma once
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Loan {
private:
	int id;
	int bookId;
	int memberId;
	sys_days startdate; // 지피티한테 chrono 물어보기. 오늘 기준으로 날짜 생성 및 날짜 더하기, 날짜 비교 다 지원해줌.
	sys_days enddate; 

public:
	// constructor
	Loan();
	Loan(int id, int bookId, int memberId, string startdate, string enddate); // 파일 읽을때 (.txt 파일이라 string으로 읽게됨)
	Loan(int id, int bookId, int memberId, sys_days startdate, sys_days enddate); // 대출시

	// getter
	int getId() const;
	int getBookId() const;
	int getMemberId() const;
	sys_days getStartDate() const;
	sys_days getEndDate() const;

	// setter
	void extendEndDate(); // 연장할 때 사용.

	// function
	bool isExpired(); // 반납일 지났는 지.
};
