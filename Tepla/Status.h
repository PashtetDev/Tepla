#pragma once
#include <string>

namespace status
{
	enum Status
	{
		properly, //Исправно
		faulty, //Неисправно
		service, //Обслуживание
		underRepair, //В ремонте
		plain //Простой
	};

	std::string status_to_string(Status status);
	Status string_to_status(std::string status);
}