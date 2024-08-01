#pragma once
#include <string>
#include <iostream>
#include <direct.h>

static std::string global_path;
int create_dir(std::string dir_name);
int delete_dir(std::string dir_name);
std::string get_maindir_path(std::string _global_path);