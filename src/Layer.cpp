#include "../include/Layer.hpp"

Layer::Layer(int size)
{
    this->size = size;
    for(int i = 0;i<size;i++)
    {
        Neuron n(0.00);
        neurons.push_back(n);
    }
}

//TODO : Overload setVal function for vector<double>
void Layer::setVal(int i, double v)
{
    neurons[i].setVal(v);
}

void Layer::setVal(vector<double> v)
{
    if(v.size()!=neurons.size())
    {
        throw "Error: Dimension Mismatch";
    }
    for(int i = 0;i<v.size();i++)
    {
        neurons[i].setVal(v[i]);
    }
}

Matrix Layer::matrixifyVals()
{
    Matrix m(1,size,false);
    for(int i = 0;i<size;i++)
    {
        m.setVal(0,i,neurons[i].getVal());
    }
    return m;
}

Matrix Layer::matrixifyActivatedVals()
{
    Matrix m(1,size,false);
    for(int i = 0;i<size;i++)
    {
        m.setVal(0,i,neurons[i].getActivatedVal());
    }
    return m;
}

Matrix Layer::matrixifyDerivedVals()
{
    Matrix m(1,size,false);
    for(int i = 0;i<size;i++)
    {
        m.setVal(0,i,neurons[i].getDerivedVal());
    }
    return m;
}