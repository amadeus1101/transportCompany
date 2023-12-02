#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Freight.h"

class Application : public Freight {
protected:
	int app_id;
	int user_id;
	bool is_approve;
	std::string worker_username;
	//sender
	std::string sender_info[5];
	//payment
	std::string card_16;
	std::string card_date;
	//reciever
	std::string reciever_info[5];
public:
	Application();
	void show() override;
};
