#include "HashTable.h"

HashTable::HashTable(std::string &_path, std::string &_conf, std::string &_backup) {
	PATH = _path;
	BACKUP_PATH = _backup;
	CONFIG_FILE = _conf;
	size = 20;
	count = 0;
	hashSet = new HashNode[size];
	file = new std::fstream;
	
	for (int i = 0; i < size; i++)
	{
		hashSet[i].t_key = "-1";
	}

	file->open(PATH + CONFIG_FILE, std::ios::binary | std::ios::in);
	if (!file->is_open())
	{
		std::cout << "!!!" << std::setw(22) << " [503] SERVER ERROR " << "!!!" << std::endl;
		std::cout << "***" << std::setw(22) << " PLEASE RECONNECT " << "***" << std::endl;
	}
	else {
		HashNode* spt = new HashNode;
		int t_len = 0;
		char t_sym;
		while (!file->eof()) {
			//KEY
			spt->t_key = "";
			file->read((char*)&t_len, sizeof(int));
			for (int i = 0; i < t_len; i++)
			{
				file->read((char*)&t_sym, sizeof(t_sym));
				spt->t_key += t_sym;
			}

			//VALUE
			spt->t_value = "";
			file->read((char*)&t_len, sizeof(int));
			for (int i = 0; i < t_len; i++)
			{
				file->read((char*)&t_sym, sizeof(t_sym));
				spt->t_value += t_sym;
			}
			if (spt->t_key.length() < 13)
				if (!push(*spt)) std::cout << "ERROR in creating hash-table" << std::endl;
			if (count > size * resize_val)
				resize();
		}
		delete spt;
	}
	file->close();
}

HashTable::~HashTable() {
	file->open(PATH + CONFIG_FILE, std::ios::binary | std::ios::out);
	if (file->is_open())
	{
		int len;
		for (int i = 0; i < size; i++)
		{
			if (hashSet[i].t_key != "-1")
			{
				len = hashSet[i].t_key.length();
				file->write((char*)&len, sizeof(len));
				for (int j = 0; j < len; j++)
					file->write((char*)&hashSet[i].t_key[j], sizeof(hashSet[i].t_key[j]));

				len = hashSet[i].t_value.length();
				file->write((char*)&len, sizeof(len));
				for (int j = 0; j < len; j++)
					file->write((char*)&hashSet[i].t_value[j], sizeof(hashSet[i].t_value[j]));
			}
		}
	}
	file->close();
	delete file;
	delete[] hashSet;
}

int HashTable::hash(std::string _key, int _size) {
	int hashRes = 0;
	int len = _key.length();
	for (int i = 0; i < len; i++)
		hashRes += _key[i];
	return hashRes % _size;
}

bool HashTable::push(HashNode& elem) {
	int pos = hash(elem.t_key, size);
	if (hashSet[pos].t_key == "-1")
	{
		hashSet[pos] = elem;
		count++;
		return true;
	}
	else {
		int corr = 1 + hash(elem.t_key, size - 2);
		for (int i = 0; i < size; i++)
		{
			pos < 0 ? pos += size : pos -= corr;
			if (hashSet[pos].t_key == "-1")
			{
				hashSet[pos] = elem;
				count++;
				return true;
			}

		}
	}
	return false;
}

bool HashTable::pop(std::string _key) {
	int pos = find(_key);
	if (pos > -1 && pos < size)
	{
		hashSet[pos].t_key = "-1";
		return true;
	}
	else
		std::cout << "The note u want to delete does not exist" << std::endl;
	return false;
}

int HashTable::find(std::string _key) {
	int pos = hash(_key, size);
	if (hashSet[pos].t_key == _key)
		return pos;
	int corr = 1 + hash(_key, size - 2);
	for (int i = 0; i < size; i++)
	{
		pos < 0 ? pos += size : pos -= corr;
		if (hashSet[pos].t_key == _key)
			return pos;
		if (hashSet[pos].t_key == "-1")
			return -1;
	}
	return -1;
}

void HashTable::findAll()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Hash node#" << i << " :: " << hashSet[i].t_key << " -- " << hashSet[i].t_value << std::endl;
	}
}

void HashTable::resize() {
	int past_size = size;
	count = 0;
	size *= 2;
	HashNode* newHashSet = hashSet;
	hashSet = new HashNode[size];
	for (int i = 0; i < size; i++)
		hashSet[i].t_key = "-1";
	for (int i = 0; i < past_size; i++)
		if (!push(newHashSet[i])) std::cout << "ERROR in resizing hash-table" << std::endl;
	delete[] newHashSet;
}