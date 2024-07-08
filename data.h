#pragma once
#include <vector>
#include<map>
#include <string>

std::string file_list[3] = { "Vehicles.csv","Casualties.csv","Accidents.csv" };
std::vector<std::string> Training_tags =
{
	"Speed_Limit",
	"Road_Type",
	"Junction_Detail",
	"Junction_Control",
	"Pedestrian_Crossing_Human_Control",
	"Pedestrian_Crossing_Physical_Facilities",
	"Light_Conditions",
	"Weather_Conditions",
	"Road_Surface_Conditions",
	"Special_Conditions_at_Site",
	"Carriageway_Hazards",
	"Urban_or_Rural_Area",
	"Vehicle_Type",
	"Towing_and_Articulation",
	"Age_Band",
	"Accident_Severity",
	"Casualty_Severity",
	"Skidding_and_Overturning"
};
std::vector<std::vector<short>> Tag_num =
{
	{20,30,40,50,60,70},
	{1,2,3,6,7,9,12},
	{0,1,2,3,5,6,7,8,9},
	{0,1,2,3,4},  //J_C
	{0,1,2},
	{0,1,4,5,7,8},
	{1,4,5,6,7},
	{1,2,3,4,5,6,7,8,9},//weather
	{1,2,3,4,5,6,7},
	{0,1,2,3,4,5,6,7},
	{0,1,2,3,4,5,6,7},
	{1,2},
	{1,2,3,4,5,8,9,10,11,16,17,18,19,20,21,22,23,90,97,98},//V_T
	{0,1,2,3,4,5},
	{1,2,3,4,5,6,7,8,9,10,11}//age
};

