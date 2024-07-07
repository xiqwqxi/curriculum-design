#pragma once
#ifndef BASE_CLASS_H
#define BASE_CLASS_H

#include <vector>
#include<map>
#include <string>
#include"csv.h"  //采用库fast cpp csv parser  github:https://github.com/ben-strasser/fast-cpp-csv-parser


class Vehicles {
public:
    Vehicles();
    ~Vehicles();
    short Vehicle_Reference = 0;
    short Vehicle_Type = 0;
    short Towing_and_Articulation = 0;
    short Vehicle_Manoeuvre = 0;
    short Vehicle_Location_Restricted_Lane = 0;
    short Junction_Location = 0;
    short Skidding_and_Overturning = 0;
    short Hit_Object_in_Carriageway = 0;
    short Vehicle_Leaving_Carriageway = 0;
    short Hit_Object_off_Carriageway = 0;
    short fst_Point_of_Impact = 0;
    short Was_Vehicle_Left_Hand_Drive = 0;
    short Journey_Purpose_of_Driver = 0;
    short Sex_of_Driver = 0;
    short Age_of_Driver = 0;
    short Age_Band_of_Driver = 0;
    short Engine_Capacity_CC = 0;
    short Propulsion_Code = 0;
    short Age_of_Vehicle = 0;
    short Driver_IMD_Decile = 0;
    short Driver_Home_Area_Type = 0;
    short Vehicle_IMD_Decile = 0;
};

class Casualties {
public:
    Casualties();
    ~Casualties();
    short Vehicle_Reference = 0;
    short Casualty_Reference = 0;
    short Casualty_Class = 0;
    short Sex_of_Casualty = 0;
    short Age_of_Casualty = 0;
    short Age_Band_of_Casualty = 0;
    short Casualty_Severity = 0;
    short Pedestrian_Location = 0;
    short Pedestrian_Movement = 0;
    short Car_Passenger = 0;
    short Bus_or_Coach_Passenger = 0;
    short Pedestrian_Road_Maintenance_Worker = 0;
    short Casualty_Type = 0;
    short Casualty_Home_Area_Type = 0;
    short Casualty_IMD_Decile = 0;
};

class Accidents {
public:
    Accidents();
    ~Accidents();
    int Location_Easting_OSGR = 0;
    int Location_Northing_OSGR = 0;
    double Longitude = 0.0;
    double Latitude = 0.0;
    short Police_Force = 0;
    short Local_Authority_District = 0;
    short fst_Road_Class = 0;
    int fst_Road_Number = 0;
    short Road_Type = 0;
    short Speed_limit = 0;
    short Junction_Detail = 0;
    short Junction_Control = 0;
    short snd_Road_Class = 0;
    int snd_Road_Number = 0;
    short Pedestrian_Crossing_Human_Control = 0;
    short Pedestrian_Crossing_Physical_Facilities = 0;
    short Light_Conditions = 0;
    short Weather_Conditions = 0;
    short Road_Surface_Conditions = 0;
    short Special_Conditions_at_Site = 0;
    short Carriageway_Hazards = 0;
    short Urban_or_Rural_Area = 0;
    short Did_Police_Officer_Attend_Scene_of_Accident = 0;
    short Day_of_Week = 0;
    short Accident_Severity = 0;
    short Number_of_Vehicles = 0;
    short Number_of_Casualties = 0;
    std::string Local_Authority_Highway;
    std::string LSOA_of_Accident_Location;
    std::string Time;
    std::string Date;

};

class middleclass { //一个数据节点（集合）

public:
    middleclass();
    ~middleclass();
    std::vector<Vehicles> Vehicle;
    std::vector<Accidents> Accident;
    std::vector<Casualties> Casualty;

};

class Datamap{
public:
    std::map<std::string, middleclass> data_node_map;
};

    
class feature_matrix
{
public:
    std::map<std::string, std::vector<int>> feature_data_map;;
    void feature_reading_data(Datamap& data);
    void initialization_feature_matrix(std::vector<std::string>);



};


class response_vector
{




};

#endif // BASE_CLASS_H
