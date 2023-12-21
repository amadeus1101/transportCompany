#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

#include "Freight.h"

class Application : public Freight {
protected:
	char app_id[13], user_id[21], worker_id[21];
	bool is_approve;
	//sender
	char sen_fname[41], sen_lname[41], sen_mail[41], sen_phone[14];
	//reciever
	char rec_fname[41], rec_lname[41], rec_mail[41], rec_phone[14];
public:
	Application();
	Application(std::string, std::string);
	//~Application();
	void show();
	std::string getAppId();
	char* getUserId();
	char* getManagerId();
};
