#pragma once
#include <string>

class Cargo 
{
protected:
	int cargo_id;
	double len;
	double wid;
	double hei;
	std::string type;
public:
	void checkCargoParams();
	void calculateCapacity();
	void getCargoId();
	void getCargoParams();
	void getCargoType();

};