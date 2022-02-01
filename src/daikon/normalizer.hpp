

#include <Eigen/Dense>

class Normalizer
{
private:
public:
    Eigen::RowVectorXd x_min;
    Eigen::RowVectorXd x_max;
    Normalizer(Eigen::MatrixXd x_min, Eigen::MatrixXd double x_max);
    Normalizer(double x_min, double x_max);
    ~Normalizer();
    normalize(Eigen::MatrixXd &input);
};