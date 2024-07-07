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


middleclass::middleclass() {}

middleclass::~middleclass() {}









void feature_matrix::initialization_feature_matrix(std::vector<std::string> str)
{
	for (int i = 0; i < str.size(); i++)
	{
		std::vector<int> temp(100);
		feature_data_map.insert(std::pair<std::string, std::vector<int>>(str[i], temp));
	}
}

void feature_matrix::feature_reading_data(Datamap& data)  //读取datanode的数据并且抛弃-1异常值；
{
	for (auto data_iterater = data.data_node_map.begin(); data_iterater != data.data_node_map.end(); data_iterater++)
	{
		/*1*/for (size_t data_vehicles_counter = 0; data_vehicles_counter < data_iterater->second.Vehicle.size(); data_vehicles_counter++)
		{
			if (data_iterater->second.Vehicle[data_vehicles_counter].Vehicle_Type != -1)
			{
				feature_data_map["Vehicle_Type"][data_iterater->second.Vehicle[data_vehicles_counter].Vehicle_Type]++;
			}
			if (data_iterater->second.Vehicle[data_vehicles_counter].Towing_and_Articulation != -1)
			{
				feature_data_map["Towing_and_Articulation"][data_iterater->second.Vehicle[data_vehicles_counter].Towing_and_Articulation]++;
			}
			if (data_iterater->second.Vehicle[data_vehicles_counter].Age_Band_of_Driver != -1)
			{
				feature_data_map["Age_Band"][data_iterater->second.Vehicle[data_vehicles_counter].Age_Band_of_Driver]++;
			}
		}
		//for (size_t data_casualties_counter = 0; data_casualties_counter < data_iterater->second.Casualty.size(); data_casualties_counter++)
		//{

		//}
		/*2*/for (size_t data_accidents_counter = 0; data_accidents_counter < data_iterater->second.Accident.size(); data_accidents_counter++)
		{
			if (data_iterater->second.Accident[data_accidents_counter].Speed_limit != -1)
			{
				feature_data_map["Speed_limit"][data_iterater->second.Accident[data_accidents_counter].Speed_limit]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Road_Type != -1)
			{
				feature_data_map["Road_Type"][data_iterater->second.Accident[data_accidents_counter].Road_Type]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Junction_Detail != -1)
			{
				feature_data_map["Junction_Detail"][data_iterater->second.Accident[data_accidents_counter].Junction_Detail]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Junction_Control != -1)
			{
				feature_data_map["Junction_Control"][data_iterater->second.Accident[data_accidents_counter].Junction_Control]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Urban_or_Rural_Area != -1)
			{
				feature_data_map["Urban_or_Rural_Area"][data_iterater->second.Accident[data_accidents_counter].Urban_or_Rural_Area]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Light_Conditions != -1)
			{
				feature_data_map["Light_Conditions"][data_iterater->second.Accident[data_accidents_counter].Light_Conditions]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Weather_Conditions != -1)
			{
				feature_data_map["Weather_Conditions"][data_iterater->second.Accident[data_accidents_counter].Weather_Conditions]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Road_Surface_Conditions != -1)
			{
				feature_data_map["Road_Surface_Conditions"][data_iterater->second.Accident[data_accidents_counter].Road_Surface_Conditions]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Special_Conditions_at_Site != -1)
			{
				feature_data_map["Special_Conditions_at_Site"][data_iterater->second.Accident[data_accidents_counter].Special_Conditions_at_Site]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Carriageway_Hazards != -1)
			{
				feature_data_map["Carriageway_Hazards"][data_iterater->second.Accident[data_accidents_counter].Carriageway_Hazards]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Pedestrian_Crossing_Human_Control != -1)
			{
				feature_data_map["Pedestrian_Crossing_Human_Control"][data_iterater->second.Accident[data_accidents_counter].Pedestrian_Crossing_Human_Control]++;
			}
			if (data_iterater->second.Accident[data_accidents_counter].Pedestrian_Crossing_Physical_Facilities != -1)
			{
				feature_data_map["Pedestrian_Crossing_Physical_Facilities"][data_iterater->second.Accident[data_accidents_counter].Pedestrian_Crossing_Physical_Facilities]++;
			}

		}
	}
}