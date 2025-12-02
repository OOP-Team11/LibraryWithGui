#include "pch.h"
#include "mainManager.h"


// constructor 
MainManager::MainManager() 
	: members(memberfile), 
	books(bookfile), 
	loans(loanfile) 
{
	this->userId = -1; // 현재 프로그램 사용하고있는 유저 아이디. 로그인하면 여기 갱신(?) 
	this->username = ""; // 사용자 이름 
	Role userrole = Role::User; // 사용자 권한 

	/*setMembers();
	setBooks();
	setLoans();*/
}

// 기능
void MainManager::Exit() { 

	// 파일 저장
	(this->members).save(memberfile); 
	(this->books).save(bookfile); 
	(this->loans).save(loanfile); 
}
// 회원 관련
void MainManager::setMembers() { 
	
}
void MainManager::join(string name, string password) { 

}
void MainManager::login(string name, string password) { 

}	// 여기서 userId <- 반환된 id 연결시키기 
void MainManager::deleteMe() { 

}

// 도서 관련 
void MainManager::setBooks(int id) { 

}
vector<Book> MainManager::getAllBooks() { 
	return (this->books).getAllBooks();
}
vector<Book> MainManager::searchBook(string bookname, string writer, BookCategory category) { // 카테고리 있어도 되고 없어도 되고{ 
	return (this->books).searchBook(bookname, writer, category);
}

void MainManager::insertBook(string bookname, string writer, BookCategory category) { 
	(this->books).insertBook(bookname, writer, category);
}
void MainManager::deleteBook(int bookid, int yourid) { 
	(this->books).deleteBook(bookid, yourid);
}

// 대출 관련
void MainManager::setLoans() { 
	
}
void MainManager::doLoan(int bookid, string bookname, string writer, string category) { 

}