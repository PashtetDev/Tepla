#pragma once
#include <string>
#include <iostream>

#include "Status.h"

using namespace std;
using namespace status;

class Equipment
{
public:
	string name;
	string full_name;
	string model;
	string inventory_number;
	string serial_number;
	string description;
	string place;
	Status status;


	Equipment(string name, string model, Status status, string global_path);

	void print_table();

	void print();

	int save();

	int remove();

	void set_path(string global_path);
private:
	string config_path;
	string dir_path;
};