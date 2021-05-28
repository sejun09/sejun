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
	void ShowMenu() //���� �޴� ���
	{
		cout << "------------MainMenu---------- \n";
		cout << "1. ���� �߰�\n";
		cout << "2. ���� �˻�\n";
		cout << "3. ���� ���� ����\n";
		cout << "4. ���� ����\n";
		cout << "5. ���� �� ���� ��� ���\n";
		cout << "6. ���α׷� ������\n";
		cout << "------------------------------ \n";
	}
	int inputMenu() //�޴� �Է�
	{
		int MenuNum = -1;
		cout << "�޴� �Է� : ";
		cin >> MenuNum;
		return MenuNum;
	}
	void BookAdd() // ���� �߰� 
	{
		{
			string New_book;
			fstream library;
			int x = 0;
			library.open("input.txt", ios::app);
			do
			{
				cout << "1. ���� 2.�۰� 3.���ǿ��� 4.���ǻ� 5.�帣 ������ �Է����ּ���"<< endl;
				cout << "ex) ������ ������ 2019 �ٸ� �Ҽ�" << endl;
				cout << "�߰��� ���� : ";
				cin.ignore();   // getline �Լ��� ���ڿ��� �Է¹��� �ʰ� �Ѿ�� ���� ���� ���� cin.ignore�Լ� 
				getline(cin, New_book);
				cout << " �Է��� ������ �߰��Ͻðڽ��ϱ�? Y=1 N=0 " << endl;
				cout << ">>>>>>>>" << New_book << "<<<<<<<<" << endl;
				cin >> x;
			} while (x == 0);
			library << New_book << endl;
			library.close();
		}
	}
	void FileRead(ifstream& fin, vector<string>& v)   //input.txt������ �ؽ�Ʈ�� �д� �Լ�
	{
		string line;
		while (getline(fin, line))
		{
			v.push_back(line);
		}
	}
	void FileSerch(vector<string>& v, string& word) //input.txt���Ͽ��� ���ϴ� ���ڸ� ã��, ����ϴ� �Լ� 
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
	void BookSerch()  //���� �˻� 
	{
		vector<string> v;
		ifstream fin("input.txt");
		if (!fin)
		{
			cout << "���� �Է�����" ;
		}
		FileRead(fin, v);
		string word;
		cout << "ã�� ���� ������ ����, ����, ���ǿ���, ���ǻ��, �帣 �� ���ϴ� ���� �Է��ϼ��� :";
		cin >> word;
		FileSerch(v, word);
	}
	void BookInfochan()  //���� ���� ����
	{
		vector<string> v;
		ifstream fin("input.txt");
		if (!fin) {
			cout << "���� �Է�����";
		}
		FileRead(fin, v);
		bookdel(v);
		BookAdd();
	}
	void bookdel(vector<string>& v)  // ���� ���� �Լ�
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << i + 1 << ". " << v[i] << endl;
		}	
		int lineNum;
		int x = 0;
		do
		{
			cout << endl << "������ ������ �� ���ڸ� �Է��ϼ��� : ";
			cin >> lineNum;
			cout << "�����Ϸ��� ������" << lineNum << ". " << v[lineNum - 1] << "�� �½��ϱ�?" << endl;
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
	void BookDelete()  // ���� ���� �Լ�
	{
		vector<string> v;
		ifstream fin("input.txt");
		if (!fin) {
			cout << "���� �Է�����";
		}
		FileRead(fin, v);
		bookdel(v);
	}
	void BookList() // ���� �� ���� ��� ����ϴ� �Լ� 
	{
		vector<string> v;
		ifstream fin("input.txt");
		FileRead(fin, v);
		cout << "------------���� �� ���� ���--------------" << endl;
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

