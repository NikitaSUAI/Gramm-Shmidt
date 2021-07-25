//
// Created by nikittossii on 23.07.2021.
//

#include "Reader.h"

Reader::Reader(const std::string &filePath) {
    stream.open(filePath);
    if(!stream.is_open()){
        throw 0;
    }
}

std::vector<Eigen::MatrixXf>* Reader::readDB(){
    if(!stream.is_open()){
        throw 0;// delete this!!!!
    }
    stream >> segments >> segment_len;
    std::vector<Eigen::MatrixXf> *result = new std::vector<Eigen::MatrixXf>(segments);
    for(int i = 0; i < segments; i++){
        Eigen::MatrixXf segment(segment_len, dimension);
        for(int j = 0; j < segment_len; j++){
            for(int d = 0; d < dimension; d++)
                stream >> segment(j, d);
        }
        (*result)[i] = segment;
    }
    return result;
}

std::vector<Eigen::MatrixXf>* Reader::readInstances() {
    if(!stream.is_open()){
        throw 0;// delete this!!!!
    }
    auto *result = new std::vector<Eigen::MatrixXf>();
    std::string tmp;
    while(!stream.eof()){
        Eigen::MatrixXf segment(segment_len, dimension);
        for(int j = 0; j < segment_len; j++){
            for(int d = 0; d < dimension; d++)
                stream >> segment(j, d);
        }
        result->push_back(segment);
    }
    stream.close();
    return result;
}
