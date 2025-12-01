#include "pch.h"
#include "member.h"
#include "role.h"

/*
멤버 프라이빗 멤버 변수
	int id;
	Role role;
	string name;
	string password; // unique 해야함. 회원가입할 때 unique 처리
	int score; // 반납 기한 연체시 점수 깎는 기능 대비
*/

// contructor
Member::Member(){
	id = 0;
	role = Role::User;
	name = "";
	password = "";
	score = 0;
}
/* role 선택 회원가입 기능 */
Member::Member(int id, const string& name, const string& password, Role role){
	this->id = id;
	this->name = name;
	this->password = password;
	this->role = role;
	this->score = 0;
}
/* 기본 회원가입 기능: role은 user로*/
Member::Member(int id, const string& name, const string& password){
	this->id = id;
	this->name = name;
	this->password = password;
	this->score = 0;
	this->role = Role::User;
}

// getter
int Member::getId() const{
	return this->id;
}
string Member::getName() const{
	return this->name;
}
string Member::getPassword() const{
	return this->password;
}
Role Member::getRole() const{
	return this->role;
}
int Member::getScore() const{
	return this->score;
}

// setter - 일단 만들어두고 이후에 필요하다면.
void Member::setName(const string& name){
	this->name = name;
}
void Member::setRole(Role role){
	this->role = role;
}
void Member::setScore(int score){
	this->score = score;
}

// function
bool Member::canLoan() const{
	if (score >= 0) return true;
	else return false;
}
bool Member::isUser() const{
	if (this->role == Role::User) return true;
	else return false;
}
bool Member::isAdmin() const{
	if (this->role == Role::Admin) return true;
	else return false;
}
