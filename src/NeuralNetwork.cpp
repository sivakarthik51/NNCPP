#include "../include/NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(vector<int>& topology)
{
    this->topologySize = topology.size();
    this->topology = topology;

    for(int i = 0;i<topologySize;i++)
    {
        Layer l(topology[i]);
        this->layers.push_back(l);
    }
    for(int i = 0;i<topologySize-1;i++)
    {
        Matrix m(topology[i],topology[i+1],true);
        this->weightMatrices.push_back(m);
    }
}

void NeuralNetwork::setCurrentInput(vector<double> input)
{
    this->input = input;
    
    for(int i = 0;i<input.size();i++)
    {
        this->layers[0].setVal(i,input[i]);
    }
    

}

void NeuralNetwork::printToConsole()
{
    for(int i =0 ;i<layers.size();i++)
    {
        cout<<"LAYER: "<<i<<endl;
        if(i == 0)
        {
            Matrix m = layers[i].matrixifyVals();
            cout<<m;
        }
        else
        {
            Matrix m = layers[i].matrixifyActivatedVals();
            cout<<m;
        }
    }
}
Matrix NeuralNetwork::getWeightMatrix(int i)
{
    return weightMatrices[i];
}

void NeuralNetwork::feedForward()
{
    for(int i = 0;i<layers.size()-1;i++)
    {
        Matrix a = getNeuronMatrix(i);
        if(i!=0)
        {
            a = getActivatedNeuronMatrix(i);
        }
        Matrix b = getWeightMatrix(i);
        Matrix c = a * b;
        vector<double> vals = c.flatten();
        layers[i+1].setVal(vals);

    }
}