cmake_minimum_required(VERSION 3.16)
project(AliceShop)

set(CMAKE_CXX_STANDARD 17)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(AliceShop src/main.cc src/core/reader.cc src/core/reader.h src/core/shop.cc src/core/shop.h src/core/gram_schmidt_matrix.cc src/core/gram_schmidt_matrix.h)
target_link_libraries (AliceShop Eigen3::Eigen)
add_subdirectory(test)