#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include<iostream>
#include<vector>
#include "Neuron.hpp"
#include "Matrix.hpp"

using namespace std;

class Layer
{
    public:
        //Constructor
        Layer(int size);

        vector<Neuron> getNeurons() {return this->neurons;}
        void setVal(int,double);
        void setVal(vector<double>);
        Matrix matrixifyVals();
        Matrix matrixifyActivatedVals();
        Matrix matrixifyDerivedVals();


    private:
        int size;
        vector<Neuron> neurons;

};

#endif