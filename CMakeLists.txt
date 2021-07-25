cmake_minimum_required(VERSION 3.19)
project(AliceShop)

set(CMAKE_CXX_STANDARD 17)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(AliceShop main.cpp Reader.cpp Reader.h Shop.cpp Shop.h)
target_link_libraries (AliceShop Eigen3::Eigen)