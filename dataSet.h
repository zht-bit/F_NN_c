#ifndef DATASET_H
#define DATASET_H

#include <Eigen/Dense>
#include <vector>

#define SIZE 2

using namespace std;
using namespace Eigen;

class DataSet {
  public:
    int num;
    vector<pair<Matrix<double, SIZE, 1>, bool>> lst;

    DataSet();
    void addData(Matrix<double, SIZE, 1>, bool);
    void addData(Matrix<double, SIZE, 1> &, bool);
    void addData(Matrix<double, SIZE, 1> &&, bool);

    void setBegin();
    pair<Matrix<double, SIZE, 1>, bool> &getData();
};

#endif