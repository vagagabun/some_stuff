#include <iostream>
#include <fstream>
#include "DB.h"
#include "Hash.h"
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

// DB

void db_menu(DB* db)
{
	int choice = 0;
	do
	{
	cout << "1. registration\n"
		 << "2. authentication\n"
		 << "3. forgot password\n"
		 << "4. save to file\n"
		 << "5. exit\n";
	cout << "Enter your choice: ";
	cin >> choice;
		switch(choice)
		{
			case 1:
				db->reg();
				break;
			case 2:
				db->enter();
				break;
			case 3:
				db->recover();
				break;
			case 4:
				{
				string filename;
				cout << "Enter a file name: ";
				cin >> filename;
				db->save_file(filename);
				}
				break;
			default:
				break;
		}
	} while (choice >= 1 && choice <= 4);
	cout << "Exiting...\n";
}

int main()
{
	//DB db;
	//ControlQuestion c("q","a");
	//Hash h("login","password",c);
	//db.push(h);
	//Hash hh("log","pas",c);
	//db.push(hh);
	//db.show_DB();
	//db.reg();
	//db.show_DB();
	////db.enter();
	////db.recover();
	//db.show_DB();
	//db.save_file("db.txt");
	/*DB newDB("db.txt");
	newDB.show_DB();*/
	cout << "create new db or load from file? 1 or 2? ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		auto* db = new DB();
		db_menu(db);
		delete db;
	}
	else if (choice == 2)
	{
		string filename;
		cout << "enter a name of file: ";
		cin >> filename;
		auto* db = new DB(filename);
		db_menu(db);
		delete db;
	}
	else
	{
		cout << "Error.\n";
	}
	system("pause");
	return 0;
}
