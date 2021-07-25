//
// Created by nikittossii on 24.07.2021.
//

#ifndef ALICESHOP_SHOP_H
#define ALICESHOP_SHOP_H
#include <vector>
#include <Eigen/Core>

class Shop {
private:
    std::vector<Eigen::MatrixXf> *_database = nullptr;
    Eigen::MatrixXf *_orthogonalization(const Eigen::MatrixXf &instance);
public:
    Shop(std::vector<Eigen::MatrixXf> *db=nullptr);
    void loadDB(std::vector<Eigen::MatrixXf> *db);
    int getSolution(const Eigen::MatrixXf &instance);
    ~Shop();
};


#endif //ALICESHOP_SHOP_H
