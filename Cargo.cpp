#include "Cargo.h"

Cargo::Cargo() {
	std::cout << std::setw(75 / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::cout << std::setw(75 / 2 - 12) << std::setfill(' ') << " F R E I G H T " << std::endl;
	std::cout << std::setw(75 / 2 - 2) << std::setfill('-') << "-" << std::endl;
	std::string phrases[] = { "Length", "Width", "Heigth", "Weight", "Cargo type", "Package type" };
	int phrasesLen = 6;
	std::cout << std::endl << "Length (m): ";
	std::cin >> cargo_params[0];
	std::cout << std::endl << "Width (m): ";
	std::cin >> cargo_params[1];
	std::cout << std::endl << "Height (m): ";
	std::cin >> cargo_params[2];
	std::cout << std::endl << "Weight (kg): ";
	std::cin >> cargo_params[3];
	std::cout << std::endl << "Cargo type: ";
	std::cin >> cargo_type;
	std::cout << std::endl << "Package type: ";
	std::cin >> package_type;
	
	price = 0;
}

void Cargo::show() {
	const int bufSize = 75;
	std::string phrase = "F R E I G H T";

	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << std::setw((bufSize - phrase.length()) / 2 - 2) << std::setfill(' ') << " " << phrase << " ";
	std::cout << std::setw((bufSize - phrase.length()) / 2 - 1) << std::setfill(' ') << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;

	std::cout << "| Params: " << std::setw(bufSize - 6 - 14) << std::setfill('.') << cargo_params[0] << " x " << cargo_params[1] << " x " << cargo_params[2] << " |" << std::endl;
	std::cout << "| Weigth: " << std::setw(bufSize - 4 - 8) << std::setfill('.') << cargo_params[3] << " |" << std::endl;
	std::cout << "| Cargo type: " << std::setw(bufSize - 4 - 12) << std::setfill('.') << cargo_type << " |" << std::endl;
	std::cout << "| Package type: " << std::setw(bufSize - 4 - 14) << std::setfill('.') << package_type << " |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	//Price
	std::string pr = "T O T A L  P R I C E";
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
	std::cout << "| " << pr << " : " << std::setw(bufSize - 9 - pr.length()) << std::setfill('.') << getPrice() << " $ |" << std::endl;
	std::cout << std::setw(bufSize) << std::setfill('-') << "-" << std::endl;
}

double Cargo::getPrice() {
	return cargo_params[0] * cargo_params[1] * cargo_params[2] / cargo_params[3] + cargo_type * package_type;
}