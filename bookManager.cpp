#include "pch.h"
#include "bookManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype> 

using namespace std;


// 기본 생성자
BookManager::BookManager() {
    this->bookCount = 0;
}

// 문자열에서 숫자만 남기고 다 지워버리는 함수
string CleanString(string input) {
    string output = "";
    for (char c : input) {
        if (isdigit((unsigned char)c)) {
            output += c;
        }
    }
    return output;
}

// 파일 불러오기 생성자
BookManager::BookManager(string filename) {
    this->bookCount = 0;
    this->lastLoadedFilename = filename;

    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        int lineNum = 0;

        while (getline(inFile, line)) {
            lineNum++;
            if (line.empty()) continue; // 빈 줄 건너뜀

            stringstream ss(line);
            string segment;
            vector<string> row;

            // 콤마 파싱
            while (getline(ss, segment, ',')) {
                row.push_back(segment);
            }

            // 데이터가 5개 이상인지 확인
            if (row.size() >= 5) {
                try {
                    // ID 부분 clean (숫자가 아닌 다른 문자 제거)
                    string rawId = row[0];
                    string cleanId = CleanString(rawId);

                    if (cleanId.empty()) {
                        continue;
                    }

                    // id 변환
                    int id = stoi(cleanId);

                    // 나머지 데이터 처리
                    string name = row[1];
                    string writer = row[2];

                    // 카테고리
                    string rawCat = row[3];
                    string cleanCat = CleanString(rawCat);
                    int catInt = cleanCat.empty() ? 0 : stoi(cleanCat);

                    // 대출여부
                    string rawLoan = row[4];
                    string cleanLoan = CleanString(rawLoan);
                    bool loan = cleanLoan.empty() ? false : (stoi(cleanLoan) != 0);

                    // 객체 생성
                    Book b(id, name, writer, (BookCategory)catInt);
                    if (loan) b.setIsLoan();

                    books.push_back(b);

                    if (id >= this->bookCount) { //최대 ID 값으로 bookCount 값 채우기
                        this->bookCount = id + 1;
                    }
                }
                catch (const exception& e) {
                    cout << lineNum << "번째 줄 처리 중 에러: " << e.what() << endl;
                }
            }
        }
        inFile.close();
    }
    else {
        cout << filename << "' 파일이 없습니다. 새 데이터를 생성합니다." << endl;
    }
}

// 소멸자
BookManager::~BookManager() {
    if (lastLoadedFilename.empty()) return;

    ofstream outFile(this->lastLoadedFilename);
    if (outFile.is_open()) {
        for (const auto& book : books) {
            outFile << book.getId() << ","
                << book.getName() << ","
                << book.getWriter() << ","
                << (int)book.getCategory() << ","
                << (book.getIsLoan() ? 1 : 0) << endl;
        }
        outFile.close();
        cout << "자동 저장 완료." << endl;
    }
}

void BookManager::addBook(const Book& book) {
    books.push_back(book);
}

vector<Book>::iterator BookManager::findBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            return it;
        }
    }
    return books.end();
}

bool BookManager::removeBook(int id) {
    auto it = findBook(id);
    if (it != books.end()) {
        books.erase(it);
        return true;
    }
    return false;
}

void BookManager::save(string filename) {
    this->lastLoadedFilename = filename;
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& book : books) {
            outFile << book.getId() << ","
                << book.getName() << ","
                << book.getWriter() << ","
                << (int)book.getCategory() << ","
                << (book.getIsLoan() ? 1 : 0) << endl;
        }
        outFile.close();
    }
}

void BookManager::insertBook(string name, string writer, BookCategory category) {
    int newId = this->bookCount; //bookCount로 ID 생성
    // 기본 카테고리 General(0)으로 생성
    Book newBook(newId, name, writer, BookCategory::General);
    addBook(newBook);
    this->bookCount++;
    cout << "도서 등록 완료: " << name << " (ID: " << newId << ")" << endl;
}

vector<Book> BookManager::getAllBooks() const {
    return this->books;
}

vector<Book> BookManager::searchBook(string name, string writer, BookCategory category) const {
    vector<Book> result;

    for (const auto& book : books) {
        // 1. 카테고리 확인
        // "전체(All)"이거나, 아니면 "카테고리가 정확히 일치"하는 경우 통과
        bool catMatch = (category == BookCategory::All) || (book.getCategory() == category);

        // 2. 이름 검색
        bool nameMatch = (name != "" && book.getName().find(name) != string::npos);

        // 3. 작가 검색
        bool writerMatch = (writer != "" && book.getWriter().find(writer) != string::npos);

        // [최종 판단]
        if (name == "" && writer == "") {
            // 이름/작가 입력 없이 카테고리만 검색하는 경우 (단, All이면 전체 출력이 되므로 주의)
            // 보통 전체 출력을 막고 싶으면 여기서 && category != BookCategory::All 조건을 걸기도 함
            if (catMatch) result.push_back(book);
        }
        else {
            if (catMatch && (nameMatch || writerMatch)) {
                result.push_back(book);
            }
        }
    }
    return result;
}

void BookManager::deleteBook(int bookId, int yourId) {

    // removeBook 실패 = 해당 ID 없음
    if (!removeBook(bookId)) {
        throw runtime_error("해당 ID의 도서를 찾을 수 없습니다.");
    }

    cout << "도서(ID: " << bookId << ")가 삭제되었습니다." << endl;
}
