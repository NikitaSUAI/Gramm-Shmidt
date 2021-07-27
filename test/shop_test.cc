//
// Created by nikittossii on 26.07.2021.
//
#include "shop_test.h"

#include "../src/core/shop.h"
#include "../src/core/reader.h"

void ShopTest::SetUp() {
	Reader r(db_file_name_);
	database_ = r.ReadDB();

	other_car_ = r.ReadInstances();

	r.open(transform_fn_);
	transformations_ = r.ReadDB();

	r.open(bias_fn_);
	bias_ = r.ReadDB();
}

void ShopTest::TearDown() {
	delete database_;
	delete transformations_;
	delete bias_;
}

TEST_F(ShopTest, Transformation) {
	int num_of_car = 0;
	Shop s(database_);
	for( auto &item : *database_) {
		for (auto &transform : *transformations_) {
			ASSERT_EQ(num_of_car, s.GetSolution((transform * item.transpose())
										.transpose().eval()))
										<< "Matrix \n" << item << "\n not equal to " <<
										num_of_car <<" car, with transform \n" <<  transform <<"\n";
		}
		num_of_car++;
	}
}

TEST_F(ShopTest, Bias){
	Shop s(database_);
	int num_of_car = 0;
	for( auto &item : *database_) {
		for (auto &bias : *bias_) {
			ASSERT_EQ(num_of_car, s.GetSolution(item + bias))
										<< "Matrix \n" << item << "\n not equal to " <<
										num_of_car <<" car, where bias is \n" << bias << std::endl;
		}
		num_of_car++;
	}
}

TEST_F(ShopTest, BiasTransform) {
	Shop s(database_);
	int num_of_car = 0;
	for( auto &item : *database_) {
		for (auto &bias : *bias_) {
			for (auto &transform : *transformations_) {
				ASSERT_EQ(num_of_car, s.GetSolution(item * transform + bias))
											<< "Matrix \n" << item << "\n not equal to " <<
											num_of_car <<" car, with bias\n" << bias <<
											"\nand transform \n" << transform << std::endl;
			}
		}
		num_of_car++;
	}
}

TEST_F(ShopTest, OtherCar){
	Shop s(database_);
	const int num_of_car = -1;
	for( auto &item : *other_car_) {
		for (auto &transform : *transformations_) {
			ASSERT_EQ(num_of_car, s.GetSolution((transform * item.transpose())
					                                    .transpose().eval()))
										<< "Matrix \n" << item << "\n not equal to " <<
										num_of_car <<" car, with transform \n" <<  transform <<"\n";
		}
		for (auto &bias : *bias_) {
			ASSERT_EQ(num_of_car, s.GetSolution(item + bias))
										<< "Matrix \n" << item << "\n not equal to " <<
										num_of_car << " car, where bias is \n" << bias << std::endl;
		}
		for (auto &bias : *bias_) {
			for (auto &transform : *transformations_) {
				ASSERT_EQ(num_of_car, s.GetSolution(item * transform + bias))
											<< "Matrix \n" << item << "\n not equal to " <<
											num_of_car <<" car, with bias\n" << bias <<
											"\nand transform \n" << transform << std::endl;
			}
		}
	}
}