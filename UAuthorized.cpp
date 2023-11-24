#include "UAuthorized.h"

UAuthorized::UAuthorized() {
	UObj = new UsersHashMap("USERS.dat", 10);
}

void UAuthorized::getAll() {
	std::cout << "**********USERS DB**********" << std::endl;
	UObj->getUsers();
}

bool UAuthorized::authorization() {
	std::string _cusernm;
	std::string _cpass;

	std::cout << "AUTHORIZATION: " << std::endl;
	std::cout << "Enter yout data: " << std::endl;
	std::cout << std::endl << "login: ";
	std::cin >> _cusernm;
	std::cout << std::endl << "password: ";
	std::cin >> _cpass;

	std::string* userObj = UObj->getAuth(_cusernm, _cpass);

	if (userObj != NULL)
	{
		User* user;
		int uid = atoi(userObj[0].c_str());
		int ust = atoi(userObj[4].c_str());
		switch (ust)
		{
		case 2:
			user = new Employee(uid, userObj[1], userObj[2], userObj[3], ust); break;
		case 3:
			user = new Manager(uid, userObj[1], userObj[2], userObj[3], ust); break;
		case 4:
			user = new Admin(uid, userObj[1], userObj[2], userObj[3], ust); break;
		default:
			user = new User(uid, userObj[1], userObj[2], userObj[3], ust);
			break;
		}
		user->menu();
	}
	else std::cout << "PAROL NEVERNIJ ILI TAKOGO USERA NETU";

	//if (UObj->getAuth(_cusernm, _cpass)) std::cout << "USPESHNO" << std::endl;
	
	return true;
}

bool UAuthorized::registration() {
	bool isPasswordValid = false;

	std::string _username;
	std::string _password;
	std::string _name;

	while (!isPasswordValid)
	{
		std::cout << "REGISTRATION" << std::endl;
		std::cout << "Enter yout data: " << std::endl;
		std::cout << std::endl << "login: ";
		std::cin >> _username;
		std::cout << std::endl << "password: ";
		std::cin >> _password;
		std::cout << std::endl << "name: ";
		std::cin >> _name;
		isPasswordValid = validate(_username, _password);
	}
	UObj->write(_username, _password, _name);

	return true;
}

bool UAuthorized::validate(std::string _uname, std::string _pass) {
	std::transform(_uname.begin(), _uname.end(), _uname.begin(), ::tolower);
	std::transform(_pass.begin(), _pass.end(), _pass.begin(), ::tolower);
	size_t unameLen = _uname.length();
	size_t passLen = _pass.length();
	bool isPassValid = false;

	if (unameLen == 0 || passLen == 0)
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return false;
	}
	if (unameLen < 4 || unameLen > 11)
	{
		std::cout << "The username should be > 3 and < 12 symbols";
		return false;
	}
	if (passLen < 5 || passLen > 13)
	{
		std::cout << "The password should be > 4 and < 13 symbols ";
		return false;
	}
	for (int j = 0; j < unameLen; j++)
	{
		char c = _uname[j];
		if (c < 57)
		{
			isPassValid = true;
			break;
		}
	}
	if (!isPassValid) {
		std::cout << "The username should contain minimum 1 number" << std::endl;
		return false;
	}
	isPassValid = false;
	for (int j = 0; j < unameLen; j++)
	{
		char c = _uname[j];
		if (c > 65)
		{
			isPassValid = true;
			break;
		}
	}
	if (!isPassValid) {
		std::cout << "The password should contain minimum 1 letter" << std::endl;
		return false;
	}
	if (UObj->find(_uname) != NULL)
	{
		std::cout << "The username has already taken, try to create another new;(" << std::endl;
		return false;
	}
	std::cout << "All data is valid. USER registrated" << std::endl;
	return true;
}