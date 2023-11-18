#pragma once

class UserList {
protected:
	//string file userDB*
	//vector of user-obj*
	//temp user obj* ??
public:
	//openfile->getUsers*
	// compare users logins
	// 
	//CRUD
	virtual void createUser() = 0;
	virtual void getUser(int) = 0;
	//virtual void updateUser(int) = 0;
	//virtual void deleteUser(int) = 0;
	//DB
	//virtual void getUserList() = 0;
	//virtual void sortUserList(int) = 0;
	//virtual void filterUserList(int) = 0;
};