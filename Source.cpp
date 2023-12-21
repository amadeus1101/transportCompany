#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

#include "Guest.h"
#include "User.h"
#include "Employee.h"
#include "Manager.h"
#include "Admin.h"
#include "UsersDB.h"
#include "Freight.h"

using namespace std;

string USERS_PATH = "db/_users/";
UsersDB database{ USERS_PATH, "uconfig.dat", "db/backups/_users/" };
User* user;

void auth();
void reg();
void addFr();

int main() {
	//ENTER -> WORK -> EXIT
	int choice = 0;
	while (choice != 5)
	{
		cout << "*** Main menu ***" << endl;
		cout << "1. Auth" << endl;
		cout << "2. Reg" << endl;
		cout << "3. Get a quote ($)" << endl;
		cout << "4. Get tracker" << endl;
		cout << "5. Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			auth();
			break;
		case 2:
			reg();
			break;
		case 3:
			cout << "QUOTE" << endl; break;
		case 4:
			cout << "Tracker" << endl; break;
		default:
			break;
		}
	}
	return 0;
}

void auth() {
	string res = database.autharization();
	if (res == "null")
	{
		cout << "The user with login does not exist" << endl;
		return;
	}
	res = USERS_PATH + res;
	user = new User(res);
}

void reg() {
	if (!database.registration())
	{
		cout << "O No! Something went wrong. The user was not registrated. Try again" << endl;
		return;
	}
	cout << "SUCCESS. User was registrated with no warnings" << endl;
}