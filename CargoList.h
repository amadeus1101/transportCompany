#pragma once

class CargoList 
{
public:
	void createCargo();
	void getCargo(); // + peregruzka po ID
	void updateCargo(int);
	void deleteCargo(int);
	void printCargoList();
	void sortCargoList();
	void filterCargList(); // peregruzka po condition int/str...
};