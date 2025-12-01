#pragma once
#include "member.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct MemberRow {
	int id;
	Role role;
	string name;
	string password;
	int score;
};

class MemberManager {
private:
	int memberCount; // 1로 초기화. 무조건 증가만. txt 파일에서 읽을때는 '제일 큰 id' 가 Count 변수가 됨.
	vector<Member> members;

	// 실제 내부 작동 functions
	void addMember(const Member& member); // txt 파일에서 읽어서 추가 or 회원가입 시
	bool removeMember(int id); // 삭제 성공했으면 true


public:
	// constructor
	MemberManager(); // memberCount = 0 으로 초기화 해야함.
	MemberManager(string filename);

	// 내부 기능 functions
	const vector<Member>:: iterator findMember(int id); // 포인터 반환 -> 없으면 nullptr
	void save(string filename);

	// 외부 기능 functions
	bool join(string name, string password); // 회원 가입. join에서 Member()생성자 이용해서 생성하고(memberManager에 memberCount 이용해서 id 하면 됨) -> 위의 addMember로 추가하기.
	const Member* login(string name, string password); // 로그인 -> memberId 반환
	const vector<Member>& getAllMembers() const; // 모든 회원 조회 -> 근데 필요할까 싶긴함
	bool deleteMember(int id); // 회원 탈퇴

};