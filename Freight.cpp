#include "Freight.h"

Freight::Freight() {
	const int bufSize = 75;

	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setw(bufSize / 2 - 12) << std::setfill(' ') << " F R E I G H T " << std::endl;
	std::cout << std::setw(bufSize / 2 - 2) << std::setfill('-') << "-" << std::endl;

	std::cout << std::endl << "Length (cm): ";
	std::cin >> len;
	while (!valid(len, 0, 201))
		std::cin >> len;

	std::cout << std::endl << "Width (cm): ";
	std::cin >> wid;
	while (!valid(wid, 0, 201))
		std::cin >> wid;

	std::cout << std::endl << "Height (cm): ";
	std::cin >> hei;
	while (!valid(hei, 0, 201))
		std::cin >> hei;

	std::cout << std::endl << "Weight (kg): ";
	std::cin >> wei;
	while (wei < 0 || wei > 51)
	{
		std::cout << "The weight should be > 0 and <= 50 kgs" << std::endl;
		std::cin >> wei;
	}
		
	std::cout << std::endl << "Freight type: " << std::endl;
	for (int i = 0; i < fr_types_len; i++)
		std::cout << i << ". " << fr_types[i] << std::endl;
	std::cin >> freight_type;
	while (!valid(freight_type, 0, fr_types_len))
		std::cin >> freight_type;

	std::cout << std::endl << "Package type: " << std::endl;
	for (int i = 0; i < pc_types_len; i++)
		std::cout << i << ". " << pc_types[i] << std::endl;
	std::cin >> package_type;
	while (!valid(package_type, 0, pc_types_len))
		std::cin >> package_type;
	
	price = 0;
}

void Freight::show() {
	system("CLS");
	const int bufSize = 75;
	std::string phrase = "F R E I G H T";

	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - phrase.length()) / 2 - 2) << std::setfill(' ') << " " << phrase << " ";
	std::cout << std::setw((bufSize - phrase.length()) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| Params: " << std::setw(bufSize - 19 - (len / 100 + 1) - (wid / 100 + 1) - (hei / 100 + 1)) << std::setfill('.') << len << " x " << wid << " x " << hei << " |" << std::endl;
	std::cout << "| Weigth: " << std::setw(bufSize - 4 - 8) << std::setfill('.') << wei << " |" << std::endl;
	std::cout << "| Cargo type: " << std::setw(bufSize - 4 - 12) << std::setfill('.') << fr_types[freight_type] << " |" << std::endl;
	std::cout << "| Package type: " << std::setw(bufSize - 4 - 14) << std::setfill('.') << pc_types[package_type] << " |" << std::endl;
	std::cout << "| " << getCityName(dep_code) << " [" << getCountryName(dep_code) << "] --> " << getCityName(des_code) << " [" << getCountryName(des_code) << "]   BY   { " << vehicle << " }" << std::endl;

	std::string pr = "T O T A L  P R I C E";
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << pr << " : " << std::setw(bufSize - 9 - pr.length()) << std::setfill('.') << getPrice() << " $ |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
}

double Freight::getPrice() {
	return (len * wid * hei) / (wei * 100) + freight_type * package_type;
}

bool valid(int& val, int begin, int end) {
	if (val < begin || val > end) {
		std::cout << "The value should be correct in range from " << begin << " to " << end << std::endl;
		return false;
	}
	return true;
}