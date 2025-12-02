#pragma once
#include "memberManager.h"
#include "bookManager.h"
#include "loanManager.h"
#include "role.h"
#include "bookCategory.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class MainManager {
private:
	string memberfile = "members.txt";
	string bookfile = "books.txt";
	string loanfile = "loans.txt";
	MemberManager members;
	BookManager books;
	LoanManager loans;
	int userId; // 현재 프로그램 사용하고있는 유저 아이디. 로그인하면 여기 갱신(?)
	string username; // 사용자 이름
	Role userrole; // 사용자 권한

public:
	// constructor
	MainManager();

	// 기능
	void Exit(); // 창 끄기전에 파일 저장 및 종료
	// 회원 관련
	void setMembers();
	void join(string name, string password);
	bool login(string name, string password); // 여기서 userId <- 반환된 id 연결시키기
	bool deleteMe();
	int getUserId();
	string getUserName();
	Role getUserRole();

	// 도서 관련
	void setBooks();
	void getAllBooks();
	void searchBook(string bookname, string writer, string category); // 카테고리 있어도 되고 없어도 되고

	void insertBook(string bookname, string writer, string category);
	void deleteBook();

	// 대출 관련
	void setLoans();
	void doLoan(int bookid, string bookname, string writer, string category);
};
