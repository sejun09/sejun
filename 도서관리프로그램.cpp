#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

enum  MainMenu{Book_Add =1, Book_Serch, Book_infochan, Book_Delete, Book_List, Exit};

class library
{
public:
	void ShowMenu() //메인 메뉴 출력
	{
		cout << "------------MainMenu---------- \n";
		cout << "1. 도서 추가\n";
		cout << "2. 도서 검색\n";
		cout << "3. 도서 정보 수정\n";
		cout << "4. 도서 삭제\n";
		cout << "5. 현재 총 도서 목록 출력\n";
		cout << "6. 프로그램 나가기\n";
		cout << "------------------------------ \n";
	}
	int inputMenu() //메뉴 입력
	{
		int MenuNum = -1;
		cout << "메뉴 입력 : ";
		cin >> MenuNum;
		return MenuNum;
	}
	void BookAdd() // 도서 추가 
	{
		{
			string New_book;
			fstream library;
			int x = 0;
			library.open("input.txt", ios::app);
			do
			{
				cout << "1. 제목 2.작가 3.출판연도 4.출판사 5.장르 순으로 입력해주세요"<< endl;
				cout << "ex) 백년아이 김지연 2019 다림 소설" << endl;
				cout << "추가할 도서 : ";
				cin.ignore();   // getline 함수가 문자열을 입력받지 않고 넘어가는 것을 막기 위한 cin.ignore함수 
				getline(cin, New_book);
				cout << " 입력한 도서를 추가하시겠습니까? Y=1 N=0 " << endl;
				cout << ">>>>>>>>" << New_book << "<<<<<<<<" << endl;
				cin >> x;
			} while (x == 0);
			library << New_book << endl;
			library.close();
		}
	}
	void FileRead(ifstream& fin, vector<string>& v)   //input.txt파일의 텍스트를 읽는 함수
	{
		string line;
		while (getline(fin, line))
		{
			v.push_back(line);
		}
	}
	void FileSerch(vector<string>& v, string& word) //input.txt파일에서 원하는 문자를 찾는, 출력하는 함수 
	{
		for (int i = 0; i < v.size(); i++)
		{
			int index = v[i].find(word);
			if (index != -1)
			{
				cout << "line" << setw(3) << i + 1 << " : " << v[i] << endl;
			}
		}
	}
	void BookSerch()  //도서 검색 
	{
		vector<string> v;
		ifstream fin("input.txt");
		if (!fin)
		{
			cout << "에러 입력파일" ;
		}
		FileRead(fin, v);
		string word;
		cout << "찾고 싶은 도서의 제목, 저자, 출판연도, 출판사명, 장르 중 원하는 것을 입력하세요 :";
		cin >> word;
		FileSerch(v, word);
	}
	void BookInfochan()  //도서 정보 수정
	{
		vector<string> v;
		ifstream fin("input.txt");
		if (!fin) {
			cout << "에러 입력파일";
		}
		FileRead(fin, v);
		bookdel(v);
		BookAdd();
	}
	void bookdel(vector<string>& v)  // 도서 삭제 함수
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << i + 1 << ". " << v[i] << endl;
		}	
		int lineNum;
		int x = 0;
		do
		{
			cout << endl << "삭제할 도서의 줄 숫자를 입력하세요 : ";
			cin >> lineNum;
			cout << "삭제하려는 도서가" << lineNum << ". " << v[lineNum - 1] << "이 맞습니까?" << endl;
			cout << "Y=1, N=0 : ";
			cin >> x;
		} while (x == 0);
	
		
		v.erase(v.begin() + (lineNum - 1));
		ofstream deldata("input.txt");
		for (int i = 0; i < v.size(); i++)
		{
			deldata << v[i] << endl;
		}
		deldata.close();
	}
	void BookDelete()  // 도서 삭제 함수
	{
		vector<string> v;
		ifstream fin("input.txt");
		if (!fin) {
			cout << "에러 입력파일";
		}
		FileRead(fin, v);
		bookdel(v);
	}
	void BookList() // 현재 총 도서 목록 출력하는 함수 
	{
		vector<string> v;
		ifstream fin("input.txt");
		FileRead(fin, v);
		cout << "------------현재 총 도서 목록--------------" << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << i + 1 << ". " << v[i] << endl;
		}
		cout << "-------------------------------------------" << endl;
	}
	void _Exit()
	{
		exit(0);
	}
	void Menu()
	{
		
		while (true)
		{
			 ShowMenu();
			int MenuNum = inputMenu();

			switch (MenuNum)
			{
			case Book_Add:
				BookAdd();
				break;
			case Book_Serch:
				BookSerch();
				break;
			case Book_infochan:
				BookInfochan();
				break;
			case Book_Delete:
				BookDelete();
				break;
			case Book_List:
				BookList();
				break;
			case Exit:
				_Exit();
				break;
			default:
				break;
			}
		}
	}
};
int main()
{
	library Manage = library();
	Manage.Menu();
}

