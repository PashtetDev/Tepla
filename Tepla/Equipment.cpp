#pragma warning(disable : 4996)
#include <iomanip>

#include "Equipment.h"
#include "FunctionsBank.h"

Equipment::Equipment(string name, string model, Status status, string global_path)
{
	this->name = name;
	this->model = model;
	this->status = status;
	set_path(global_path);
}

void Equipment::print_table()
{
	cout << setw(20) << name + " | ";
	cout << setw(20) << model + " | ";
	cout << setw(20) << place + " | ";
	cout << setw(20) << status_to_string(this->status) + " | ";
}

void Equipment::print()
{
	cout.width(10);
	cout << "Название: " << name << "\n";
	cout << "Полное наименование: " << full_name << "\n";
	cout << "Модель: " << model << "\n";
	cout << "Инвентарный номер: " << inventory_number << "\n";
	cout << "Серийный номер: " << serial_number << "\n";
	cout << "Описание:\n" << description << "\n";
	cout << "Площадка: " << place << "\n";
	cout << "Статус: " << status_to_string(this->status) << "\n";
}

int Equipment::save()
{
	if (create_dir(dir_path) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}
	else
	{
		FILE* file = fopen(config_path.c_str(), "w+");
		string data = name + '\n'
			+ full_name + "\n"
			+ model + '\n'
			+ inventory_number + '\n'
			+ serial_number + '\n'
			+ description + "&\n"
			+ place + '\n'
			+ status_to_string(this->status);
		fprintf(file, data.c_str());
		fclose(file);

		return EXIT_SUCCESS;
	}
}

int Equipment::remove()
{
	return delete_dir(dir_path);
}

void Equipment::set_path(string global_path)
{
	dir_path = global_path + "Equipment\\" + name;
	config_path = dir_path + "\\config";
}