//
// Created by nikittossii on 26.07.2021.
//

#ifndef ALICESHOP_SHOP_TEST_H
#define ALICESHOP_SHOP_TEST_H

#include <vector>
#include <string>

#include <Eigen/Core>
#include <gtest/gtest.h>

class ShopTest : public ::testing::Test{

public:
	std::vector<Eigen::MatrixXf> *database_ = nullptr;
	std::vector<Eigen::MatrixXf> *transformations_ = nullptr;
	std::vector<Eigen::MatrixXf> *bias_ = nullptr;
	std::vector<Eigen::MatrixXf> *other_car_ = nullptr;

	std::string db_file_name_ = "/home/nikittossii/Documents/AliceShop/test/instances/database.txt";
	std::string transform_fn_ = "/home/nikittossii/Documents/AliceShop/test/instances/transforms.txt";
	std::string bias_fn_ = "/home/nikittossii/Documents/AliceShop/test/instances/bias.txt";

protected:
	void SetUp();
	void TearDown();
};


#endif //ALICESHOP_SHOP_TEST_H
