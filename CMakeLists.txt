cmake_minimum_required(VERSION 3.19)
project(AliceShop)

set(CMAKE_CXX_STANDARD 17)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(AliceShop src/main.cc src/core/reader.cc src/core/reader.h src/core/shop.cc src/core/shop.h src/core/my_matrix.cc src/core/my_matrix.h)
target_link_libraries (AliceShop Eigen3::Eigen)