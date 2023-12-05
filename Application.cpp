#include "Application.h"

Application::Application() {
	app_id = -1;
	is_approve = false;
	user_id = -1;
	const int bufSize = 75;
	std::string phraseArr[] = {"A P P L I C A T I O N" , "F R O M", "T O", "F R E I G H T", "R E S U L T  P R I C E"};
	int phraseLen = 4;
	std::string fields[] = { "Name", "Email", "Phone" };
	int fieldsLen = 3;
	//From
	system("CLS");
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize / 2 - phraseArr[1].length()) / 2 - 2) << std::setfill(' ') << " " << phraseArr[1] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[1].length() - 1) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize/2 - 2) << std::setfill('-') << "-" << std::endl;

	std::cout << std::endl << fields[0] << ": ";
	std::cin >> sen_name;
	std::cout << std::endl << fields[1] << ": ";
	std::cin >> sen_mail;
	std::cout << std::endl << fields[2] << ": ";
	std::cin >> sen_phone;

	system("CLS");
	//To
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize / 2 - phraseArr[2].length()) / 2 - 2) << std::setfill(' ') << " " << phraseArr[2] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[2].length() - 1) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	
	std::cout << std::endl << fields[0] << ": ";
	std::cin >> rec_name;
	std::cout << std::endl << fields[1] << ": ";
	std::cin >> rec_mail;
	std::cout << std::endl << fields[2] << ": ";
	std::cin >> rec_phone;

	//OUTPUT
}

void Application::show() {
	int bufSize = 75;
	std::string phraseArr[] = { "A P P L I C A T I O N" , "F R O M", "T O", "F R E I G H T", "T O T A L  P R I C E", "T R A N S P O R T"};
	std::string fields[] = { "Name", "Email", "Phone", "Country", "City" };
	int fieldsLen = 5;
	system("CLS");
	//Header
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - phraseArr[0].length()) / 2 - 2) << std::setfill(' ') << " " << phraseArr[0] << " ";
	std::cout << std::setw((bufSize - phraseArr[0].length()) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	//Freight
	std::cout << "| " << std::setw((bufSize - phraseArr[3].length()) / 2 - 2) << std::setfill(' ') << " " << phraseArr[3] << " ";
	std::cout << std::setw((bufSize - phraseArr[3].length()) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| Params: " << std::setw(bufSize - 18 - (len / 100 + 1) - (wid / 100 + 1) - (hei / 100 + 1)) << std::setfill('.') << len << " x " << wid << " x " << hei << " |" << std::endl;
	std::cout << "| Weigth: " << std::setw(bufSize - 4 - 8) << std::setfill('.') << wei << " |" << std::endl;
	std::cout << "| Cargo type: " << std::setw(bufSize - 4 - 12) << std::setfill('.') << freight_type << " |" << std::endl;
	std::cout << "| Package type: " << std::setw(bufSize - 4 - 14) << std::setfill('.') << package_type << " |" << std::endl;
	std::cout << "| Transport: " << std::setw(bufSize - 4 - 11) << std::setfill('.') << vehicle << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	//FROM&TO
	std::cout << "| " << std::setw((bufSize / 2 - phraseArr[1].length()) / 2 - 1) << std::setfill(' ') << " " << phraseArr[1] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[1].length()) / 2) << std::setfill(' ') << " | ";
	std::cout << std::setw((bufSize / 2 - phraseArr[2].length()) / 2) << std::setfill(' ') << " " << phraseArr[2] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[2].length()) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| " << fields[0] << ": " << std::setw(bufSize / 2 - 5 - fields[0].length()) << std::setfill('.') << sen_name << " | ";
	std::cout << std::setw(fields[0].length()) << fields[0] << ": " << std::setw(bufSize / 2 - 5 - fields[0].length()) << rec_name << " |" << std::endl;
	std::cout << "| " << fields[1] << ": " << std::setw(bufSize / 2 - 5 - fields[1].length()) << std::setfill('.') << sen_mail << " | ";
	std::cout << std::setw(fields[1].length()) << fields[1] << ": " << std::setw(bufSize / 2 - 5 - fields[1].length()) << rec_mail << " |" << std::endl;
	std::cout << "| " << fields[2] << ": " << std::setw(bufSize / 2 - 5 - fields[2].length()) << std::setfill('.') << sen_phone << " | ";
	std::cout << std::setw(fields[2].length()) << fields[2] << ": " << std::setw(bufSize / 2 - 5 - fields[2].length()) << rec_phone << " |" << std::endl;
	std::cout << "| " << fields[3] << ": " << std::setw(bufSize / 2 - 5 - fields[3].length()) << std::setfill('.') << getCountryName(dep_code) << " | ";
	std::cout << std::setw(fields[3].length()) << fields[3] << ": " << std::setw(bufSize / 2 - 5 - fields[3].length()) << getCountryName(des_code) << " |" << std::endl;
	std::cout << "| " << fields[4] << ": " << std::setw(bufSize / 2 - 5 - fields[4].length()) << std::setfill('.') << getCityName(dep_code) << " | ";
	std::cout << std::setw(fields[4].length()) << fields[4] << ": " << std::setw(bufSize / 2 - 5 - fields[4].length()) << getCityName(des_code) << " |" << std::endl;

	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	//PRICE
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << phraseArr[4] << " : " << std::setw(bufSize - 9 - phraseArr[4].length()) << std::setfill('.') << getPrice() << " $ |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
}