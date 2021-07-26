//
// Created by nikittossii on 24.07.2021.
//

#include "shop.h"

#include <list>

Shop::Shop(std::vector<Eigen::MatrixXf> *db) {
	LoadDB(db);
}

void Shop::LoadDB(std::vector<Eigen::MatrixXf> *db) {
	if(database_ != nullptr)
    delete database_;
	database_ = new std::vector<Eigen::MatrixXf>(*db);
}

int Shop::GetSolution(const Eigen::MatrixXf &instance) {
	if(database_ != nullptr){
    auto instance_in_normal_basis = instance
    		* GramSchmidtOrthogonalization(instance)->transpose();
    for(int i = 0; i < database_->size(); i++){
    	auto *item = &database_->at(i);
    	auto item_in_normal_basis = ((*item) *
    			GramSchmidtOrthogonalization(*item)->transpose());
    	if((item_in_normal_basis - instance_in_normal_basis).isZero()){
    		return i;
    	}
    }
	}
	return -1;
}

Eigen::MatrixXf *
Shop::GramSchmidtOrthogonalization(const Eigen::MatrixXf &instance) {
	// magic 2 set from the assumption that the plane (2d)
	// is minimum space describing the object.
  auto *basis = new  Eigen::MatrixXf(2, instance.cols());
  int basis_row_counter = 0;
  for(int i = 0; i < instance.rows(); i++){
    if (0 == i) {
    	basis->row(basis_row_counter++) = instance.row(i);
    	continue;
    }
    const auto instance_row = instance.row(i);
    basis->row(basis_row_counter) = instance_row;
    for(int j = 0; j < basis_row_counter; j++){
    	const auto basis_row = basis->row(j);
    	basis->row(basis_row_counter) -= basis_row *
    			basis_row.dot(instance_row) / basis_row.dot(basis_row);
    }
    if (!basis->row(basis_row_counter).isZero()){
    	basis_row_counter++;
    	if(basis_row_counter == basis->rows()){
    		basis->conservativeResize(basis_row_counter + 1,
																	basis->cols());
    	}
    }
  }
  basis->conservativeResize(basis_row_counter, basis->cols());
  return basis;
}

Shop::~Shop() {
	delete database_;
}


