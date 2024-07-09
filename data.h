#pragma once
#include <vector>
#include<map>
#include <string>

std::string file_list[] = { "Vehicles.csv","Casualties.csv","Accidents.csv","result.txt" };
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
std::vector<std::vector<std::string>> test_tags = {
	{"No tow/articulation","Articulated vehicle","Double or multiple trailer","Caravan","Single trailer","Other tow"},
	{"None","Skidded","Skidded and overturned","Jackknifed","Jackknifed and overturned","Overturned"},
	{"Fatal","Serious","Slight"}
};
int test_num = 100;
