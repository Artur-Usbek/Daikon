#ifndef LAYER_HPP
#define LAYER_HPP

#include <Eigen/Dense>
#include <string>


class Layer
{
protected:
    std::string type = "Layer";

public:
    Layer(){};
    virtual ~Layer() = default;

    virtual std::string get_type()=0;
    virtual void forward(Eigen::MatrixXd &input) = 0;
    virtual void backward(Eigen::MatrixXd &input1, 
                            Eigen::MatrixXd &input2, 
                            Eigen::MatrixXd &input3) = 0;
};

#endif // LAYER_HPP