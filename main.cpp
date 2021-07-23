#include <iostream>
#include <Eigen/Core>
#include "Reader.h"

int main() {
    Reader r("/home/nikittossii/Documents/AliceShop/input_file.txt");
    auto v1 = r.readDB();
    auto v2 = r.readInstances();
    std::cout << "Database" << std::endl;
    for(auto &item : *v1){
        std::cout << item << std::endl;
    }
    std::cout << "Instance" << std::endl;
    for(auto &item : *v2){
        std::cout << item << std::endl;
    }
    return 0;
}
