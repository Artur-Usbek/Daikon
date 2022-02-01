
#ifndef PRELU_HPP
#define PRELU_HPP

#include <Eigen/Dense>

#include "layer.hpp"


class PReLU : public Layer
{
private:
    std::string type = "PReLU";
    double leakrate;
    Eigen::MatrixXd inputCache;

public:
    PReLU(double leakrateInit): leakrate(leakrateInit) {};
    ~PReLU() {};

    std::string get_type() { return this->type; };

    void forward(Eigen::MatrixXd &input)
    {   /*other option but slower
        input.array() = input.array().cwiseMax(0) + input.array().cwiseMax(0) * leakrate;
        */
        inputCache = input;
        input = (input.array() < 0).select(input * leakrate, input);
    };


    /* template <typename... Args>
    void backward(Eigen::MatrixXd first, Args... args)
    {
        first = (inputCache.array() < 0).select(first * leakrate, first);
    }; */
    
    void backward(Eigen::MatrixXd &first, Eigen::MatrixXd &input2, Eigen::MatrixXd &input3){
        first = (inputCache.array() < 0).select(first * leakrate, first);
    };
};
#endif // PRELU_HPP