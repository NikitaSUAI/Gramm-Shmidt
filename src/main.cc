//
// Created by nikittossii on 24.07.2021.
//

#include <iostream>

#include "core/reader.h"
#include "core/shop.h"


int main() {
	Reader r("/home/nikittossii/Documents/AliceShop/input_file.txt");
	auto v1 = r.ReadDB();
	auto v2 = r.ReadInstances();
	Shop shop(v1);
	for(auto &item : *v2){
		std::cout << "car is " << shop.GetSolution(item);
	}
	delete v1;
	delete v2;
	return 0;
}
