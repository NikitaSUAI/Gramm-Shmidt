//
// Created by nikittossii on 26.07.2021.
//

#include "gram_schmidt_matrix.h"

#include <Eigen/Core>

GSMatrix::GSMatrix(const Eigen::Index &x,
                   const Eigen::Index &y) : Eigen::MatrixXf(x, y) {
	storage_ = new std::vector<Eigen::VectorXf>(x);
}

Eigen::VectorXf GSMatrix::SelfDotVector(const Eigen::Index& i){
	if(storage_ == nullptr && i == 0){
		storage_ = new std::vector<Eigen::VectorXf>(i);
	}
	if(i >= storage_->size() - 1){
		storage_->push_back(row(i) / row(i).dot(row(i)));
	}
	if(storage_->at(i).isZero()){
		storage_->at(i).resize(cols());
		storage_->at(i) = row(i) / row(i).dot(row(i));
	}
	return storage_->at(i);
}

GSMatrix::~GSMatrix() {
	delete storage_;
};
