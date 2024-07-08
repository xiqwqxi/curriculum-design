#include<iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include"class.h"
#include"fun.h"
#include"data.h"



int main(void) {
	Datamap data;
	Read_data(data, file_list[0], file_list[1], file_list[2]);
	feature_matrix f_matrix;
	f_matrix.initialization_feature_matrix(Training_tags);
	f_matrix.feature_reading_data(data);
	std::cout << "A";
	double light_total_number = 0.0;
	light_total_number = f_matrix.feature_data_map["Light_Conditions"][1] + f_matrix.feature_data_map["Light_Conditions"][4] + f_matrix.feature_data_map["Light_Conditions"][5] + f_matrix.feature_data_map["Light_Conditions"][6] + f_matrix.feature_data_map["Light_Conditions"][7];
	double p_light_conditions[7] = { f_matrix.feature_data_map["Light_Conditions"][1] / light_total_number,0,0,f_matrix.feature_data_map["Light_Conditions"][4] / light_total_number ,f_matrix.feature_data_map["Light_Conditions"][5] / light_total_number ,f_matrix.feature_data_map["Light_Conditions"][6] / light_total_number ,f_matrix.feature_data_map["Light_Conditions"][7] / light_total_number };
	double weather_total_number = f_matrix.feature_data_map["Weather_Conditions"][1] + f_matrix.feature_data_map["Weather_Conditions"][2] + f_matrix.feature_data_map["Weather_Conditions"][3] + f_matrix.feature_data_map["Weather_Conditions"][4] + f_matrix.feature_data_map["Weather_Conditions"][5] + f_matrix.feature_data_map["Weather_Conditions"][6] + f_matrix.feature_data_map["Weather_Conditions"][7] + f_matrix.feature_data_map["Weather_Conditions"][8] + f_matrix.feature_data_map["Weather_Conditions"][9];
	double p_weather_conditions[9] = { f_matrix.feature_data_map["Weather_Conditions"][1] / weather_total_number, f_matrix.feature_data_map["Weather_Conditions"][2] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][3] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][4] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][5] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][6] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][7] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][8] / weather_total_number ,f_matrix.feature_data_map["Weather_Conditions"][9] / weather_total_number };
	double surface_total_number = f_matrix.feature_data_map["Road_Surface_Conditions"][1] + f_matrix.feature_data_map["Road_Surface_Conditions"][2] + f_matrix.feature_data_map["Road_Surface_Conditions"][3] + f_matrix.feature_data_map["Road_Surface_Conditions"][4] + f_matrix.feature_data_map["Road_Surface_Conditions"][5] + f_matrix.feature_data_map["Road_Surface_Conditions"][6] + f_matrix.feature_data_map["Road_Surface_Conditions"][7];
	double p_surface_conditions[7] = { f_matrix.feature_data_map["Road_Surface_Conditions"][1] / surface_total_number,f_matrix.feature_data_map["Road_Surface_Conditions"][2] / surface_total_number ,f_matrix.feature_data_map["Road_Surface_Conditions"][3] / surface_total_number ,f_matrix.feature_data_map["Road_Surface_Conditions"][4] / surface_total_number ,f_matrix.feature_data_map["Road_Surface_Conditions"][5] / surface_total_number ,f_matrix.feature_data_map["Road_Surface_Conditions"][6] / surface_total_number ,f_matrix.feature_data_map["Road_Surface_Conditions"][7] / surface_total_number };
	double speed_total_number = f_matrix.feature_data_map["Speed_Limit"][20] + f_matrix.feature_data_map["Speed_Limit"][30] + f_matrix.feature_data_map["Speed_Limit"][40] + f_matrix.feature_data_map["Speed_Limit"][50] + f_matrix.feature_data_map["Speed_Limit"][60] + f_matrix.feature_data_map["Speed_Limit"][70];
	double p_speed_limit[6] = { f_matrix.feature_data_map["Speed_Limit"][20] / speed_total_number,f_matrix.feature_data_map["Speed_Limit"][30] / speed_total_number ,f_matrix.feature_data_map["Speed_Limit"][40] / speed_total_number ,f_matrix.feature_data_map["Speed_Limit"][50] / speed_total_number ,f_matrix.feature_data_map["Speed_Limit"][60] / speed_total_number ,f_matrix.feature_data_map["Speed_Limit"][70] / speed_total_number };
	double road_total_number = f_matrix.feature_data_map["Road_Type"][1] + f_matrix.feature_data_map["Road_Type"][2] + f_matrix.feature_data_map["Road_Type"][3] + f_matrix.feature_data_map["Road_Type"][6] + f_matrix.feature_data_map["Road_Type"][7] + f_matrix.feature_data_map["Road_Type"][9];
	double p_road_type[6] = { f_matrix.feature_data_map["Road_Type"][1] / road_total_number,f_matrix.feature_data_map["Road_Type"][2] / road_total_number ,f_matrix.feature_data_map["Road_Type"][3] / road_total_number ,f_matrix.feature_data_map["Road_Type"][6] / road_total_number ,f_matrix.feature_data_map["Road_Type"][7] / road_total_number ,f_matrix.feature_data_map["Road_Type"][9] / road_total_number };
	double towing_articulation_total_number = f_matrix.feature_data_map["Towing_and_Articulation"][0] + f_matrix.feature_data_map["Towing_and_Articulation"][1] + f_matrix.feature_data_map["Towing_and_Articulation"][2] + f_matrix.feature_data_map["Towing_and_Articulation"][3] + f_matrix.feature_data_map["Towing_and_Articulation"][4] + f_matrix.feature_data_map["Towing_and_Articulation"][5];
	double p_towing_articulation[6] = { f_matrix.feature_data_map["Towing_and_Articulation"][0] / towing_articulation_total_number,f_matrix.feature_data_map["Towing_and_Articulation"][1] / towing_articulation_total_number ,f_matrix.feature_data_map["Towing_and_Articulation"][2] / towing_articulation_total_number ,f_matrix.feature_data_map["Towing_and_Articulation"][3] / towing_articulation_total_number ,f_matrix.feature_data_map["Towing_and_Articulation"][4] / towing_articulation_total_number ,f_matrix.feature_data_map["Towing_and_Articulation"][5] / towing_articulation_total_number };
	double p_tow_articulation[9][7][6][7][6][6];
	for (int wth = 0; wth < 9; wth++)
	{
		for (int sf = 0; sf < 7; sf++)
		{
			for (int rd = 0; rd < 6; rd++)
			{
				for (int lt = 0; lt < 7; lt++)
				{
					for (int spd = 0; spd < 6; spd++)
					{
						for (int t_a = 0; t_a < 6; t_a++)
						{
							p_tow_articulation[wth][sf][rd][lt][spd][t_a] = p_weather_conditions[wth] * p_surface_conditions[sf] * p_road_type[rd] * p_light_conditions[lt] * p_speed_limit[spd] * p_towing_articulation[t_a];

						}
					}
				}
			}
		}
	}
	int light = 0, weather = 0, surface = 0, speed = 0, road = 0;
	std::cout << "input light condition:";
	std::cin >> light;
	std::cout << "input weather condition:";
	std::cin >> weather;
	std::cout << "input road surface condition:";
	std::cin >> surface;
	std::cout << "input speed limit:";
	std::cin >> speed;
	std::cout << "input road type:";
	std::cin >> road;
	std::vector<double> likelihood;
	std::string type_name[6] = { "no_tow_and_articulation","articulated_vehicle","double_or_multiple_trailer","caravan","single_trailer","other_tow" };
	for (int i = 0; i < 6; i++)
	{
		likelihood.push_back(p_tow_articulation[weather - 1][surface - 1][road - 1][light - 1][(speed / 10) - 2][i]);
	}
	auto max_it = std::max_element(likelihood.begin(), likelihood.end());
	int maxValue = *max_it;
	int maxIndex = std::distance(likelihood.begin(), max_it);
	std::cout << type_name[maxIndex] << std::endl;
	//std::cout << "最大值是: " << *max_it << std::endl;
	//std::cout << "最大值的位置是：" << maxIndex << std::endl;
	//sort(likelihood.begin(), likelihood.end(), std::greater<int>());
	/*for (int i = 0; i < 6; i++)
	{
		std::cout << std::fixed <<std::setprecision(10) << likelihood[i] << "  ";
	}*/
}