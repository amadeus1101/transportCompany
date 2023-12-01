#include "Application.h"

Application::Application() {
	app_id = -1;
	is_approve = false;
	user_id = -1;
	//freight details
	
	//shipment details+form+payment
	const int bufSize = 75;
	std::string phraseArr[] = {"A P P L I C A T I O N" , "F R O M", "T O", "F R E I G H T", "R E S U L T  P R I C E"};
	int phraseLen = 4;
	std::string fields[] = { "Name", "Email", "Phone", "Country", "City" };
	int fieldsLen = 5;
	//From
	system("CLS");
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize / 2 - phraseArr[1].length()) / 2 - 2) << std::setfill(' ') << " " << phraseArr[1] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[1].length() - 1) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize/2 - 2) << std::setfill('-') << "-" << std::endl;
	for (int i = 0; i < fieldsLen; i++)
	{
		std::cout << std::endl << fields[i] << ": ";
		std::cin >> sender_info[i];
	}
	system("CLS");
	//To
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize / 2 - phraseArr[2].length()) / 2 - 2) << std::setfill(' ') << " " << phraseArr[2] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[2].length() - 1) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	for (int i = 0; i < fieldsLen; i++)
	{
		std::cout << std::endl << fields[i] << ": ";
		std::cin >> reciever_info[i];
	}

	//OUTPUT
}

void Application::show() {
	int bufSize = 75;
	std::string phraseArr[] = { "A P P L I C A T I O N" , "F R O M", "T O", "F R E I G H T", "T O T A L  P R I C E" };
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

	std::cout << "| Params: " << std::setw(bufSize - 6 - 14) << std::setfill('.') << cargo_params[0] << " x " << cargo_params[1] << " x " << cargo_params[2] << " |" << std::endl;
	std::cout << "| Weigth: " << std::setw(bufSize - 4 - 8) << std::setfill('.') << cargo_params[3] << " |" << std::endl;
	std::cout << "| Cargo type: " << std::setw(bufSize - 4 - 12) << std::setfill('.') << cargo_type << " |" << std::endl;
	std::cout << "| Package type: " << std::setw(bufSize - 4 - 14) << std::setfill('.') << package_type << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	//FROM&TO
	std::cout << "| " << std::setw((bufSize / 2 - phraseArr[1].length()) / 2 - 1) << std::setfill(' ') << " " << phraseArr[1] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[1].length()) / 2) << std::setfill(' ') << " | ";
	std::cout << std::setw((bufSize / 2 - phraseArr[2].length()) / 2) << std::setfill(' ') << " " << phraseArr[2] << " ";
	std::cout << std::setw((bufSize / 2 - phraseArr[2].length()) / 2 - 2) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	for (int i = 0; i < fieldsLen; i++)
	{
		std::cout << "| " << fields[i] << ": " << std::setw(bufSize / 2 - 5 - fields[i].length()) << std::setfill('.') << sender_info[i] << " | ";
		std::cout << std::setw(fields[i].length()) << fields[i] << ": " << std::setw(bufSize / 2 - 5 - fields[i].length()) << reciever_info[i] << " |" << std::endl;
	}
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	//PRICE
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << phraseArr[4] << " : " << std::setw(bufSize - 9 - phraseArr[4].length()) << std::setfill('.') << getPrice() << " $ |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
}