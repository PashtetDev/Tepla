#pragma once
#include <iomanip>
#include <vector>

#include "Equipment.h"
#include "FunctionsBank.h"

using namespace std;

class ListEquipment
{
public:
	string global_path;
	vector<Equipment> list_;
	void print();
	void load_data(string path);

	void eq_menu_caller(vector<int> operations, string back);

	void edit_equipment(int number, string back);
	void add_equipment(string gloabal_path);
};