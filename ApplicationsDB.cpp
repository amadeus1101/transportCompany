//#include "ApplicationsDB.h"
//
//ApplicationsDB::ApplicationsDB(std::string _path, std::string _conf, std::string _backup) : HashTable::HashTable(_path, _conf, _backup) {}
//
//ApplicationsDB::~ApplicationsDB() {}
//
////DATABASE OPERATIONS
//
//bool ApplicationsDB::create(std::string _ID) {
//	time_t mytime = time(NULL);
//	struct tm* now = new tm;
//	localtime_s(now, &mytime);
//	std::string date = now->tm_mday < 10 ? "0" + std::to_string(now->tm_mday) : std::to_string(now->tm_mday);
//	date += now->tm_mon < 9 ? "0" + std::to_string(now->tm_mon + 1) : std::to_string(now->tm_mon + 1);
//	date += std::to_string(now->tm_year + 1900);
//	date += now->tm_hour < 10 ? "0" + std::to_string(now->tm_hour) : std::to_string(now->tm_hour);
//	date += now->tm_min < 10 ? "0" + std::to_string(now->tm_min) : std::to_string(now->tm_min);
//	delete now;
//
//	Application t_app{_ID, date};
//
//	std::string _flname = date + ".dat";
//
//	file->open(PATH + _flname, std::ios::binary | std::ios::out);
//
//	if (!file->is_open())
//		return false;
//
//	file->write((char*)&t_app, sizeof(Application));
//
//	file->close();
//
//	HashNode* spt = new HashNode;
//	spt->t_key = date;
//	spt->t_value = _flname;
//	if (!push(*spt)) std::cout << "ERROR in creating hash-table" << std::endl;
//	if (count > size * resize_val)
//		resize();
//	delete spt;
//
//	return true;
//}
//
//void ApplicationsDB::read() {
//	Application t_app;
//	std::cout << "| " << std::setw(12) << " APP_ID " << " | " << std::setw(20) << " USER_ID " << " | " << std::setw(20) << " MANAGER_ID " << " |" << std::endl;
//	std::cout << std::setw(62) << std::setfill('-') << "-" << std::endl;
//	for (int i = 0; i < size; i++)
//	{
//		file->open(PATH + hashSet[i].t_value, std::ios::binary | std::ios::in);
//		if (file->is_open())
//		{
//			file->read((char*)&t_app, sizeof(Application));
//			std::cout << "| " << std::setw(12) << hashSet[i].t_key << " | " << std::setw(20) << t_app.getUserId() << " | " << std::setw(20) << t_app.getManagerId() << " |" << std::endl;
//		}
//		file->close();
//	}
//}
//
//void ApplicationsDB::read(std::string _key) {
//	int pos = find(_key);
//	if (pos > -1 && pos < size)
//	{
//		file->open(PATH + hashSet[pos].t_value, std::ios::binary | std::ios::in);
//		if (file->is_open())
//		{
//			Application t_app;
//			file->read((char*)&t_app, sizeof(Application));
//			system("CLS");
//			t_app.show();
//		}
//		file->close();
//	}
//}
//
//bool ApplicationsDB::remove(std::string _key) {
//	int pos = find(_key);
//	if (pos > -1 && pos < size)
//	{
//		std::string _flname = PATH + hashSet[pos].t_value;
//		char st[35];
//		strcpy_s(st, _flname.c_str());
//		if (!std::remove(st))
//		{
//			pop(_key);
//			std::cout << "FILE: " << st << ":: was successfully deleted" << std::endl;
//			return true;
//		}
//		else {
//			std::cout << "Error in file, cannot delete" << std::endl;
//			return false;
//		}
//	}
//	return false;
//}
//
//bool ApplicationsDB::backup() {
//	int len;
//	char sym;
//	std::fstream* back_file = new std::fstream;
//	std::ofstream ofl;
//	time_t mytime = time(NULL);
//	struct tm* now = new tm;
//	localtime_s(now, &mytime);
//	std::string date = "BACKED UP AT " + std::to_string(now->tm_mday) + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_year + 1900) + " :: " + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min);
//
//	//CONFIG BACKUP
//	back_file->open(BACKUP_PATH + CONFIG_FILE, std::ios::binary | std::ios::out);
//	if (back_file->is_open())
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (hashSet[i].t_key != "-1")
//			{
//				len = hashSet[i].t_key.length();
//				back_file->write((char*)&len, sizeof(len));
//				for (int j = 0; j < len; j++)
//					back_file->write((char*)&hashSet[i].t_key[j], sizeof(hashSet[i].t_key[j]));
//
//				len = hashSet[i].t_value.length();
//				back_file->write((char*)&len, sizeof(len));
//				for (int j = 0; j < len; j++)
//					back_file->write((char*)&hashSet[i].t_value[j], sizeof(hashSet[i].t_value[j]));
//			}
//		}
//	}
//	back_file->close();
//
//	//DATABASE BACKUP
//	Application t_app;
//	for (int i = 0; i < size; i++)
//	{
//		file->open(PATH + hashSet[i].t_value, std::ios::binary | std::ios::in);
//		back_file->open(BACKUP_PATH + hashSet[i].t_value, std::ios::binary | std::ios::out);
//		if (file->is_open() && back_file->is_open())
//		{
//			file->read((char*)&t_app, sizeof(Application));
//			back_file->write((char*)&t_app, sizeof(Application));
//		}
//		file->close();
//		back_file->close();
//	}
//
//	//BACKUP INFO
//	ofl.open(BACKUP_PATH + "README.txt");
//	if (ofl.is_open())
//	{
//		ofl << date << std::endl;
//	}
//	ofl.close();
//
//	std::cout << std::endl << "BACKUP HAS BEEN DONE at " << date << std::endl;
//
//	delete back_file;
//	return true;
//}