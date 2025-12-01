#include "pch.h"
#include "loan.h"
#include <string>


// constructor
Loan::Loan()
    : id(0), bookId(0), memberId(0),
    startdate(sys_days{ year{1970} / 1 / 1 }),
    enddate(sys_days{ year{1970} / 1 / 1 })
{
}

Loan::Loan(int id, int bookId, int memberId, string start, string end)
    :id(id), bookId(bookId), memberId(memberId)
{
    // string → sys_days 변환
    // 형식: YYYY-MM-DD
    int y = stoi(start.substr(0, 4));
    int m = stoi(start.substr(5, 2));
    int d = stoi(start.substr(8, 2));
    startdate = sys_days{ year{y} / month{unsigned(m)} / day{unsigned(d)} };

    int y2 = stoi(end.substr(0, 4));
    int m2 = stoi(end.substr(5, 2));
    int d2 = stoi(end.substr(8, 2));
    enddate = sys_days{ year{y2} / month{unsigned(m2)} / day{unsigned(d2)}};
}

Loan::Loan(int id, int bookId, int memberId, sys_days startdate, sys_days enddate)
    : id(id), bookId(bookId), memberId(memberId), startdate(startdate), enddate(enddate)
{
}

// getter
int Loan::getId() const {
    return id;
}
int Loan::getBookId() const {
    return bookId;
}
int Loan::getMemberId() const {
    return memberId;
}
sys_days Loan::getStartDate() const {
    return startdate;
}
sys_days Loan::getEndDate() const {
    return enddate;
}

// setter
void Loan::extendEndDate() {
    enddate += std::chrono::days{ 7 }; // 7일 연장 고정
}

// function
bool Loan::isExpired() {
    // 오늘 날짜 구하기
    auto today = floor<days>(system_clock::now());

    return today > enddate; // 연체됐으면 true 아니면 false
}
