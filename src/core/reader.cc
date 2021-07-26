//
// Created by nikittossii on 24.07.2021.
//

#include "reader.h"

#include <string>
#include <vector>

#include <Eigen/Core>

Reader::Reader(const std::string &filePath) {
	file_descriptor_.open(filePath);
	if(!file_descriptor_.is_open()){
    // TODO(nikittossii): change exception value
    throw 0;
	}
}

std::vector<Eigen::MatrixXf>* Reader::ReadDB(){
	if(!file_descriptor_.is_open()){
		// TODO(nikittossii): change exception value
    throw 0;
	}
  file_descriptor_ >> segments_ >> segment_len_;
  std::vector<Eigen::MatrixXf> *result = new std::vector<Eigen::MatrixXf>(segments_);
  for(int i = 0; i < segments_; i++){
    Eigen::MatrixXf segment(segment_len_, kDimension_);
    for(int j = 0; j < segment_len_; j++){
      for(int d = 0; d < kDimension_; d++)
        file_descriptor_ >> segment(j, d);
    }
    (*result)[i] = segment;
  }
  return result;
}

std::vector<Eigen::MatrixXf>* Reader::ReadInstances() {
	if(!file_descriptor_.is_open()){
    throw 0;// delete this!!!!
	}
  auto *result = new std::vector<Eigen::MatrixXf>();
  std::string tmp;
  while(!file_descriptor_.eof()){
    Eigen::MatrixXf segment(segment_len_, kDimension_);
    for(int j = 0; j < segment_len_; j++){
      for(int d = 0; d < kDimension_; d++)
        file_descriptor_ >> segment(j, d);
    }
    result->push_back(segment);
  }
  file_descriptor_.close();
  return result;
}
