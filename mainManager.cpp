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
/* username, userrole 설정하는 역할? login에서 한번에 하면 될듯 */

void MainManager::setMembers() { 
}
/* 회원 가입 */
bool MainManager::join(string name, string password) { 
	return members.join(name, password);
}
/* 로그인 */
bool MainManager::login(string name, string password) {
	const Member* currentUser = members.login(name, password);
	if (currentUser == nullptr) return false;

	(this->userId) = (currentUser->getId());
	(this->username) = (currentUser->getName());
	(this->userrole) = (currentUser->getRole());
	return true;
}	// 여기서 userId <- 반환된 id 연결시키기

/* 탈퇴 */
bool MainManager::deleteMe() { 
	return members.deleteMember(this->userId);
}
/* getters */

int MainManager::getUserId() {
	return this->userId;
}
string MainManager::getUserName() {
	return this->username;
}
Role MainManager::getUserRole() {
	return this->userrole;
}

// 도서 관련
void MainManager::setBooks(int id) { 

}
vector<Book> MainManager::getAllBooks() { 
	return (this->books).getAllBooks();
}
vector<Book> MainManager::searchBook(string bookname, string writer, BookCategory category) { // 
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