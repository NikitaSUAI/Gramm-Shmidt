//
// Created by nikittossii on 24.07.2021.
//
#include <iostream>

#include "core/reader.h"
#include "core/shop.h"


int main(int argc, char** argv) {
	std::string file_path = "../input_file.txt";
	if(2 == argc){
		file_path = argv[1];
	}
	Reader r(file_path);
	auto v1 = r.ReadDB();
	auto v2 = r.ReadInstances();
	Shop shop(v1);
	for (auto &item : *v2) {
		std::cout << "car is " << shop.GetSolution(item) << std::endl;
	}
	delete v1;
	delete v2;
	return 0;
}
