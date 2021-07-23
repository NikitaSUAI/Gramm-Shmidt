//
// Created by nikittossii on 23.07.2021.
//

#ifndef ALICESHOP_READER_H
#define ALICESHOP_READER_H
#include <string>
#include <fstream>
#include <vector>
#include <Eigen/Core>

class Reader {
private:
    std::ifstream stream;
    int segments;
    int segment_len;
    const int dimension = 3;
public:
    Reader(const std::string &filePath);
    std::vector<Eigen::MatrixXf>* readDB();
    std::vector<Eigen::MatrixXf>* readInstances();
};


#endif //ALICESHOP_READER_H
