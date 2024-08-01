#include <iostream>
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "ListEquipment.h"

using namespace std;
namespace fs = std::filesystem;

Status edit_status()
{
	string in_str;
	cout << "�������� ������:\n1. ��������\n2. ���������\n3. ������������\n4. � �������\n5. �������\n>> ";
	cin >> in_str;
	int md = atoi(in_str.c_str());
	if (md > 5 || md < 1)
		md = 1;
	return Status(md - 1);
}

void ListEquipment::print()
{
	int number = 1;
	cout << setw(7) << "N. " << " | ";
	cout << setw(20) << "�������� | ";
	cout << setw(20) << "������ | ";
	cout << setw(20) << "�������� | ";
	cout << setw(20) << "������ | " << '\n';
	for (auto e : list_)
	{
		cout << setw(5) << number++ << ". " << " | ";
		e.print_table();
		cout << "\n";
	}
	for (int i = 0; i < 18; i++)
		cout << "_____";
	cout << endl << endl;
}

void ListEquipment::load_data(string path)
{
	list_.clear();
	for (auto& temp : std::filesystem::directory_iterator(path + "Equipment\\"))
	{
		if (temp.is_directory())
		{
			string name, full_name, model, inv_number, serial_number, description, place, status;
			char buff[50];
			ifstream fin((temp.path().string() + "\\config").c_str());

			getline(fin, name);
			getline(fin, full_name);
			getline(fin, model);
			getline(fin, inv_number);
			getline(fin, serial_number);
			getline(fin, description, '&');
			getline(fin, place);
			getline(fin, place);
			getline(fin, status);

			fin.close();

			Equipment eq = Equipment(name, model, string_to_status(status), path);
			eq.description = description;
			eq.full_name = full_name;
			eq.inventory_number = inv_number;
			eq.serial_number = serial_number;
			eq.place = place;

			list_.push_back(eq);
		}
	}
}

void ListEquipment::eq_menu_caller(vector<int> operations, string back)
{
	const string equipment =
		"N. ����� �����������\n"
		"0. �������� �����\n"
		"-1. �����\n"
		"_______________\n"
		">> ";

	if (operations.size() > 2)
	{
		switch (operations[2])
		{
		case 0:
			printf("Add Equipment >> \n\n");
			add_equipment(global_path);
			printf("%s", back.c_str());
			break;
		default:
			if (operations[2] > list_.size())
			{
				printf("Page not found");
				printf("\n\n%s", back.c_str());
			}
			else
			{
				printf("Edit Equipment >> \n\n");
				edit_equipment(operations[2] - 1, back);
			}
			break;
		}
	}
	else
	{
		printf("\n\n");
		print();
		printf(equipment.c_str());
	}
}

void ListEquipment::add_equipment(string gloabal_path)
{
	string name, full_name, model, inv_number, serial_number, description, place, path;

	string str1;
	getline(cin, str1);

	cout << "��������: ";
	getline(cin, name);
	cout << "������ ��������: ";
	getline(cin, full_name);
	cout << "������: ";
	getline(cin, model);
	cout << "����������� �����: ";
	getline(cin, inv_number);
	cout << "�������� �����: ";
	getline(cin, serial_number);
	cout << "�������������� ���������� (�������������� ������� �� ����� ������, ����������� ���� �� ������� \'&\'): ";
	getline(cin, description, '&');
	getline(cin, place);
	cout << "��������: ";
	getline(cin, place);

	Status status = edit_status();

	Equipment eq = Equipment(name, model, status, gloabal_path);
	eq.description = description;
	eq.full_name = full_name;
	eq.inventory_number = inv_number;
	eq.serial_number = serial_number;
	eq.place = place;

	if (eq.save() == EXIT_SUCCESS)
	{
		list_.push_back(eq);

		cout << "\n������������ ���������\n\n";
	}
	else
		cout << "\n������ ���������� ������������\n\n";
}

void ListEquipment::edit_equipment(int number, string back)
{
	list_[number].print();
	string menu = "\n1. �������� ��������\n"
		"2. �������� ������ ������������\n"
		"3. �������� ������\n"
		"4. �������� ����������� �����\n"
		"5. �������� �������� �����\n"
		"6. �������� ��������\n"
		"7. �������� ��������\n"
		"8. �������� ������\n"
		"9. �������\n";
	printf("%s%s", menu.c_str(), back.c_str());

	string in_oper;
	cin >> in_oper;

	int operation = atoi(in_oper.c_str());

	string name = list_[number].name;
	string model = list_[number].model;
	Status status = list_[number].status;
	string full_name = list_[number].full_name;
	string inventory_number = list_[number].inventory_number;
	string serial_number = list_[number].serial_number;
	string description = list_[number].description;
	string place = list_[number].place;

	auto p = list_.begin() + number;
	list_[number].remove();
	list_.erase(p);

	string str1;
	getline(cin, str1);

	switch (operation)
	{
	case -1:
		break;
	case 1:
		cout << "\n��������: ";
		getline(cin, name);
		break;
	case 2:
		cout << "������ ��������: ";
		getline(cin, full_name);
		break;
	case 3:
		cout << "������: ";
		getline(cin, model);
		break;
	case 4:
		cout << "����������� �����: ";
		getline(cin, inventory_number);
		break;
	case 5:
		cout << "�������� �����: ";
		getline(cin, serial_number);
		break;
	case 6:
		cout << "�������������� ���������� (�������������� ������� �� ����� ������, ����������� ���� �� ������� \'&\'): ";
		getline(cin, description, '&');
		break;
	case 7:
		cout << "��������: ";
		getline(cin, place);
		break;
	case 8:
		status = edit_status();
		break;
	case 9:
		cout << "\n������������ �������\n";
		printf("\n����� �� �������\n%s", back.c_str());
		return;
	}

	Equipment new_eq = Equipment(name, model, status, global_path);
	new_eq.description = description;
	new_eq.full_name = full_name;
	new_eq.inventory_number = inventory_number;
	new_eq.serial_number = serial_number;
	new_eq.place = place;

	list_.push_back(new_eq);
	new_eq.save();

	printf("\n����� �� �������\n%s", back.c_str());
}