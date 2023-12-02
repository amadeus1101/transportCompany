#include "Guest.h"

Guest::Guest() {
	UObj = new UsersList("USERS.dat", 10);
}

void Guest::getAll() {
	std::cout << "**********USERS DB**********" << std::endl;
	UObj->getUsers();
}

bool Guest::authorization() {
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
	else std::cout << "The information is not valid or user with this parametrs does not exist";

	//if (UObj->getAuth(_cusernm, _cpass)) std::cout << "USPESHNO" << std::endl;
	
	return true;
}

bool Guest::registration() {
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

bool Guest::validate(std::string _uname, std::string _pass) {
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

bool Guest::createCargo() {
	std::string countriesArr[3][4] = {
		{"Germany", "Berlin", "Frankfurt", "Munhen"},
		{"France", "Paris", "Lion", "Marcel"},
		{"Spain", "Madrid", "Barcelona", "Valencia"} };
	std::string vehiclesArr[4] = { "Truck", "Train", "Ship", "Plane" };
	std::string cargoTypes[4] = { "Glass", "Metal", "Plastic", "Wood" };
	std::string packageTypes[3] = { "Paper", "Wooden", "Polymeric" };

	int _cargo, _package;
	int vic_code = -1, dep_code = -1, des_code = -1;
	int country_choice;
	double _cap, _wei;
	std::string _vic, _dep, _des;
	std::cout << "**********Cargo menu**********" << std::endl;
	std::cout << "Enter your parameters: " << std::endl;

	std::cout << std::endl << "capacity (m3): ";
	std::cin >> _cap;

	std::cout << std::endl << "weigth (kg): ";
	std::cin >> _wei;

	std::cout << std::endl << "Cargo type: " << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << i << ". " << cargoTypes[i] << std::endl;
	std::cin >> _cargo;
	std::cout << std::endl << "Your cargo-type: " << cargoTypes[_cargo] << std::endl;

	std::cout << std::endl << "Package type: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i << ". " << packageTypes[i] << std::endl;
	std::cin >> _package;
	std::cout << std::endl << "Your package-type: " << packageTypes[_package] << std::endl;

	std::cout << std::endl << "Vehicle: " << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << i << ". " << vehiclesArr[i] << std::endl;
	std::cin >> vic_code;
	_vic = vehiclesArr[vic_code];

	std::cout << std::endl << "Country of departure: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i << ". " << countriesArr[i][0] << std::endl;
	std::cin >> country_choice;
	std::cout << std::endl << "Your country: " << countriesArr[country_choice][0] << ". Now choose the city" << std::endl;
	for (int i = 1; i < 4; i++)
		std::cout << i << ". " << countriesArr[country_choice][i] << std::endl;
	std::cin >> dep_code;
	_dep = countriesArr[country_choice][dep_code];

	std::cout << std::endl << "Country of destination: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << i << ". " << countriesArr[i][0] << std::endl;
	std::cin >> country_choice;
	std::cout << std::endl << "Your country: " << countriesArr[country_choice][0] << ". Now choose the city" << std::endl;
	for (int i = 1; i < 4; i++)
		std::cout << i << ". " << countriesArr[country_choice][i] << std::endl;
	std::cin >> des_code;
	_des = countriesArr[country_choice][des_code];

	//Cargo* ncargo = new Cargo(_cargo, _package, _cap, _wei, _vic, _dep, _des);
	//ncargo->show();
	std::cout << "Norm ili ne? (Y/N)" << std::endl;
	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case 'Y':
		//std::cout << ncargo->calculateCargo() << std::endl;
		break;
	case 'N':
		std::cout << "MENYAI DANNIE TOGDA" << std::endl;
		break;
	default:
		std::cout << "Y/N chego slojnogo 2 letters vibrat??" << std::endl;
		break;
	}

	return true;
}