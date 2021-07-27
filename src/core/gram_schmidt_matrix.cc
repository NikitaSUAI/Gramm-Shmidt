//#include <iostream>
// Created by nikittossii on 26.07.2021.
//
#include "gram_schmidt_matrix.h"

#include <Eigen/Core>

GSMatrix::GSMatrix(const Eigen::Index& x, const Eigen::Index& y): Eigen::MatrixXf(x, y) {
	storage_ = new std::vector<Eigen::VectorXf>(x);
};

Eigen::VectorXf GSMatrix::SelfDotVector(const Eigen::Index& i){
	if (i >= storage_->size()){
		storage_->resize(i+1);
	}
	if (storage_->at(i).isZero()) {
		storage_->at(i) = row(i) / row(i).dot(row(i));
	}
	return storage_->at(i);
}

GSMatrix::~GSMatrix() {
	delete storage_;
}

Eigen::MatrixXf* RemoveBias(const Eigen::MatrixXf& item) {
	auto *result = new Eigen::MatrixXf(item);
	for (int i = 0; i < item.cols(); i++) {
		Eigen::VectorXf tmp = item.col(i);
	  float min = item.col(i).minCoeff();
		if (min == 0) {
			continue;
		}
		for (int j = 0; j  < item.rows(); j++) {
			tmp[j] -= min;
		}
		result->col(i) = tmp;
	}
	return result;
};
