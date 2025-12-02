#include "pch.h"
#include "memberManager.h"

/*
private:
	int memberCount; // 1로 초기화. 무조건 증가만. txt 파일에서 읽을때는 '제일 큰 id' 가 Count 변수가 됨.
	vector<Member> members;
*/

/* 멤버 클래스 하나를 읽어 멤버 배열 vector<Member> members에 추가함. */
void MemberManager::addMember(const Member& member) {
	members.push_back(member);
}

/* 특정 id를 가진 멤버를 삭제함. 성공 시 true를, 실패 시 false를 반환. */
bool MemberManager::removeMember(int id) {
	vector<Member>::iterator it = findMember(id);
	// 검색 실패
	if (it==members.end()) return false;
	// 검색 성공
	else {
		members.erase(it);
		return true;
	}
}
/* default constructor. */
MemberManager::MemberManager() {
	this->memberCount = 1;
}

/* 파일 이름 받아와 멤버 정보 불러오는 생성자. memberCount 주의. 항상 다음에 추가될 멤버의 id를 가지도록. */
// MemberManager.cpp

// ----------------------------------------------
// Constructor: file에서 읽어서 초기화
// ----------------------------------------------
MemberManager::MemberManager(string filename) {

	int id=0;
	ifstream in(filename);
	if (!in.is_open()) {
		cerr << "파일을 열 수 없습니다: " << filename << endl;
		return;
	}

	string line;
	while (getline(in, line)) {
		if (line.empty()) continue;

		stringstream ss(line);
		string idStr, roleStr, name, password, scoreStr;
		// 파일 형식: id,role,name,pw,score
		getline(ss, idStr, ',');
		getline(ss, roleStr, ',');
		getline(ss, name, ',');
		getline(ss, password, ',');
		getline(ss, scoreStr, ',');

		// 텍스트 → C++ 자료형 변환
		id = stoi(idStr);
		int score = stoi(scoreStr);

		// Role 변환
		Role role;
		if (roleStr == "Admin") role = Role::Admin;
		else role = Role::User;   // 기본값: User

		// Member 생성 후 스코어 저장
		Member m(id, name, password, role);
		m.setScore(score);

		addMember(m);
	}

	memberCount = id + 1; // 멤버카운트는 마지막에 읽은 멤버 id에 +1
	in.close();
}

/* 
특정 id를 가진 멤버를 찾아 iterator 타입으로 반환함.
실패한 경우 members.end()가 반환됨.
*/
const vector<Member>::iterator MemberManager::findMember(int id) {
	vector<Member>::iterator it = members.begin();
	for (; it != members.end(); it++) {
		if ((it->getId()) == id) {
			break;
		}
	}
	return it;
}
/* 파일을 불러와 멤버변수 members에 저장. */
void MemberManager::save(string filename) {
	ofstream out(filename);
	if (!out.is_open()) {
		cerr << "파일 저장 실패: " << filename << endl;
		return;
	}

	for (auto& m : members) {
		out << m.getId() << ","
			<< (m.isAdmin() ? "Admin" : "User") << ","
			<< m.getName() << ","
			<< m.getPassword() << ","
			<< m.getScore()
			<< "\n";
	}

	out.close();
}
/* 회원가입 메소드. name과 pw 받아 member생성하고, id 받아서 push_back. 이름이 유니크해야 함. */
bool MemberManager::join(string name, string password) {
	// 먼저 이름이 유니크한지 검사, 실패 시 바로 false 리턴
	vector<Member>::iterator it = members.begin();
	for (; it != members.end(); it++) {
		if (it->getName() == name) {
			return false;
		}
	}
	// 아이디가 unique하면 회원가입 가능, 가입 및 true 리턴

	// User로 회원가입 되도록.
	Member newMember = Member(this->memberCount, name, password);
	members.push_back(newMember);
	(this->memberCount)++;
	return true;
	
}
/* 로그인 기능. 이름과 패스워드가 일치하는 멤버가 있다면 멤버 객체를 반환. 로그인 실패 시 nullptr 리턴.*/
const Member* MemberManager::login(string name, string password) {
	vector<Member>::iterator it = members.begin();
	for (; it != members.end(); it++) {
		if ((it->getName() == name) && (it->getPassword() == password)) {
			break;
		}
	}
	// 로그인 실패
	if (it == members.end()) return nullptr;
	// 로그인 성공
	else {
		return &(*it);
	}
}
/* 모든 멤버 목록 리턴 */
const vector<Member>& MemberManager::getAllMembers() const {
	return members;
}

/* 회원 탈퇴 기능. 어딘가에서 getCurrentUser() 같은 걸로 현재 로그인한 사용자 정보 받아와야 함. */
bool MemberManager::deleteMember(int id) {
	return removeMember(id);
}