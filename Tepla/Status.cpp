#include "Status.h"

std::string status::status_to_string(status::Status status)
{
	switch (status)
	{
	case properly:
		return "Исправно";
	case faulty:
		return "Неисправно";
	case service:
		return "Обслуживание";
	case underRepair:
		return "В ремонте";
	case plain:
		return "Простой";
	default:
		return "NULL";
	}
}

status::Status status::string_to_status(std::string status)
{
	if (status == "Исправно")
		return properly;
	else
	{
		if (status == "Неисправно")
			return faulty;
		else
		{
			if (status == "Обслуживание")
				return service;
			else
				return status == "Простой" ? plain : underRepair;
		}
	}
}
