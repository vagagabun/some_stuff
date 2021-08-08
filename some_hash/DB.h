#ifndef DB_H_INCLUDED
#define DB_H_INCLUDED
#include "Hash.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
class DB
{
private:
	 std::vector<Hash> objects{};
	//void push(const Hash &hash);
public:
	DB();
	DB(string filename);
	void reg();
	void enter();
	void push(const Hash &hash);
	void recover();
	void show_DB();
	void save_file(string filename);
	void load_file(string filename);
};
#endif // DB_H_INCLUDED
