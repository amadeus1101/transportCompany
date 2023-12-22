#include "RoutesList.h"

RoutesList::RoutesList(string _path, string _backup) {
	ifstream* file1 = new ifstream;
	ifstream* file2 = new ifstream;
	PATH = _path;
	BACKUP_PATH = _backup;
	char loc[23];
	int cod;

	file1->open(PATH + "routes.dat", ios::binary | ios::in);
	file2->open(PATH + "locations.dat", ios::binary | ios::in);
	if (!file1->is_open() || !file2->is_open())
	{
		std::cout << "!!!" << std::setw(22) << " [503] SERVER ERROR " << "!!!" << std::endl;
		std::cout << "***" << std::setw(22) << " CANNOT GET ROUTES " << "***" << std::endl;
	}
	else {
		Route obj;
		while (!file1->eof()) {
			file1->read((char*)&obj, sizeof(Route));
			routes.push_back(obj);
		}
		while (!file2->eof())
		{
			file2->read((char*)&cod, sizeof(cod));
			file2->read((char*)&loc, sizeof(loc));
			locations[cod] = loc;
		}
	}
	file1->close();
	file2->close();
	delete file1;
	delete file2;
}

RoutesList::~RoutesList() {
	ofstream* file = new ofstream;
	file->open(PATH + "locations.dat", ios::binary | ios::out);
	if (file->is_open())
	{
		char loc[23];
		for (const auto& obj : locations)
		{
			strcpy_s(loc, obj.second.c_str());
			file->write((char*)&obj.second, sizeof(int));
			file->write((char*)&loc, sizeof(loc));
		}
	}
	file->close();
	delete file;
	locations.clear();
	routes.clear();
}

bool RoutesList::create() {
	char loc[23];
	int cod;
	cout << "Add new destination point" << endl;
	cout << "Enter code: ";
	cin >> cod;
	cout << endl << "Enter title: ";
	cin >> loc;
	if (!locations.count(cod))
	{
		locations[cod] = loc;
		return true;
	}
	return false;
}

void RoutesList::printCountry() {
	for (const auto& obj : locations)
	{
		if (obj.first < 1000)
			cout << "#" << obj.first << "::" << obj.second << endl;
	}
}

void RoutesList::printCity(int country) {
	if(locations.count(country))
	for (const auto& obj : locations)
	{
		if (obj.first / 1000 == country)
			cout << "#" << obj.first << "::" << obj.second << endl;
	}
}

bool RoutesList::remove(int cod) {
	if (!locations.count(cod))
		return false;
	if (cod >= 1000)
	{
		locations.erase(cod);
		return true;
	}
	if (cod < 1000)
	{
		locations.erase(cod);
		for (const auto& obj : locations)
		{
			if (obj.first / 1000 == cod)
				locations.erase(obj.first);
		}
		return true;
	}
	return false;
}

bool RoutesList::push() {
	int _dep, _des, _pr, _country=0;
	cout << "Create new route" << endl;
	printCountry();
	cout << "Enter a departure country: ";
	cin >> _country;
	cout << endl;
	printCity(_country);
	cout << "Enter code of a departure city: ";
	cin >> _dep;
	cout << endl;
	printCountry();
	cout << "Enter a destination country: ";
	cin >> _country;
	cout << endl;
	printCity(_country);
	cout << "Enter code of a destination city: ";
	cin >> _des;
	cout << endl;
	cout << "Enter a price coefficient: ";
	cin >> _pr;
	cout << endl;
	Route obj{ _dep, _des, _pr };
	ofstream* file = new ofstream;
	file->open(PATH + "routes.dat", ios::binary | ios::out | ios::app);
	if (file->is_open())
		file->write((char*)&obj, sizeof(Route));
	file->close();
	delete file;
}
