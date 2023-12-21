#include "Application.h"

Application::Application() {
	is_approve = false;
	strcpy_s(app_id, "e0");
	strcpy_s(user_id, "e0");
	strcpy_s(worker_id, "e0");
	strcpy_s(sen_fname, "e0");
	strcpy_s(sen_lname, "e0");
	strcpy_s(sen_mail, "e0");
	strcpy_s(sen_phone, "e0");
	strcpy_s(rec_fname, "e0");
	strcpy_s(rec_lname, "e0");
	strcpy_s(rec_mail, "e0");
	strcpy_s(rec_phone, "e0");
}

Application::Application(std::string _ID, std::string _DATE) : Freight::Freight(0) {
	is_approve = false;
	strcpy_s(app_id, _DATE.c_str());
	strcpy_s(user_id, _ID.c_str());
	strcpy_s(worker_id, "e0");

	const double bufSize = 75;
	//From
	system("CLS");
	std::cout << std::setw(bufSize - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - 7) / 2 - 2) << std::setfill(' ') << " " << "F R O M" << " ";
	std::cout << std::setw((bufSize - 7) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize - 2) << std::setfill('-') << "-" << std::endl;

	std::cout << std::endl << "First name: ";
	std::cin >> sen_fname;
	std::cout << std::endl << "Last name: ";
	std::cin >> sen_lname;
	std::cout << std::endl << "Mail: ";
	std::cin >> sen_mail;
	std::cout << std::endl << "Phone: ";
	std::cin >> sen_phone;

	//To
	system("CLS");
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - 3) / 2 - 2) << std::setfill(' ') << " " << "T O" << " ";
	std::cout << std::setw((bufSize - 4) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	
	std::cout << std::endl << "First name: ";
	std::cin >> rec_fname;
	std::cout << std::endl << "Last name: ";
	std::cin >> rec_lname;
	std::cout << std::endl << "Mail: ";
	std::cin >> rec_mail;
	std::cout << std::endl << "Phone: ";
	std::cin >> rec_phone;
}

void Application::show() {
	const int bufSize = 75;
	//system("CLS");
	//Header
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - 21) / 2 - 2) << std::setfill(' ') << " " << "A P P L I C A T I O N" << " ";
	std::cout << std::setw((bufSize - 21) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	//FROM&TO
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - 7) / 2 - 2) << std::setfill(' ') << " " << "F R O M" << " ";
	std::cout << std::setw((bufSize - 7) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| First Name: " << std::setw(bufSize - 16) << std::setfill('.') << sen_fname << " |" << std::endl;
	std::cout << "| Last Name: " << std::setw(bufSize - 15) << std::setfill('.') << sen_lname << " |" << std::endl;
	std::cout << "| Email: " << std::setw(bufSize - 11) << std::setfill('.') << sen_mail << " |" << std::endl;
	std::cout << "| Phone: " << std::setw(bufSize - 11) << std::setfill('.') << sen_phone << " |" << std::endl;
	std::cout << "| Country: " << std::setw(bufSize - 13) << std::setfill('.') << getCountryName(dep_code) << " |" << std::endl;
	std::cout << "| City: " << std::setw(bufSize - 10) << std::setfill('.') << getCityName(dep_code) << " |" << std::endl;

	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setw((bufSize - 3) / 2) << std::setfill(' ') << " " << "T O" << " ";
	std::cout << std::setw((bufSize - 3) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| First Name: " << std::setw(bufSize - 16) << std::setfill('.') << rec_fname << " |" << std::endl;
	std::cout << "| Last Name: " << std::setw(bufSize - 15) << std::setfill('.') << rec_lname << " |" << std::endl;
	std::cout << "| Email: " << std::setw(bufSize - 11) << std::setfill('.') << rec_mail << " |" << std::endl;
	std::cout << "| Phone: " << std::setw(bufSize - 11) << std::setfill('.') << rec_phone << " |" << std::endl;
	std::cout << "| Country: " << std::setw(bufSize - 13) << std::setfill('.') << getCountryName(des_code) << " |" << std::endl;
	std::cout << "| City: " << std::setw(bufSize - 10) << std::setfill('.') << getCityName(des_code) << " |" << std::endl;

	//Freight
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - 13) / 2 - 2) << std::setfill(' ') << " " << "F R E I G H T" << " ";
	std::cout << std::setw((bufSize - 13) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| Application Identificator: " << std::setw(bufSize - 31) << std::setfill('.') << app_id << " |" << std::endl;
	std::cout << "| Transport: " << std::setw(bufSize - 15) << std::setfill('.') << getVehicleName() << " |" << std::endl;
	std::cout << "| Params: " << std::setw(bufSize - 16) << std::setfill('.') << capacity << " cm3 |" << std::endl;
	std::cout << "| Weigth: " << std::setw(bufSize - 15) << std::setfill('.') << weight << " kg |" << std::endl;
	std::cout << "| Cargo type: " << std::setw(bufSize - 16) << std::setfill('.') << getFreightName(freight_type) << " |" << std::endl;
	std::cout << "| Package type: " << std::setw(bufSize - 18) << std::setfill('.') << getPackageName(package_type) << " |" << std::endl;
	

	//PRICE
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| T O T A L  P R I C E : " << std::setw(bufSize - 29) << std::setfill('.') << getPrice() << " $ |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
}

char* Application::getUserId()
{
	return user_id;
}

char* Application::getManagerId()
{
	return worker_id;
}

std::string Application::getAppId() {
	return app_id;
}