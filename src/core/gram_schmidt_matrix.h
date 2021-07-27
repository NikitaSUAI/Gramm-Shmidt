//
// Created by nikittossii on 26.07.2021.
//

#ifndef ALICESHOP_GRAM_SCHMIDT_MATRIX_H
#define ALICESHOP_GRAM_SCHMIDT_MATRIX_H

#include <vector>

#include "Eigen/Core"

// Adds storage to Eigen::MatrixXf, for frequently counted values
// in Gram-Schmidt process.
class GSMatrix : public Eigen::MatrixXf {
private:
	std::vector<Eigen::VectorXf> *storage_ = nullptr;

public:
	GSMatrix(const Eigen::Index& x, const Eigen::Index& y);
	Eigen::VectorXf SelfDotVector(const Eigen::Index& i);
	~GSMatrix();
};

// subtracts minimal element from each column
Eigen::MatrixXf* RemoveBias(const Eigen::MatrixXf & item);


#endif //ALICESHOP_GRAM_SCHMIDT_MATRIX_H
