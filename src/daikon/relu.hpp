
#ifndef RELU_HPP
#define RELU_HPP

#include "prelu.hpp"

class ReLU : public PReLU
{
private:
    std::string type = "ReLU";

public : 
    ReLU(): PReLU{0} {};
    ~ReLU() {};
};

#endif // RELU_HPP