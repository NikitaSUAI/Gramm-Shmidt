//
// Created by nikittossii on 24.07.2021.
//

#ifndef ALICESHOP_SHOP_H
#define ALICESHOP_SHOP_H

#include <vector>

#include <Eigen/Core>

// Simulates car selection by coordinates.
// Example:
//    Shop shop(database);
//    int car = shop.getSolution(coordinates_of_current_car);
//
class Shop {

private:
	std::vector<Eigen::MatrixXf> *database_=nullptr;
	Eigen::MatrixXf *GramSchmidtOrthogonalization(const Eigen::MatrixXf &instance);

public:
	Shop(std::vector<Eigen::MatrixXf> *db);
	void LoadDB(std::vector<Eigen::MatrixXf> *db);

	// Returns a number of car which corresponds to instance.
	// If the instance does not match, -1 is returned.
	// Counting begins with 0.
	int GetSolution(const Eigen::MatrixXf &instance);
	~Shop();
};


#endif //ALICESHOP_SHOP_H
