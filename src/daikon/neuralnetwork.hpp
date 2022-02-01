#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <Eigen/Dense>



#include "layer.hpp"
#include "linear.hpp"
#include "loss.hpp"
#include "meansquarederror.hpp"

#include <memory>
#include <vector>


class NeuralNetwork
{
private:
    

public:
    std::vector<double> lossHistory;
    std::shared_ptr<Loss> loss;
    std::vector<std::shared_ptr<Layer>> layers;

    NeuralNetwork(){};
    ~NeuralNetwork(){};

    void predict(Eigen::MatrixXd &input)
    {
        for (auto &layer : layers)
        {
            layer->forward(input);
        };
    };

    Eigen::MatrixXd forward(Eigen::MatrixXd &input, Eigen::MatrixXd &target)
    {
        predict(input);
        Eigen::MatrixXd err = loss->forward(input, target);
        lossHistory.push_back(err(0));
        return err;
    };

    void backward()
    {
        Eigen::MatrixXd dOut = loss->backward();
        Eigen::MatrixXd dWeight;
        Eigen::MatrixXd dBias;
        double learnrate = 0.0001;
        for (int i = layers.size() - 1; i >= 0; --i)
        {
            layers[i]->backward(dOut, dWeight, dBias);
            if ((layers[i]->get_type() == "Linear"))
            {
                std::shared_ptr<Linear> foo;
                foo = std::dynamic_pointer_cast<Linear>(layers[i]);

                foo->bias -= learnrate * dBias;
                foo->weight -= learnrate * dWeight;
            };
        };
    }

    template <typename T>
    void set_loss(T lossInit)
    {
        loss = std::make_shared<T>(lossInit);
    };

    template <typename T>
    void add_layer(T &layer)
    {
        std::shared_ptr<Layer> layer_ptr = std::make_shared<T>(layer);
        layers.push_back(layer_ptr);
    };

    template <typename T, typename... Args>
    void add_layer(T &first, Args... args)
    {
        add_layer(first);
        add_layer(args ...);
    };

    template <typename T>
    NeuralNetwork& add_layer_seq(T &layer)
    {
        std::shared_ptr<Layer> layer_ptr = std::make_shared<T>(layer);
        layers.push_back(layer_ptr);
        return *this;
    };

};

#endif // NEURALNETWORK_HPP