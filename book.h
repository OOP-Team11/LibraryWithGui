#pragma once
#include "bookCategory.h"
#include <string>
using namespace std;

class Book {
private:
	int id;
	string name;
	string writer;
	BookCategory category;
	bool isLoan;

public:
	// constructor
	Book();
	Book(int id, string name, string writer, BookCategory category); // isLoan은 false로 초기화.
	Book(int id, string name, string writer); // 카테고리 지정 귀찮을때 그냥 다 000으로 되도록 하나 만들기

	// getter
	int getId() const;
	string getName() const;
	string getWriter() const;
	BookCategory getCategory() const;
	bool getIsLoan() const;

	// setter
	void setName(string name);
	void setWriter(string writer);
	void setCategory(BookCategory category);
	void setIsLoan(); // 실행 될때 true면 false, false면 true 로 switch 기능 하도록.

	// functions
	bool checkLoan() const; // 위에 getIsLoan이랑 겹치긴 하는데 혹시 몰라서 일단 적어둠.
};