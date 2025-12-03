癤#include "pch.h"
#include "mainManager.h"


// constructor 
MainManager::MainManager() 
	: members(memberfile), 
	books(bookfile), 
	loans(loanfile) 
{
	this->userId = -1; //  濡洹몃 ъ⑺怨 � 대. 濡洹몄명硫 ш린 媛깆(?) 
	this->username = ""; // ъ⑹ 대 
	Role userrole = Role::User; // ъ⑹ 沅 

	/*setMembers();
	setBooks();
	setLoans();*/
}

// 湲곕
void MainManager::Exit() { 

	//  �
	(this->members).save(memberfile); 
	(this->books).save(bookfile); 
	(this->loans).save(loanfile); 
}

//  愿�

// 회占쏙옙 占쏙옙占쏙옙
/* username, userrole 占쏙옙占쏙옙占싹댐옙 占쏙옙占쏙옙? login占쏙옙占쏙옙 占싼뱄옙占쏙옙 占싹몌옙 占심듸옙 */

void MainManager::setMembers() { 
}
/* 회원 가입 */
bool MainManager::join(string name, string password) { 
	return members.join(name, password);
}
/* 占싸깍옙占쏙옙 */
bool MainManager::login(string name, string password) {
	const Member* currentUser = members.login(name, password);
	if (currentUser == nullptr) return false;

	(this->userId) = (currentUser->getId());
	(this->username) = (currentUser->getName());
	(this->userrole) = (currentUser->getRole());
	return true;
}	// ш린 userId <- 諛 id 곌껐ㅺ린 

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

//  愿� 
void MainManager::setBooks(int id) { 

}
vector<Book> MainManager::getAllBooks() { 
	return (this->books).getAllBooks();
}
vector<Book> MainManager::searchBook(string bookname, string writer, BookCategory category) { // 移댄怨由 대 怨 대 怨{ 
	return (this->books).searchBook(bookname, writer, category);
}

void MainManager::insertBook(string bookname, string writer, BookCategory category) { 
	(this->books).insertBook(bookname, writer, category);
}
void MainManager::deleteBook(int bookid, int yourid) { 
	(this->books).deleteBook(bookid, yourid);
}

// 異 愿�
void MainManager::setLoans() { 
	
}
void MainManager::doLoan(int bookid, string bookname, string writer, string category) { 

}