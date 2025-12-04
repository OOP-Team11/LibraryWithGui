#pragma once
#include "book.h"
#include <string>
#include <vector>
using namespace std;

class BookManager {
private:
	int bookCount; // 0으로 초기화 0,1,2,4
	vector<Book> books;
	string lastLoadedFilename; // 저장할 파일명

	// 실제 내부 작동 functions
	void addBook(const Book& book); // txt 파일에서 읽어서 추가 or 책 등록 시
	bool removeBook(int id); // 삭제 성공하면 true

public:
	// constructor
	BookManager(); // memberCount = 0 으로 초기화 해야함.
	BookManager(string filename); // txt 파일 불러읽기용
	~BookManager(); // Deallocation (소멸자): 객체 소멸 시 파일 저장

	// 내부 기능 functions
	vector<Book>::iterator findBook(int id);
	void save(string filename); 

	// 외부 기능 functions
	void insertBook(string name, string writer, BookCategory category); // 도서 등록 : bookCount 통해 Book() 생성 -> addBook 으로 DB에 추가
	vector<Book> getAllBooks() const; // 도서 조회(전체)
	vector<Book> searchBook(string name, string writer, BookCategory bookcategory) const; // 도서 검색 (책 이름, 작가 이름), findBook 이용하기
	void deleteBook(int bookId, int yourId); // 도서 삭제 + yourId는 명령 실행하는 사용자 권한 체크용
	void changeBookState(int bookId);

	bool checkBookState(int bookId);

};