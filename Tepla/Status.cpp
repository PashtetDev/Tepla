#include "Status.h"

std::string status::status_to_string(status::Status status)
{
	switch (status)
	{
	case properly:
		return "��������";
	case faulty:
		return "����������";
	case service:
		return "������������";
	case underRepair:
		return "� �������";
	case plain:
		return "�������";
	default:
		return "NULL";
	}
}

status::Status status::string_to_status(std::string status)
{
	if (status == "��������")
		return properly;
	else
	{
		if (status == "����������")
			return faulty;
		else
		{
			if (status == "������������")
				return service;
			else
				return status == "�������" ? plain : underRepair;
		}
	}
}
