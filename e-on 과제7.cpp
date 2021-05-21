#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <iostream>

#define Row 7
#define Col 5
using namespace std;

enum MainMenu { Book_Add = 1, Book_Serch, Book_imfoChan, Book_delete, Book_List, File_Save, Exit };

class Book
{
	char Name[50]; // 도서명
	char Author[50]; // 저자 
	char Year[50]; // 출판연도
	char Publisher[50]; // 출판사명
	char Genre[50]; // 장르 
public:
	Book(const char _Name[], const char _Author[], const char _Year[], const char _Publisher[], const char _Genre[])
	{
		strcpy_s(Name, _Name);
		strcpy_s(Author, _Author);
		strcpy_s(Year, _Year);
		strcpy_s(Publisher, _Publisher);
		strcpy_s(Genre, _Genre);
	}
	Book() {};
	~Book() {};
	char* getName();
	char* getAuthor();
	char* getYear();
	char* getGenre();
	char* getPublisher();

};
char* Book::getName()
{
	return Name;
};
char* Book::getAuthor()
{
	return Author;
};
char* Book::getYear()
{
	return Year;
}
char* Book::getGenre()
{
	return Genre;
};
char* Book::getPublisher()
{
	return Publisher;
};


class Menu
{
private:
	Book* BookNum[Row][Col];
public:
	void ShowMenu() // 메인 메뉴 출력
	{
		cout << "---------------------- \n";
		cout << "1. 도서 추가\n";
		cout << "2. 도서 검색\n";
		cout << "3. 도서 정보 수정\n";
		cout << "4. 도서 삭제\n";
		cout << "5. 현재 총 도서 목록 출력\n";
		cout << "6. 저장\n";
		cout << "7. 프로그램 나가기\n";
		cout << "---------------------- \n";
	}
	void Show_BookAdd()  //도서 추가 메뉴 출력
	{
		cout << "---------------------- \n";
		cout << "1. 도서명\n";
		cout << "2. 저자\n";
		cout << "3. 출판연도\n";
		cout << "4. 출판사명\n";
		cout << "5. 장르\n";
		cout << "---------------------- \n";
	}
	void Show_BookSerch()  //도서 찾기 메뉴 출력 
	{
		cout << "---------------------- \n";
		cout << "1. 도서명\n";
		cout << "2. 저자\n";
		cout << "3. 출판연도\n";
		cout << "4. 출판사명\n";
		cout << "5. 장르\n";
		cout << "---------------------- \n";
	}
	int inputMenu() //메뉴 입력 
	{
		int menuNum = -1;
		cout << "메뉴입력:";
		cin >> menuNum;
		return menuNum;
	}
	void BookSerch() 	// 도서 검색
	{
		bool isEmpty = true;

		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				if (BookNum[i][j] != NULL) {
					isEmpty = false;
					goto exit;
				}
			}
		}
	exit:
		if (isEmpty)
		{
			cout << "찾고자 하는 책이 없습니다. \n";
		}
		else
		{
			char Name[50];
			cout << "검색할 책 제목 입력 :";
			cin >> Name;

			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (BookNum[i][j] != NULL)
					{
						if (strcmp(BookNum[i][j]->getName(), Name) == 0)
						{
							cout << "---------------책 정보---------------\n";
							cout << "도서명 : " << BookNum[i][j]->getName() << "\n";
							cout << "저자 : " << BookNum[i][j]->getAuthor() << "\n";
							cout << "출판 연도" << BookNum[i][j]->getYear() << "\n";
							cout << "출판사명" << BookNum[i][j]->getPublisher() << "\n";
							cout << "장르 : " << BookNum[i][j]->getGenre() << "\n";
							cout << "======================================================\n";
						}
					}
				}
			}
		}
	}
	void BookList() // 도서 목록 출력
	{
		cout << "도서명" << "__" << "저자" << "__" << "출판 연도" << "__" << "출판사명" << "__" << "장르 \n";
		cout << "======================================================\n";

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (BookNum[i][j] != NULL)
				{
					cout << BookNum[i][j]->getName() << "__" << BookNum[i][j]->getAuthor() << "__" << BookNum[i][j]->getYear() << "__" << BookNum[i][j]->getPublisher() << "__" << BookNum[i][j]->getGenre() << i << "행" << j << "열\n";
				}
			}
		}
		cout << "======================================================\n";
	}
	void BookAdd() // 도서 추가 
	{
		char Name[50];
		char Author[50];
		char Year[50];
		char Publisher[50];
		char Genre[50];

		cout << "------------------------도서 추가------------------------\n";
		cout << "도서명 :";
		cin >> Name;
		cout << "저자 : ";
		cin >> Author;
		cout << "출판연도 :";
		cin >> Year;
		cout << "출판사명 :";
		cin >> Publisher;
		cout << "장르 :";
		cin >> Genre;

		Book book = Book(Name, Author, Year, Publisher, Genre);

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (BookNum[i][j] == NULL)
				{
					BookNum[i][j] = new Book();
					*BookNum[i][j] = book;
					goto exit;
				}
			}
		}
	exit: NULL;

		SaveFile();
	}
	void SaveFile() //파일 저장
	{
		ofstream outFile("BookNum.txt", ios_base::out);

		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				if (BookNum[i][j] == NULL) {
					outFile << "[         " << "]";
				}
				else {
					outFile << "[" << BookNum[i][j]->getName() << "__" << BookNum[i][j]->getAuthor() << "__" << BookNum[i][j]->getYear() << "__" << BookNum[i][j]->getPublisher() << "__" << BookNum[i][j]->getGenre() << "]";
				}
			}
			outFile << "\n";
		}
	}
	void BookDelete() //도서 삭제
	{
		char bookname[50];
		cout << "삭제할 도서명 입력 : ";
		cin >> bookname;
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				if (BookNum[i][j] != NULL) {
					if (BookNum[i][j]->getName() == bookname)
					{
						BookNum[i][j] = NULL;
						goto exit;
					}
				}
			}
		}
	exit: NULL;
		SaveFile();
	}

	void Bookimfochange()
	{

	}

	void _exit() //프로그램 종료
	{
		exit(0);
	}
	void MainMenu() // 메인메뉴
	{
		ShowMenu(); // 메인 메뉴 출력
		while (true)
		{
			int menuNum = inputMenu();

			switch (menuNum)
			{
			case Book_Add:
				BookAdd();
				break;
			case Book_Serch:
				BookSerch();
				break;
			case Book_imfoChan:
				Bookimfochange();
				break;
			case Book_delete:
				BookDelete();
				break;
			case Book_List:
				BookList();
				break;
			case File_Save:
				SaveFile();
				break;
			case Exit:
				_exit();
				break;
			default:
				break;
			}
		}
	}
	Menu() {}
};
int main()
{
	Menu manage = Menu();
	manage.MainMenu();
}

//참고 링크 
//https://hjjungdev.tistory.com/140
//https://hjjungdev.tistory.com/145
