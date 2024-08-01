#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

#include "ListEquipment.h"

using namespace std;
ListEquipment LE;
extern string global_path;

class Menu
{
public:
	void print(vector<int> operations)
	{
		cout << "Отладочная информация (навигация): ";

		for (auto i : operations)
			cout << i << " ";
		cout << endl;

		printf("Menu >> ");
				
		if (operations.size() > 1)
		{
			switch (operations[1])
			{
			case 1:
				printf("Equipment >> ");
				LE.eq_menu_caller(operations, back);
				break;
			case 2:
				printf("Order >> ");
				if (operations.size() > 2)
				{
					printf("Page not found");
					printf("\n\n%s", back.c_str());
				}
				else
				{
					printf("\n\n");
					printf(order.c_str());
				}
				break;
			default:
				printf("Page not found");
				printf("\n\n%s", back.c_str());
				break;
			}
		}
		else
		{
			printf("\n\n");
			printf(main.c_str());
		}
	}
private:
	const string main =
		"1. Оборудование\n"
		"2. Заявки\n"
		"-1. Выход\n"
		"_______________\n"
		">> ";
	const string order =
		"Этот раздел находится в разработке. Приходите позже\n"
		"-1. Назад\n"
		"_______________\n"
		">> ";
	const string back =
		"-1. Назад\n"
		"_______________\n"
		">> ";
};

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Menu menu;

	global_path = get_maindir_path(argv[0]);
	LE.global_path = global_path;
	//cout << global_path << endl;

	if (create_dir(global_path+"Equipment") == EXIT_SUCCESS)
	{
		cout << "Папка Equipment и база данных не обнаруженны\n";
	}

	/*int count = rand() % 10 + 4;
	for (int i = 0; i < count; i++)
	{
		Equipment temp = Equipment("machine" + to_string(rand() % 10000), "model-" + to_string(rand() % 100), properly, global_path);
		temp.save();
		LE.list_.push_back(temp);
	}
	LE.print();*/
	LE.load_data(global_path);

	vector<int> operations;
	operations.push_back(0);
	do
	{
		menu.print(operations);

		string in_oper;
		cin >> in_oper;

		int new_oper = atoi(in_oper.c_str());

		if (new_oper == -1 && !operations.empty())
			operations.pop_back();
		else
			operations.push_back(new_oper);

		system("cls");
	} while (!operations.empty());

	return EXIT_SUCCESS;
}