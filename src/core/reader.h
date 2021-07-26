//
// Created by nikittossii on 24.07.2021.
//

#ifndef ALICESHOP_READER_H
#define ALICESHOP_READER_H

#include <fstream>
#include <string>
#include <vector>

#include <Eigen/Core>

// Read special file with k+n matrices (m * 3)
// Where k - amount of segments for database, n - amount of instance.
// File structure:
//      k m
//
//      1 2 3
//      3 4 5
// Example:
//    Reader r(path_to_file);
//    std::vector<Eigen::MatrixXf>* v1 = r.ReadDB();
//    std::vector<Eigen::MatrixXf>* v2 = r.ReadInstances();
class Reader {
private:
	std::ifstream file_descriptor_;
  int segments_;
  int segment_len_;
  const int kDimension_ = 3;
public:
	Reader(const std::string &filePath);
	std::vector<Eigen::MatrixXf>* ReadDB();
	std::vector<Eigen::MatrixXf>* ReadInstances();
	~Reader();
};


#endif //ALICESHOP_READER_H
