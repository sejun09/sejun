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
	char Name[50]; // ������
	char Author[50]; // ���� 
	char Year[50]; // ���ǿ���
	char Publisher[50]; // ���ǻ��
	char Genre[50]; // �帣 
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
	void ShowMenu() // ���� �޴� ���
	{
		cout << "---------------------- \n";
		cout << "1. ���� �߰�\n";
		cout << "2. ���� �˻�\n";
		cout << "3. ���� ���� ����\n";
		cout << "4. ���� ����\n";
		cout << "5. ���� �� ���� ��� ���\n";
		cout << "6. ����\n";
		cout << "7. ���α׷� ������\n";
		cout << "---------------------- \n";
	}
	void Show_BookAdd()  //���� �߰� �޴� ���
	{
		cout << "---------------------- \n";
		cout << "1. ������\n";
		cout << "2. ����\n";
		cout << "3. ���ǿ���\n";
		cout << "4. ���ǻ��\n";
		cout << "5. �帣\n";
		cout << "---------------------- \n";
	}
	void Show_BookSerch()  //���� ã�� �޴� ��� 
	{
		cout << "---------------------- \n";
		cout << "1. ������\n";
		cout << "2. ����\n";
		cout << "3. ���ǿ���\n";
		cout << "4. ���ǻ��\n";
		cout << "5. �帣\n";
		cout << "---------------------- \n";
	}
	int inputMenu() //�޴� �Է� 
	{
		int menuNum = -1;
		cout << "�޴��Է�:";
		cin >> menuNum;
		return menuNum;
	}
	void BookSerch() 	// ���� �˻�
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
			cout << "ã���� �ϴ� å�� �����ϴ�. \n";
		}
		else
		{
			char Name[50];
			cout << "�˻��� å ���� �Է� :";
			cin >> Name;

			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (BookNum[i][j] != NULL)
					{
						if (strcmp(BookNum[i][j]->getName(), Name) == 0)
						{
							cout << "---------------å ����---------------\n";
							cout << "������ : " << BookNum[i][j]->getName() << "\n";
							cout << "���� : " << BookNum[i][j]->getAuthor() << "\n";
							cout << "���� ����" << BookNum[i][j]->getYear() << "\n";
							cout << "���ǻ��" << BookNum[i][j]->getPublisher() << "\n";
							cout << "�帣 : " << BookNum[i][j]->getGenre() << "\n";
							cout << "======================================================\n";
						}
					}
				}
			}
		}
	}
	void BookList() // ���� ��� ���
	{
		cout << "������" << "__" << "����" << "__" << "���� ����" << "__" << "���ǻ��" << "__" << "�帣 \n";
		cout << "======================================================\n";

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (BookNum[i][j] != NULL)
				{
					cout << BookNum[i][j]->getName() << "__" << BookNum[i][j]->getAuthor() << "__" << BookNum[i][j]->getYear() << "__" << BookNum[i][j]->getPublisher() << "__" << BookNum[i][j]->getGenre() << i << "��" << j << "��\n";
				}
			}
		}
		cout << "======================================================\n";
	}
	void BookAdd() // ���� �߰� 
	{
		char Name[50];
		char Author[50];
		char Year[50];
		char Publisher[50];
		char Genre[50];

		cout << "------------------------���� �߰�------------------------\n";
		cout << "������ :";
		cin >> Name;
		cout << "���� : ";
		cin >> Author;
		cout << "���ǿ��� :";
		cin >> Year;
		cout << "���ǻ�� :";
		cin >> Publisher;
		cout << "�帣 :";
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
	void SaveFile() //���� ����
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
	void BookDelete() //���� ����
	{
		char bookname[50];
		cout << "������ ������ �Է� : ";
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

	void _exit() //���α׷� ����
	{
		exit(0);
	}
	void MainMenu() // ���θ޴�
	{
		ShowMenu(); // ���� �޴� ���
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

//���� ��ũ 
//https://hjjungdev.tistory.com/140
//https://hjjungdev.tistory.com/145
