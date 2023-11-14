#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Auth.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	Auth A;
	A.startMenu();
	return 0;
}
//ALL_USERS.DB || ORDERS_STACK.DB(for manager: user id + date + order_params) || ALL_ORDERS.DB || CITIES_AND_TRANSPORT.DB