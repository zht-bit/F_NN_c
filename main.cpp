#include <cmath>
#include <iostream>

using namespace std;

double sigmoid(double x) { return 1 / (1 + exp(-x)); }
double tanh(double x){
    double ex = exp(x);
    ex = ex * ex;
    return (ex - 1) / (ex + 1);
}
