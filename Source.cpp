#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

#include "Application.h"
#include "Freight.h"
#include "Route.h"

#include "UsersDB.h"
#include "ApplicationsDB.h"

using namespace std;

int main() {
	////ENTER -> WORK -> EXIT
	//UAuthorized unAuthUser;
	//int user_choice = 0;
	//while (user_choice != 4)
	//{
	//	cout << "Transport Company Information System" << endl;
	//	cout << "MAIN MENU" << endl;
	//	cout << "1. AUTHERIZATION" << endl;
	//	cout << "2. REGISTRATION" << endl;
	//	cout << "3. Create Cargo" << endl;
	//	cout << "4. EXIT" << endl;
	//	cin >> user_choice;
	//	switch (user_choice)
	//	{
	//	case 1:
	//		unAuthUser.authorization(); break;
	//	case 2:
	//		unAuthUser.registration(); break;
	//	case 3:
	//		unAuthUser.createCargo(); break;
	//	case 4:
	//		std::cout << "(4)" << std::endl; break;
	//	default:
	//		unAuthUser.getAll();
	//	}
	//}
	// 
	//Application* ap = new Application("123456");
	//ap->show();
	ApplicationsDB* tt = new ApplicationsDB("db/_applications/", "aconfig.dat", "db/backups/_applications/");
	//tt->create("userID");
	tt->read();
	delete tt;
	//Route tr;
	//tr.show();
	//UsersDB *lst = new UsersDB("db/_users/", "uconfig.dat", "db/backups/_users/");
	//lst->create("usr999", "qwerty", "12345", "654321", 2);
	//lst->resize();
	//lst->remove("u234");
	//lst->read();
	//lst->backup();
	//delete lst;


	return 0;
}

// ИСПРАВИИИИИИИИТЬ\СДЕЛАААААТЬ
// 1. Почему хеш не обновляется
// 2. А может сделать 1 класс шаблоном для БД?
// 3. Поменять названия для БД?
// 