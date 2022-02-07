#ifndef NN_HPP
#define NN_HPP

#include <Eigen/Dense>

using namespace Eigen;

template <int upper_n, int this_n>
class Layer {
  public:
    Matrix<double, upper_n, 1> input;
    Matrix<double, this_n, 1> output;
    Matrix<double, this_n, 1> gradient;
    Matrix<double, this_n, upper_n> w;
    Matrix<double, this_n, 1> bias;

    double (*activationFunc)(double);
    double (*derivativeFunc)(double);

    Layer(double (*fp)(double)) {
        activationFunc = fp;
        w.Random();
        bias.Random();
    }
    void activation(Matrix<double, this_n> &v) {
        for (int i = 0; i < this_n; ++i) {
            v(i, 0) = activationFunc(v(i, 0));
        }
    }
    void derivative(Matrix<double, this_n> &v) {
        for (int i = 0; i < this_n; ++i) {
            v(i, 0) = derivativeFunc(v(i, 0));
        }
    }
    Matrix<double, this_n, 1> &Forward(Matrix<double, upper_n, 1> &in) {
        input = in;
        output = w * input + bias;
        activation(output);
        return output;
    }
    Matrix<double, upper_n, 1> &Backward(Matrix<double, this_n, 1> &back,
                                         double eta) {
        gradient = output;
        derivative(gradient);

        // uncertaintly use
        gradient = gradient.cwiseProduct(back);

        w = w - eta * (input * gradient.transpose());
    }
};

#endif // NN_HPP