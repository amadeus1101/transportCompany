#pragma once

class UsersList
{
public:
	void createUser(); // + peregruzka po ROLE
	void getUser(int);
	void updateUser();
	void deleteUser(int);
	void printUsers();
	void sortUsers();
	void filterUsers(); // peregruzka po condition int/str...
};