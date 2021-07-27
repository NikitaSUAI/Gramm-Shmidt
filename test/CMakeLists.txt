cmake_minimum_required(VERSION 3.16)
project(AliceShopTest)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

#enable_testing()

include(GoogleTest)
add_executable(AliceShopTest test.cc shop_test.cc shop_test.h ../src/core/shop.cc ../src/core/reader.cc ../src/core/gram_schmidt_matrix.cc ../src/core/reader.h ../src/core/shop.h ../src/core/gram_schmidt_matrix.h)

target_link_libraries(AliceShopTest gtest gtest_main Eigen3::Eigen)
