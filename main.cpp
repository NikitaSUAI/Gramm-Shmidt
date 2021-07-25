#include <iostream>
#include <Eigen/Core>
#include "Reader.h"
#include "Shop.h"


int main() {
    Reader r("/home/nikittossii/Documents/AliceShop/input_file.txt");
    auto v1 = r.readDB();
    auto v2 = r.readInstances();
    Shop shop(v1);
    for(auto &item : *v2){
        std::cout << "car is " << shop.getSolution(item);
    }
    delete v1;
    delete v2;
    return 0;
}
