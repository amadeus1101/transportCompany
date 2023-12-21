#include "ApplicationsList.h"

ApplicationsList::ApplicationsList(string _path, string _backup) {
	file = new fstream();
	PATH = _path;
	BACKUP_PATH = _backup;
	char _key[11];
	char _value[11];

	file->open(PATH + "config.dat", ios::binary | ios::in);
	if (!file->is_open())
	{
		std::cout << "!!!" << std::setw(22) << " [503] SERVER ERROR " << "!!!" << std::endl;
		std::cout << "***" << std::setw(22) << " PLEASE RECONNECT " << "***" << std::endl;
	}
	else {
		while (!file->eof()) {
			file->read((char*)&_key, sizeof(_key));
			file->read((char*)&_value, sizeof(_value));
			applications[_key] = _value;
		}
	}
	file->close();
}

ApplicationsList::~ApplicationsList() {
	file->open(PATH + "config.dat", std::ios::binary | std::ios::out);
	if (file->is_open())
	{
		char t_key[11];
		char t_val[11];
		for (const auto& obj : applications)
		{
			strcpy_s(t_key, obj.first.c_str());
			strcpy_s(t_val, obj.second.c_str());
			file->write((char*)&t_key, sizeof(t_key));
			file->write((char*)&t_val, sizeof(t_val));
		}
	}
	else {
		cout << "Unexpected error, DB destructor collapse!!!" << endl;
	}
	file->close();
	delete file;
	applications.clear();
}

//DATABASE OPERATIONS

bool ApplicationsList::create(string _UID) {
	time_t date = time(nullptr);
	string _AID = to_string(date);
	Application tapp{ _UID, _AID };
	if (applications.count(tapp.getAppId()))
		return false;
	file->open((PATH + tapp.getAppId() + ".dat"), ios::binary | ios::out);
	if (!file->is_open())
		return false;
	file->write((char*)&tapp, sizeof(Application));
	file->close();
	applications[tapp.getAppId()] = tapp.getUserId();
	return true;
}

Application* ApplicationsList::read(string _key) {
	if (!applications.count(_key))
		return nullptr;
	file->open((PATH + _key + ".dat"), ios::binary | ios::in);
	if (!file->is_open())
		return nullptr;
	Application* obj = new Application;
	file->read((char*)&(*obj), sizeof(Application));
	file->close();
	return obj;
}

void ApplicationsList::print(string _key) {
	Application* obj = read(_key);
	if (obj) obj->show();
	delete obj;
}

void ApplicationsList::print() {
	char t_key[11];
	cout << "| " << setw(20) << "Application" << " | " << setw(20) << "Customer" << " |" << endl;
	for (const auto& elem : applications)
		cout << "| " << setw(20) << elem.first << " | " << setw(20) << elem.second << " |" << endl;
}

bool ApplicationsList::remove(string _key) {
	if (!applications.count(_key))
		return false;
	string _fname = PATH + _key + ".dat";
	if (!std::remove(_fname.c_str()))
	{
		applications.erase(_key);
		std::cout << "FILE: " << _fname << ":: was successfully deleted" << std::endl;
		return true;
	}
	else {
		std::cout << "Error in file, cannot delete" << std::endl;
		return false;
	}
}

bool ApplicationsList::backup() {
	fstream* back_file = new fstream;
	time_t mytime = time(nullptr);
	struct tm* now = new tm;
	localtime_s(now, &mytime);
	string date = "BACKED UP AT " + to_string(now->tm_mday) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_year + 1900) + "::" + to_string(now->tm_hour) + "." + to_string(now->tm_min) + "::[" + to_string(applications.size()) + " objects]";
	delete now;
	//CONFIG BACKUP
	back_file->open(BACKUP_PATH + "config.dat", ios::binary | ios::out);
	if (back_file->is_open())
	{
		char t_key[11];
		char t_val[11];
		for (const auto& elem : applications)
		{
			strcpy_s(t_key, elem.first.c_str());
			strcpy_s(t_val, elem.second.c_str());
			file->write((char*)&t_key, sizeof(t_key));
			file->write((char*)&t_val, sizeof(t_val));
		}
	}
	back_file->close();

	//DATABASE BACKUP
	Application obj;
	for (const auto& elem : applications)
	{
		file->open((PATH + elem.first + ".dat"), ios::binary | ios::in);
		back_file->open((BACKUP_PATH + elem.first + ".dat"), ios::binary | ios::out);
		if (file->is_open() && back_file->is_open())
		{
			file->read((char*)&obj, sizeof(Application));
			back_file->write((char*)&obj, sizeof(Application));
		}
		file->close();
		back_file->close();
	}
	//BACKUP INFO
	ofstream ofl;
	ofl.open(BACKUP_PATH + "README.txt");
	if (ofl.is_open())
	{
		ofl << date << std::endl;
	}
	ofl.close();
	//cout << endl << "BACKUP HAS BEEN DONE at " << date << endl;
	delete back_file;
	return true;
}