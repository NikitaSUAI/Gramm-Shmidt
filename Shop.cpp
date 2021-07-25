//

#include "Shop.h"
#include <list>

//
// Created by nikittossii on 24.07.2021.
Shop::Shop(std::vector<Eigen::MatrixXf> *db) {
    loadDB(db);
}

void Shop::loadDB(std::vector<Eigen::MatrixXf> *db) {
    if(_database!= nullptr)
        delete _database;
    _database = db;
}

int Shop::getSolution(const Eigen::MatrixXf &instance) {
    auto instance_in_normal_basis = (instance * _orthogonalization(instance)->transpose());
    for(int i = 0; i < _database->size(); i++){
        auto *item = &_database->at(i);
        auto tmp = (*item * _orthogonalization(*item)->transpose());
        if((tmp - instance_in_normal_basis).isZero()){
            return i;
        }
    }
    return -1;
}

Eigen::MatrixXf *Shop::_orthogonalization(const Eigen::MatrixXf &instance) {
    // magic 2 set from the assumption that the plane (2d) is minimum space describing the object
    auto *basis = new  Eigen::MatrixXf(2, instance.cols());
    int row_counter = 0;
    for(int i = 0; i < instance.rows(); i++){ // n *
        if (0 == i) {
            basis->row(row_counter++) = instance.row(i); // n +
            continue;
        }
        const auto row = instance.row(i);
        basis->row(row_counter) = row;
        for(int j = 0; j < row_counter; j++){ // r * ; r <= n
            const auto basis_row = basis->row(j); // n
            basis->row(row_counter) -= basis_row * basis_row.dot(row)/basis_row.dot(basis_row); // 3n
        }
        if (!basis->row(row_counter).isZero()){ // n +
            row_counter++;
            if(row_counter == basis->rows()){ // n +
                basis->conservativeResize(row_counter+1, basis->cols()); // n*r+1; r <= n
            }
        }
    }
    basis->conservativeResize(row_counter, basis->cols());
    return basis;
}

Shop::~Shop() {
//    deleted in main
//    delete [] _database;
}

