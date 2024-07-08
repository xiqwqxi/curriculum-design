#include<iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include"class.h"
#include"fun.h"
#include"data.h"



int main(void) {
	Datamap data;
	Read_data(data, file_list[0], file_list[1], file_list[2]);
	feature_matrix f_matrix;
	f_matrix.initialization_feature_matrix(Training_tags);
	f_matrix.feature_reading_data(data);
	std::cout << "数据读取及训练矩阵初始化完成,开始写入文件"<<std::endl;
	std::ofstream outFile(file_list[3]);
	if (!outFile) {
		std::cerr << "无法打开文件" << std::endl;
		return 1;
	}
	std::streambuf* coutBuf = std::cout.rdbuf();
	std::cout.rdbuf(outFile.rdbuf());
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
	double skidding_overturning_total_number = f_matrix.feature_data_map["Skidding_and_Overturning"][0] + f_matrix.feature_data_map["Skidding_and_Overturning"][1] + f_matrix.feature_data_map["Skidding_and_Overturning"][2] + f_matrix.feature_data_map["Skidding_and_Overturning"][3] + f_matrix.feature_data_map["Skidding_and_Overturning"][4] + f_matrix.feature_data_map["Skidding_and_Overturning"][5];
	double p_skidding_overturning[6] = { f_matrix.feature_data_map["Skidding_and_Overturning"][0] / skidding_overturning_total_number,f_matrix.feature_data_map["Skidding_and_Overturning"][1] / skidding_overturning_total_number ,f_matrix.feature_data_map["Skidding_and_Overturning"][2] / skidding_overturning_total_number ,f_matrix.feature_data_map["Skidding_and_Overturning"][3] / skidding_overturning_total_number ,f_matrix.feature_data_map["Skidding_and_Overturning"][4] / skidding_overturning_total_number ,f_matrix.feature_data_map["Skidding_and_Overturning"][5] / skidding_overturning_total_number };
	double accidents_severity_total_number = f_matrix.feature_data_map["Accident_Severity"][1] + f_matrix.feature_data_map["Accident_Severity"][2] + f_matrix.feature_data_map["Accident_Severity"][3];
	double p_accidents_severity[3] = { f_matrix.feature_data_map["Accident_Severity"][1] / accidents_severity_total_number,f_matrix.feature_data_map["Accident_Severity"][2] / accidents_severity_total_number,f_matrix.feature_data_map["Accident_Severity"][3] / accidents_severity_total_number };
	double p_Accidents_severity[9][7][6][7][6][3];
	double p_tow_articulation[9][7][6][7][6][6];
	double p_skid_overturn[9][7][6][7][6][6];
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
						for (int s_o = 0; s_o < 6; s_o++)
						{
							p_skid_overturn[wth][sf][rd][lt][spd][s_o] = p_weather_conditions[wth] * p_surface_conditions[sf] * p_road_type[rd] * p_light_conditions[lt] * p_speed_limit[spd] * p_skidding_overturning[s_o];

						}
					}
				}
			}
		}
	}
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
						for (int a_s = 0; a_s<3;a_s++)
						{
							p_Accidents_severity[wth][sf][rd][lt][spd][a_s] = p_weather_conditions[wth] * p_surface_conditions[sf] * p_road_type[rd] * p_light_conditions[lt] * p_speed_limit[spd] * p_accidents_severity[a_s];
						}
					}
				}
			}
		}
	}
	auto data_map_it = data.data_node_map.begin();
	int num = 0,num1 = 0,num2 = 0,num3 = 0;
	for(size_t i = 0;i<1000;i++ )
	{

		int test_rand = rand() % 10;
		for (auto i = 0; i < test_rand; i++)
		{
			data_map_it++;
		}
		int light = data_map_it->second.Accident[0].Light_Conditions,
			weather = data_map_it->second.Accident[0].Weather_Conditions,
			surface = data_map_it->second.Accident[0].Road_Surface_Conditions, 
			speed = data_map_it->second.Accident[0].Speed_limit,
			road_type = data_map_it->second.Accident[0].Road_Type;
		if (data_map_it->second.Accident[0].Accident_Severity == -1
			||data_map_it->second.Vehicle[0].Skidding_and_Overturning == -1
			||data_map_it->second.Vehicle[0].Towing_and_Articulation == -1
			||light == -1||weather == -1
			||surface == -1||speed == -1
			||road_type == -1)
		{
		}
		else{
			num++;
			std::vector<double> towing_articulation_likelihood;
			std::vector<double> skidding_overturning_likelihood;
			std::vector<double> accidents_severity_likelihood;
			std::string t_a_type_name[6] = { "No tow/articulation","Articulated vehicle","Double or multiple trailer","Caravan","Single trailer","Other tow" };
			std::string s_o_type_name[6] = { "None","Skidded","Skidded and overturned","Jackknifed","Jackknifed and overturned","Overturned" };
			std::string a_s_type_name[3] = { "Fatal","Serious","Slight" };
			for (int i = 0; i < 6; i++)
			{
				towing_articulation_likelihood.push_back(p_tow_articulation[weather - 1][surface - 1][road_type - 1][light - 1][(speed / 10) - 2][i]);
			}
			for (int i = 0; i < 6; i++)
			{
				skidding_overturning_likelihood.push_back(p_tow_articulation[weather - 1][surface - 1][road_type - 1][light - 1][(speed / 10) - 2][i]);
			}
			for (int i = 0; i < 3; i++)
			{
				accidents_severity_likelihood.push_back(p_Accidents_severity[weather - 1][surface - 1][road_type - 1][light - 1][(speed / 10) - 2][i]);
			}
			auto t_a_max_it = std::max_element(towing_articulation_likelihood.begin(), towing_articulation_likelihood.end());
			int maxValue = *t_a_max_it;
			int maxIndex = std::distance(towing_articulation_likelihood.begin(), t_a_max_it);
			std::cout<< "数据所对应的acc_id为" <<data_map_it->first<< std::endl;
			std::cout << "预测的结果是：" << t_a_type_name[maxIndex] << std::endl << "原数据的结果是：" << test_tags[0][data_map_it->second.Vehicle[0].Towing_and_Articulation] << std::endl;
			if (t_a_type_name[maxIndex] == test_tags[0][data_map_it->second.Vehicle[0].Towing_and_Articulation])
			{
				num1++;
			}
			auto s_o_max_it = std::max_element(skidding_overturning_likelihood.begin(), skidding_overturning_likelihood.end());
			maxValue = *s_o_max_it;
			maxIndex = std::distance(skidding_overturning_likelihood.begin(), s_o_max_it);
			std::cout << "预测的结果是：" << s_o_type_name[maxIndex] << std::endl << "原数据的结果是：" << test_tags[1][data_map_it->second.Vehicle[0].Skidding_and_Overturning] << std::endl;
			if (s_o_type_name[maxIndex] == test_tags[1][data_map_it->second.Vehicle[0].Skidding_and_Overturning])
			{
				num2++;
			}
			auto a_s_max_it = std::max_element(accidents_severity_likelihood.begin(), accidents_severity_likelihood.end());
			maxValue = *a_s_max_it;
			maxIndex = std::distance(accidents_severity_likelihood.begin(), a_s_max_it);
			std::cout << "预测的结果是：" << a_s_type_name[maxIndex] << std::endl << "原数据的结果是：" << test_tags[2][data_map_it->second.Accident[0].Accident_Severity - 1 ] << std::endl<<std::endl;
			if (a_s_type_name[maxIndex] == test_tags[2][data_map_it->second.Accident[0].Accident_Severity - 1])
			{
				num3++;
			}
		}
	}

	std::cout.rdbuf(coutBuf);

	outFile.close();

	std::cout << "文件写入完成。" << std::endl;

	double accuracy = (double)(num1 + num2 + num3) / (double)(num * 3);
	std::cout <<"共预测"<<num<<"条数据"<<std::endl << "预测的准确率为：" << accuracy << std::endl;

	
}