#pragma once
#include <string>

#include "Menu.h"

class Auth : public Menu {
public:
	void validator(std::string, std::string);
	void signUp();
	//signUp for admin with peregruzka
	void signIn();
	void logOut();
	void close();
	//override menu
};
