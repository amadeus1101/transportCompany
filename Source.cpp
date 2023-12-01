#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

#include "Application.h"
#include "Cargo.h"

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
	Application tAp;
	tAp.show();
	Cargo tCar;
	tCar.show();
	
	return 0;
}