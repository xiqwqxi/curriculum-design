#pragma once
#include"class.h"
#include "fun.h"
#include <iostream>
Casualties::Casualties() {}

Casualties::~Casualties() {}


Vehicles::Vehicles() {}

Vehicles::~Vehicles() {}


Accidents::Accidents() {}

Accidents::~Accidents() {}


Data_node::Data_node() {}

Data_node::~Data_node() {}





void light_condition::read(Accidents temp_A)
{
	if (temp_A.Light_Conditions == 1)
	{
		daylight++;
		total_number++;
	}
	else if (temp_A.Light_Conditions == 4)
	{
		light_lit++;
		total_number++;
	}
	else if (temp_A.Light_Conditions == 5)
	{
		light_unlit++;
		total_number++;
	}
	else if (temp_A.Light_Conditions == 6)
	{
		no_lighting++;
		total_number++;
	}

}
void light_condition::print_type(int type_number)
{
	std::cout << Light_condition[type_number] << "  ";
}
void light_condition::plight()
{
	light.push_back(daylight / total_number);
	light.push_back(light_lit / total_number);
	light.push_back(light_unlit / total_number);
	light.push_back(no_lighting / total_number);
}




void feature_matrix::initialization(std::vector<std::string> str, std::vector<std::vector<short>> num)
{
	while (!str.empty())
	{

	}
}

void feature_matrix::Reading_data(std::vector<Data_node>& data)
{
	for (int i = 0; i < data.size(); i++)
	{

	}
}