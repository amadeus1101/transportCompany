#include "Route.h"

Route::Route() {
	dep_code = -1;
	des_code = -1;
}

Route::Route(int _dep, int _des) {
	dep_code = _dep;
	des_code = _des;
}

void Route::getCountries() {
	std::string directions[4][4] = {
{"Germany", "Berlin", "Hamburg", "Frankfurt"},
{"France", "Paris", "Lion", "Gil'o-tine"},
{"Spain", "Madrid", "Barca", "Castillio"},
{"Belarus", "Minsk", "Grommel", "Vitebsk"} };
	for (int i = 0; i < len_i; i++)
		std::cout << i << ". " << directions[i][0] << std::endl;
}

void Route::getCities(int& _country) {
	std::string directions[4][4] = {
{"Germany", "Berlin", "Hamburg", "Frankfurt"},
{"France", "Paris", "Lion", "Gil'o-tine"},
{"Spain", "Madrid", "Barca", "Castillio"},
{"Belarus", "Minsk", "Grommel", "Vitebsk"} };
	for (int j = 1; j < len_j; j++)
		std::cout << j << ". " << directions[_country][j] << std::endl;
}

std::string Route::getCountryName(int &val) {
	std::string directions[4][4] = {
{"Germany", "Berlin", "Hamburg", "Frankfurt"},
{"France", "Paris", "Lion", "Gil'o-tine"},
{"Spain", "Madrid", "Barca", "Castillio"},
{"Belarus", "Minsk", "Grommel", "Vitebsk"} };
	if(val >= 0) return directions[val / 1000][0];
	return "Undefined";
}

std::string Route::getCityName(int& val) {
	std::string directions[4][4] = {
{"Germany", "Berlin", "Hamburg", "Frankfurt"},
{"France", "Paris", "Lion", "Gil'o-tine"},
{"Spain", "Madrid", "Barca", "Castillio"},
{"Belarus", "Minsk", "Grommel", "Vitebsk"} };
	if(val >= 0) return directions[val / 1000][val % 1000];
	return "Undefined";
}