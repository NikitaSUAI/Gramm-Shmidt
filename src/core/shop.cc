//
// Created by nikittossii on 24.07.2021.
//
#include "shop.h"

#include <list>

#include "gram_schmidt_matrix.h"

Shop::Shop(std::vector<Eigen::MatrixXf> *db) {
	LoadDB(db);
}

void Shop::LoadDB(std::vector<Eigen::MatrixXf> *db) {
	if (database_ != nullptr)
    delete database_;
	database_ = new std::vector<Eigen::MatrixXf>(*db);
}

int Shop::GetSolution(const Eigen::MatrixXf &instance) {
	if(database_ != nullptr){
		auto newInstance = RemoveBias(instance);
		auto basis = GramSchmidtOrthogonalization(*newInstance);
    auto instance_in_normal_basis = (*newInstance * basis->transpose()).eval();
    delete newInstance;
    for (int i = 0; i < database_->size(); i++) {
    	auto *item = &database_->at(i);
			auto item_basis = GramSchmidtOrthogonalization(*item);
    	auto item_in_normal_basis = ((*item) *item_basis->transpose());
    	if (item_in_normal_basis.cols() == instance_in_normal_basis.cols()
    			&& (item_in_normal_basis - instance_in_normal_basis).isZero()) {
    		delete item_basis;
    		return i;
    	}
	    delete item_basis;
    }
    delete basis;
	}
	return -1;
}

Eigen::MatrixXf *
Shop::GramSchmidtOrthogonalization(const Eigen::MatrixXf &instance) {
	// magic 2 set from the assumption that the plane (2d)
	// is minimum space describing the object.
  auto *basis = new GSMatrix(2, instance.cols());
  int basis_row_counter = 0;
  for(int i = 0; i < instance.rows(); i++){
    if (0 == i) {
    	basis->row(basis_row_counter++) = instance.row(i);
    	continue;
    }
    const auto instance_row = instance.row(i);
    basis->row(basis_row_counter) = Eigen::VectorXf(instance_row);
    for (int j = 0; j < basis_row_counter; j++) {
    	auto basis_row = basis->row(j);
    	basis->row(basis_row_counter) -= basis_row.dot(instance_row) *
			    basis->SelfDotVector(j);
    }
    if (!basis->row(basis_row_counter).isZero()) {
    	basis_row_counter++;
    	if(basis_row_counter == basis->rows()) {
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


