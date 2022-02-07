#include "dataSet.h"

DataSet::DataSet() { num = 0; }
void DataSet::addData(Matrix<double, SIZE, 1> x, bool y) {
    lst.push_back(make_pair(x, y));
}
void DataSet::addData(Matrix<double, SIZE, 1> &x, bool y) {
    lst.push_back(make_pair(x, y));
}
void DataSet::addData(Matrix<double, SIZE, 1> &&x, bool y) {
    lst.push_back(make_pair(x, y));
}
void DataSet::setBegin() { num = 0; }
pair<Matrix<double, SIZE, 1>, bool> &DataSet::getData() {
    if (num >= lst.size()) num = 0;
    return lst[num++];
}
