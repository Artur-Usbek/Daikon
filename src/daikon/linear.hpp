#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "layer.hpp"
#include <Eigen/Dense>

#include <string>

class Linear : public Layer
{

private:
    Eigen::MatrixXd inputCache;
    const std::string type = "Linear";

public:
    Eigen::MatrixXd weight;
    Eigen::RowVectorXd bias;

    Linear(int inputSize, int outputSize):  weight(Eigen::MatrixXd::Random(inputSize, outputSize)),
                                            bias(Eigen::RowVectorXd::Random(1, outputSize)) {};

    ~Linear(){};

    void forward(Eigen::MatrixXd &input)
    {
        inputCache = input;
        input = (input * weight).rowwise() + bias;
    };

    std::string get_type(){ return this->type; };

    /* template <typename ... Args>
    void backward(Eigen::MatrixXd &dInput,
                  Eigen::MatrixXd &dWeight,
                  Eigen::RowVectorXd &dBias,
                  Args ... args)
    {
        dWeight = inputCache.transpose() * dInput;
        dBias = dInput.colwise().sum();
        dInput = dInput * weight.transpose();
    }; */
    void backward(Eigen::MatrixXd &dInput, Eigen::MatrixXd &dWeight, Eigen::MatrixXd &dBias)
    {
        dWeight = inputCache.transpose() * dInput;

        dBias = dInput.colwise().sum();


        dInput = dInput * weight.transpose();
        
    };
};

#endif // LINEAR_HPP