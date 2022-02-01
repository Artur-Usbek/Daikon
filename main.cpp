



#include <Eigen/Dense>
#include "matplotlibcpp.h"
#include "logging.hpp"

// AI
#include "prelu.hpp"
#include "relu.hpp"
#include "leakyrelu.hpp"
#include "linear.hpp"
#include "meansquarederror.hpp"
#include "neuralnetwork.hpp"

//
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <memory>
#include <utility>

int main()
{
    // Sizes of the NeuralNetwork
    int measuredSize    = 30;
    int inputSize       = 1;
    int outputSize      = 16;
    int inputSize2      = outputSize;
    int outputSize2     = 16;
    int inputSize3      = outputSize2;
    int outputSize3     = 1;

    // Generate Inputs
    Eigen::VectorXd X   = Eigen::VectorXd::LinSpaced(measuredSize, -1, 1);
    Eigen::MatrixXd input = Eigen::MatrixXd(measuredSize, 1);
    input.col(0)            = X;
    Eigen::MatrixXd target = input.array().cube();

    // Plot
    matplotlibcpp::plot(input, target, ".");
    matplotlibcpp::xlabel("X");
    matplotlibcpp::ylabel("y");
    matplotlibcpp::show();
    logging(target);

    // Creating the Layers
    NeuralNetwork NN;
    Linear lin1(inputSize, outputSize);
    LeakyReLU lrelu1;
    Linear lin2(inputSize2, outputSize2);
    LeakyReLU lrelu2;
    Linear lin3(inputSize3, outputSize3);

    // Add Layers
    //NN.add_layer_seq(lin1).add_layer_seq(lrelu1).add_layer_seq(lin2);
    NN.add_layer(lin1, lrelu1, lin2, lrelu2, lin3);

    // Add loss
    MeanSquaredError mse;
    NN.set_loss(mse);
    
    // Training the Network
    for (int i = 0; i < 10000; i++)
    {
        Eigen::MatrixXd input2 = input.replicate(1, 1);
        auto err_val = NN.forward(input2, target);
        if (i % 100 == 0)
        {
            logging("Error:", err_val);
        };
        NN.backward();
    };
    
    // Plot Training History
    matplotlibcpp::plot(NN.lossHistory);
    matplotlibcpp::show();

    // Prediciting with trained Network
    Eigen::VectorXd val_X = Eigen::VectorXd::LinSpaced(measuredSize * 20, -1, 1);
    Eigen::MatrixXd val_input = Eigen::MatrixXd(measuredSize * 20, 1);
    val_input.col(0) = val_X;
    Eigen::MatrixXd val_target = val_input.array().cube();
    Eigen::MatrixXd val_Y = val_input.replicate(1, 1);
    NN.predict(val_input);
    
    // Plot prediction
    matplotlibcpp::plot(val_Y, val_input);
    matplotlibcpp::plot(val_Y, val_target);
    matplotlibcpp::show();

    // Benchmark
    int benchcount = 1000; // number of predictions
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i <= benchcount; i++)
    {
        NN.predict(val_input);
    };
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    logging("Time needed in ms:", elapsed); 
    
    return 0;
}