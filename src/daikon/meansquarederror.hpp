#ifndef MEANSQUAREDERROR_HPP
#define MEANSQUAREDERROR_HPP

#include <Eigen/Dense>
#include "loss.hpp"

class MeanSquaredError :  public Loss{
    private:
        Eigen::MatrixXd errorCache;

    public:
        Eigen::MatrixXd forward(Eigen::MatrixXd prediction, Eigen::MatrixXd target)
        {
            errorCache = target - prediction;
            return errorCache.array().square().colwise().sum() / target.rows();
        };
        
        Eigen::MatrixXd backward(){return -2 * errorCache;};
};

#endif // MEANSQUAREDERROR_HPP
