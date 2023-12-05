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
	std::string sen_name, sen_mail, sen_phone;
	std::string sender_info[3];
	//payment
	std::string card_16;
	std::string card_date;
	//reciever
	std::string rec_name, rec_mail, rec_phone;
	std::string reciever_info[3];
public:
	Application();
	void show() override;
};
