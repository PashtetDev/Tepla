#include "FunctionsBank.h"
#include <filesystem>

using namespace std;
extern string global_path;

string get_maindir_path(string _global_path)
{
	string word;
	string maindir_path;
	for (auto c : _global_path)
	{
		word += c;
		if (c == '\\')
		{
			maindir_path += word;
			word = "";
		}
		else
		{
			if (c == '.')
				break;
		}
	}
	return maindir_path;
}

int create_dir(std::string path)
{
	return _mkdir((path).c_str());
}

int delete_dir(std::string path)
{
	return std::filesystem::remove_all((path).c_str());
}