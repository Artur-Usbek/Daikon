#ifndef LOSS_HPP
#define LOSS_HPP

#include <Eigen/Dense>
#include <string>

class Loss
{
private:
    std::string type;

public:
    virtual ~Loss(){};

    std::string get_type(){return type;};

    virtual Eigen::MatrixXd forward(Eigen::MatrixXd prediction, Eigen::MatrixXd target) = 0;
    virtual Eigen::MatrixXd backward()=0;
};

#endif // LOSS_HPP