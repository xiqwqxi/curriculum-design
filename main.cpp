#include<iostream>
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

}

