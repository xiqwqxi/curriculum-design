#pragma once
#include <iostream>
#include "fun.h"

void Read_data(std::vector<Data_node>& data, std::string source_file_Vehicles, std::string source_file_Casualties, std::string source_file_Accidents, light_condition& light) {
    try {
        std::vector<std::string> file_list = { source_file_Vehicles, source_file_Casualties, source_file_Accidents };

        long long a = 0;
        io::CSVReader<23> data_Vehicles(file_list[0]);
        io::CSVReader<16> data_Casualties(file_list[1]);
        io::CSVReader<32> data_Accidents(file_list[2]);


        data_Vehicles.read_header(io::ignore_extra_column,
            "Accident_Index",
            "Vehicle_Reference",
            "Vehicle_Type",
            "Towing_and_Articulation",
            "Vehicle_Manoeuvre",
            "Vehicle_Location-Restricted_Lane",
            "Junction_Location",
            "Skidding_and_Overturning",
            "Hit_Object_in_Carriageway",
            "Vehicle_Leaving_Carriageway",
            "Hit_Object_off_Carriageway",
            "1st_Point_of_Impact",
            "Was_Vehicle_Left_Hand_Drive?",
            "Journey_Purpose_of_Driver",
            "Sex_of_Driver",
            "Age_of_Driver",
            "Age_Band_of_Driver",
            "Engine_Capacity_(CC)",
            "Propulsion_Code",
            "Age_of_Vehicle",
            "Driver_IMD_Decile",
            "Driver_Home_Area_Type",
            "Vehicle_IMD_Decile"
        );

        data_Casualties.read_header(io::ignore_extra_column,
            "Accident_Index",
            "Vehicle_Reference",
            "Casualty_Reference",
            "Casualty_Class",
            "Sex_of_Casualty",
            "Age_of_Casualty",
            "Age_Band_of_Casualty",
            "Casualty_Severity",
            "Pedestrian_Location",
            "Pedestrian_Movement",
            "Car_Passenger",
            "Bus_or_Coach_Passenger",
            "Pedestrian_Road_Maintenance_Worker",
            "Casualty_Type",
            "Casualty_Home_Area_Type",
            "Casualty_IMD_Decile"
        );

        data_Accidents.read_header(io::ignore_extra_column,
            "Accident_Index",
            "Location_Easting_OSGR",
            "Location_Northing_OSGR",
            "Longitude",
            "Latitude",
            "Police_Force",
            "Accident_Severity",
            "Number_of_Vehicles",
            "Number_of_Casualties",
            "Time",
            "Day_of_Week",
            "Date",
            "Local_Authority_(District)",
            "Local_Authority_(Highway)",
            "1st_Road_Class",
            "1st_Road_Number",
            "Road_Type",
            "Speed_limit",
            "Junction_Detail",
            "Junction_Control",
            "2nd_Road_Class",
            "2nd_Road_Number",
            "Pedestrian_Crossing-Human_Control",
            "Pedestrian_Crossing-Physical_Facilities",
            "Light_Conditions",
            "Weather_Conditions",
            "Road_Surface_Conditions",
            "Special_Conditions_at_Site",
            "Carriageway_Hazards",
            "Urban_or_Rural_Area",
            "Did_Police_Officer_Attend_Scene_of_Accident",
            "LSOA_of_Accident_Location"
        );

        Vehicles temp_V;
        Casualties temp_C;
        Accidents temp_A;
        Data_node temp_D;
        std::string Acc_id;

        while (data_Vehicles.read_row(Acc_id,
            temp_V.Vehicle_Reference,
            temp_V.Vehicle_Type,
            temp_V.Towing_and_Articulation,
            temp_V.Vehicle_Manoeuvre,
            temp_V.Vehicle_Location_Restricted_Lane,
            temp_V.Junction_Location,
            temp_V.Skidding_and_Overturning,
            temp_V.Hit_Object_in_Carriageway,
            temp_V.Vehicle_Leaving_Carriageway,
            temp_V.Hit_Object_off_Carriageway,
            temp_V.fst_Point_of_Impact,
            temp_V.Was_Vehicle_Left_Hand_Drive,
            temp_V.Journey_Purpose_of_Driver,
            temp_V.Sex_of_Driver,
            temp_V.Age_of_Driver,
            temp_V.Age_Band_of_Driver,
            temp_V.Engine_Capacity_CC,
            temp_V.Propulsion_Code,
            temp_V.Age_of_Vehicle,
            temp_V.Driver_IMD_Decile,
            temp_V.Driver_Home_Area_Type,
            temp_V.Vehicle_IMD_Decile))
        {
            if (temp_D.Vehicle.empty()) {
                temp_D.Vehicle.push_back(temp_V);
                temp_D.Accident_Index = Acc_id;
            }
            else {
                if (temp_D.Accident_Index == Acc_id)
                {
                    temp_D.Vehicle.push_back(temp_V);
                    temp_D.Accident_Index = Acc_id;
                }
                else
                {
                    data.push_back(temp_D);
                    temp_D = Data_node();
                    temp_D.Vehicle.push_back(temp_V);
                    temp_D.Accident_Index = Acc_id;
                }
            }
        }

        if (!temp_D.Vehicle.empty()) {
            data.push_back(temp_D);
            temp_D = Data_node();
        }

        while (data_Casualties.read_row(Acc_id,
            temp_C.Vehicle_Reference,
            temp_C.Casualty_Reference,
            temp_C.Casualty_Class,
            temp_C.Sex_of_Casualty,
            temp_C.Age_of_Casualty,
            temp_C.Age_Band_of_Casualty,
            temp_C.Casualty_Severity,
            temp_C.Pedestrian_Location,
            temp_C.Pedestrian_Movement,
            temp_C.Car_Passenger,
            temp_C.Bus_or_Coach_Passenger,
            temp_C.Pedestrian_Road_Maintenance_Worker,
            temp_C.Casualty_Type,
            temp_C.Casualty_Home_Area_Type,
            temp_C.Casualty_IMD_Decile))
        {
            if (temp_D.Casualty.empty()) {
                temp_D.Casualty.push_back(temp_C);
                temp_D.Accident_Index = Acc_id;
            }
            else {
                if (temp_D.Accident_Index == Acc_id)
                {
                    temp_D.Casualty.push_back(temp_C);
                    temp_D.Accident_Index = Acc_id;
                }
                else
                {
                    data.push_back(temp_D);
                    temp_D = Data_node();
                    temp_D.Casualty.push_back(temp_C);
                    temp_D.Accident_Index = Acc_id;
                }
            }
        }

        if (!temp_D.Casualty.empty()) {
            data.push_back(temp_D);
            temp_D = Data_node();
        }


        while (data_Accidents.read_row(Acc_id,
            temp_A.Location_Easting_OSGR,
            temp_A.Location_Northing_OSGR,
            temp_A.Longitude,
            temp_A.Latitude,
            temp_A.Police_Force,
            temp_A.Accident_Severity,
            temp_A.Number_of_Vehicles,
            temp_A.Number_of_Casualties,
            temp_A.Time,
            temp_A.Day_of_Week,
            temp_A.Date,
            temp_A.Local_Authority_District,
            temp_A.Local_Authority_Highway,
            temp_A.fst_Road_Class,
            temp_A.fst_Road_Number,
            temp_A.Road_Type,
            temp_A.Speed_limit,
            temp_A.Junction_Detail,
            temp_A.Junction_Control,
            temp_A.snd_Road_Class,
            temp_A.snd_Road_Number,
            temp_A.Pedestrian_Crossing_Human_Control,
            temp_A.Pedestrian_Crossing_Physical_Facilities,
            temp_A.Light_Conditions,
            temp_A.Weather_Conditions,
            temp_A.Road_Surface_Conditions,
            temp_A.Special_Conditions_at_Site,
            temp_A.Carriageway_Hazards,
            temp_A.Urban_or_Rural_Area,
            temp_A.Did_Police_Officer_Attend_Scene_of_Accident,
            temp_A.LSOA_of_Accident_Location))
        {
            light.read(temp_A);
            //std::cout << light.total_number<<std::endl;
            if (temp_D.Accident.empty()) {
                temp_D.Accident.push_back(temp_A);
                temp_D.Accident_Index = Acc_id;
            }
            else {
                if (temp_D.Accident_Index == Acc_id)
                {
                    temp_D.Accident.push_back(temp_A);
                    temp_D.Accident_Index = Acc_id;
                }
                else
                {
                    data.push_back(temp_D);
                    temp_D = Data_node();
                    temp_D.Accident.push_back(temp_A);
                    temp_D.Accident_Index = Acc_id;
                }
            }
        }

        if (!temp_D.Accident.empty()) {
            data.push_back(temp_D);
        }

    }
    catch (const io::error::base& err) {
        std::cerr << "CSV error: " << err.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Standard exception: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred!" << std::endl;
    }
}
