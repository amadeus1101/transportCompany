#pragma once
#include <string>

class User
{
protected:
	int user_ID;
	std::string username;
	std::string password;
	std::string fio;
	std::string tel;
	char role[2];
public:
	virtual void showProfile() = 0;
	virtual void changePassword() = 0;
};

