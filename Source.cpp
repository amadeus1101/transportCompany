#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

#include "UAuthorized.h"
#include "User.h"

using namespace std;

int main() {
	//ENTER -> WORK -> EXIT
	
	UAuthorized unAuthUser;
	//UObj.insert(15, "+-USERNAME-+", "++PASSWORDE++", "***PERSONALE***", 1);
	//UObj.getUsers();
	int user_choice = 0;
	while (user_choice != 3)
	{
		cout << "ASTC" << endl;
		cout << "MAIN MENU" << endl;
		cout << "1. AUTHERIZATION" << endl;
		cout << "2. REGISTRATION" << endl;
		cout << "3. EXIT" << endl;
		cin >> user_choice;
		switch (user_choice)
		{
		case 1:
			cout << unAuthUser.authorization() << endl; break;
		case 2:
			cout << unAuthUser.registration() << endl; break;
		case 3:
			cout << "(3)" << endl; break;
		default:
			break;
		}
	}
	
	return 0;
}