#pragma once

#include <iostream>
#include <string>

class Route
{
protected:
	int route_id;
	int dep_code;
	int des_code;
public:
	Route();
	//Route(std::string, std::string);
	//~Route();
	virtual void show();
	bool valid(int&, int, int);
	std::string getCountryName(int&);
	std::string getCityName(int&);
private:
	int len_i = 4;
	int len_j = 3;
	std::string countries[4] = { "Germany", "France", "Spain", "Belarus" };
	std::string cities[4][3] = { {"Berlin", "Hamburg", "Frankfurt"}, {"Paris", "Lion", "Gil'o-tine"}, {"Madrid", "Barca", "Castillio"}, {"Minsk", "Grommel", "Vitebsk"} };
};

