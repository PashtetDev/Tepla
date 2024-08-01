#pragma once
#include <string>

namespace status
{
	enum Status
	{
		properly, //��������
		faulty, //����������
		service, //������������
		underRepair, //� �������
		plain //�������
	};

	std::string status_to_string(Status status);
	Status string_to_status(std::string status);
}