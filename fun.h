#pragma once
#ifndef FUN_H 

#define FUN_H

#include<string>
#include<vector>
#include"class.h"

void Read_data(std::vector<Data_node>& data, std::string source_file_Vehicles, std::string source_file_Casualties, std::string source_file_Accidents, light_condition& light);

#endif
