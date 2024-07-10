#pragma once
#include <iostream>
#include "fun.h"

void Read_data(Datamap& data, std::string source_file_Vehicles, std::string source_file_Casualties, std::string source_file_Accidents) {
    try {
        std::vector<std::string> file_list = { source_file_Vehicles, source_file_Casualties, source_file_Accidents };

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

        Vehicles tempV;
        Casualties tempC;
        Accidents tempA;
        middleclass tempM;
        std::string Acc_id_V,Acc_id_C,Acc_id_A;

        while (data_Vehicles.read_row(Acc_id_V,
            tempV.Vehicle_Reference,
            tempV.Vehicle_Type,
            tempV.Towing_and_Articulation,
            tempV.Vehicle_Manoeuvre,
            tempV.Vehicle_Location_Restricted_Lane,
            tempV.Junction_Location,
            tempV.Skidding_and_Overturning,
            tempV.Hit_Object_in_Carriageway,
            tempV.Vehicle_Leaving_Carriageway,
            tempV.Hit_Object_off_Carriageway,
            tempV.fst_Point_of_Impact,
            tempV.Was_Vehicle_Left_Hand_Drive,
            tempV.Journey_Purpose_of_Driver,
            tempV.Sex_of_Driver,
            tempV.Age_of_Driver,
            tempV.Age_Band_of_Driver,
            tempV.Engine_Capacity_CC,
            tempV.Propulsion_Code,
            tempV.Age_of_Vehicle,
            tempV.Driver_IMD_Decile,
            tempV.Driver_Home_Area_Type,
            tempV.Vehicle_IMD_Decile)&&
            data_Casualties.read_row(Acc_id_C,
            tempC.Vehicle_Reference,
            tempC.Casualty_Reference,
            tempC.Casualty_Class,
            tempC.Sex_of_Casualty,
            tempC.Age_of_Casualty,
            tempC.Age_Band_of_Casualty,
            tempC.Casualty_Severity,
            tempC.Pedestrian_Location,
            tempC.Pedestrian_Movement,
            tempC.Car_Passenger,
            tempC.Bus_or_Coach_Passenger,
            tempC.Pedestrian_Road_Maintenance_Worker,
            tempC.Casualty_Type,
            tempC.Casualty_Home_Area_Type,
            tempC.Casualty_IMD_Decile)&&
            data_Accidents.read_row(Acc_id_A,
            tempA.Location_Easting_OSGR,
            tempA.Location_Northing_OSGR,
            tempA.Longitude,
            tempA.Latitude,
            tempA.Police_Force,
            tempA.Accident_Severity,
            tempA.Number_of_Vehicles,
            tempA.Number_of_Casualties,
            tempA.Time,
            tempA.Day_of_Week,
            tempA.Date,
            tempA.Local_Authority_District,
            tempA.Local_Authority_Highway,
            tempA.fst_Road_Class,
            tempA.fst_Road_Number,
            tempA.Road_Type,
            tempA.Speed_limit,
            tempA.Junction_Detail,
            tempA.Junction_Control,
            tempA.snd_Road_Class,
            tempA.snd_Road_Number,
            tempA.Pedestrian_Crossing_Human_Control,
            tempA.Pedestrian_Crossing_Physical_Facilities,
            tempA.Light_Conditions,
            tempA.Weather_Conditions,
            tempA.Road_Surface_Conditions,
            tempA.Special_Conditions_at_Site,
            tempA.Carriageway_Hazards,
            tempA.Urban_or_Rural_Area,
            tempA.Did_Police_Officer_Attend_Scene_of_Accident,
            tempA.LSOA_of_Accident_Location))
        {
            data.data_node_map[Acc_id_A].Accident.push_back(tempA);
            data.data_node_map[Acc_id_V].Vehicle.push_back(tempV);
            data.data_node_map[Acc_id_C].Casualty.push_back(tempC);
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
