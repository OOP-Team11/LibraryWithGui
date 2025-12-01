#include "pch.h"
#include "book.h"
#include <string>

using namespace std;

Book::Book() {
    this->id = 0;
    this->name = "";
    this->writer = "";
    this->isLoan = false;
    this->category = BookCategory::General;
}

Book::Book(int id, string name, string writer, BookCategory category) {
    this->id = id;
    this->name = name;
    this->writer = writer;
    this->category = category;
    this->isLoan = false; // 기본 대출 가능 상태
}

Book::Book(int id, string name, string writer) {
    this->id = id;
    this->name = name;
    this->writer = writer;
    this->isLoan = false;
    this->category = BookCategory::General;
}

// getter
int Book::getId() const { 
    return this->id; 
}
string Book::getName() const { 
    return this->name; 
}
string Book::getWriter() const { 
    return this->writer; 
}
BookCategory Book::getCategory() const { 
    return this->category; 
}
bool Book::getIsLoan() const { 
    return this->isLoan; 
}

// setter
void Book::setName(string name) { 
    this->name = name; 
}
void Book::setWriter(string writer) { 
    this->writer = writer; 
}
void Book::setCategory(BookCategory category) { 
    this->category = category; 
}
void Book::setIsLoan() { 
    this->isLoan = !this->isLoan; 
}

// functions
bool Book::checkLoan() const { 
    return this->isLoan; 
}