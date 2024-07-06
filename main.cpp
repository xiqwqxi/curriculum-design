#include<iostream>
#include"class.h"
#include"fun.h"
#include"data.h"



int main(void) {
	std::vector<Data_node> data;
	light_condition light;
	Read_data(data, file_list[0], file_list[1], file_list[2], light);
	feature_matrix f_matrix;
	f_matrix.initialization(Training_tags, Tag_num);

	std::cout << "A";

}