
#ifndef LEAKYRELU_HPP
#define LEAKYRELU_HPP

#include "prelu.hpp"

class LeakyReLU : public PReLU
{
private:
    std::string type = "LeakyReLU";
public:
    LeakyReLU(): PReLU{0.1} {};
    ~LeakyReLU(){};
    std::string get_type() { return this->type; };
};

#endif // LEAKYRELU_HPP