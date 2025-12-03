癤#pragma once
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
	int userId; //  濡洹몃 ъ⑺怨 � 대. 濡洹몄명硫 ш린 媛깆(?)
	string username; // ъ⑹ 대
	Role userrole; // ъ⑹ 沅

public:
	// constructor
	MainManager();

	// 湲곕
	void Exit(); // 李 湲곗  � 諛 醫猷
	//  愿�
	void setMembers();
	bool join(string name, string password);
	bool login(string name, string password); // 여기서 userId <- 반환된 id 연결시키기
	bool deleteMe();
	int getUserId();
	string getUserName();
	Role getUserRole();

	//  愿�
	void setBooks(int id);
	vector<Book> getAllBooks();
	vector<Book> searchBook(string bookname, string writer, BookCategory category); // 移댄怨由 대 怨 대 怨

	void insertBook(string bookname, string writer, BookCategory category);
	void deleteBook(int bookid, int yourid);

	// 異 愿�
	void setLoans();
	void doLoan(int bookid, string bookname, string writer, string category);
};
