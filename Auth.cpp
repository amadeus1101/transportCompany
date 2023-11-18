#include "Auth.h"

void Auth::authMenu() {
	std::cout << "this is menu" << std::endl;
	std::cout << "1 authoriz" << std::endl;
	std::cout << "2 registr" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: authorization(); break;
	case 2: registration(); break;
	default:
		std::cout << "Oshibka vibora" << std::endl;
	}
}

bool Auth::authorization() {
	int len;
	char c;
	std::ifstream fin("1_USER.dat", std::ios::in | std::ios::binary);
	if (!fin.is_open())
	{
		std::cout << "NET DOSTUPA K DB" << std::endl;
		return false;
	}
	std::cout << "***AUTHORIZATION***" << std::endl;
	std::cout << "ENTER_YOUR_DATA>>>" << std::endl;
	std::cout << std::endl << "login: ";
	std::cin >> UObj._login;
	std::cout << std::endl <<"password: ";
	std::cin >> UObj._password;

	while (!fin.eof())
	{
		AuthUser temp;
		//USER_ID

		fin.read((char*)&temp._user_ID, sizeof(int));

		//LOGIN

		fin.read((char*)&len, sizeof(int));
		
		temp._login = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			temp._login += c;
		}

		//PASSWORD

		fin.read((char*)&len, sizeof(int));
		temp._password = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			temp._password += c;
		}

		//NAME

		fin.read((char*)&len, sizeof(int));
		temp._name = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			temp._name += c;
		}

		//ROLE

		fin.read((char*)&len, sizeof(int));
		temp._role = "";
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)&c, sizeof(c));
			temp._role += c;
		}

		UVector.push_back(temp);
	}

	fin.close();

	for (int j = 0; j < UVector.size(); j++)
	{
		if (UObj._login == UVector[j]._login && UObj._password == UVector[j]._password)
		{
			user = new Customer(UVector[j]._user_ID, UVector[j]._login, UVector[j]._password, UVector[j]._name, UVector[j]._role);
			user->show();
			return true;
		}
	}
	std::cout << "A USERA TO NETU" << std::endl;
	return false;
}

bool Auth::registration() {
	std::cout << "***REGISTRATION***" << std::endl;
	std::cout << "ENTER_YOUR_DATA>>>" << std::endl;
	std::cout << std::endl << "login: ";
	std::cin >> UObj._login;
	std::cout << std::endl << "password: ";
	std::cin >> UObj._password;
	std::cout << std::endl << "name: ";
	std::cin >> UObj._name;

	//FILE

	std::ofstream fout;
	fout.open("1_USER.dat", std::ios::out | std::ios::binary | std::ios::app);
	if (!fout.is_open())
	{
		std::cout << "oshibka s failom";
		return false;
	}

	//USER_ID

	fout.write((char*)&UObj._user_ID, sizeof(int));

	//LOGIN

	int len = UObj._login.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&UObj._login[i], sizeof(UObj._login[i]));

	//PASSWORD

	len = UObj._password.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&UObj._password[i], sizeof(UObj._password[i]));

	//NAME

	len = UObj._name.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&UObj._name[i], sizeof(UObj._name[i]));

	// ROLE

	len = UObj._role.length();
	fout.write((char*)&len, sizeof(int));
	for (int i = 0; i < len; i++)
		fout.write((char*)&UObj._role[i], sizeof(UObj._role[i]));

	fout.close();

	user = new Customer(UObj._user_ID, UObj._login, UObj._password, UObj._name, UObj._role);
	user->show();

	return true;	
}