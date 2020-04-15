#ifndef _NEURAL_NETWORK_HPP_
#define _NEURAL_NETWORK_HPP_

#include<iostream>
#include<vector>
#include "Matrix.hpp"
#include "Layer.hpp"
#include "Neuron.hpp"

using namespace std;

class NeuralNetwork
{
    public:
        //Constructor
        NeuralNetwork(vector<int>& topology);
        void setCurrentInput(vector<double>);
        void printToConsole();
        Matrix getNeuronMatrix(int i) { return layers[i].matrixifyVals();}
        Matrix getActivatedNeuronMatrix(int i) {return layers[i].matrixifyActivatedVals();}
        Matrix getDerivedNeuronMatrix(int i) {return layers[i].matrixifyDerivedVals();}
        Matrix getWeightMatrix(int);
        void feedForward();

        double getTotalError() {return error;}
        vector<double> getErrors() {return errors;}
        void setCurrentTarget(vector<double>& tar) {target = tar;}

        void setErrors();

    private:
        int topologySize;
        vector<int> topology;
        vector<Layer> layers;
        vector<Matrix> weightMatrices;
        vector<double> input;
        vector<double> target;
        double error;
        vector<double> errors;
        vector<double> historicalErrors;
        
};

#endif