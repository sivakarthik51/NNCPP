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

ostream& operator << (ostream& os, NeuralNetwork& nn)
{
    os<<"===================================================================="<<endl;
    for(int i =0 ;i<nn.layers.size();i++)
    {
        os<<"LAYER: "<<i<<endl;
        os<<"Values of Layer:"<<endl;
        if(i == 0)
        {
            Matrix m = nn.layers[i].matrixifyVals();
            os<<m;
        }
        else
        {
            Matrix m = nn.layers[i].matrixifyActivatedVals();
            os<<m;
        }
        if(i!= nn.layers.size()-1)
        {
            os<<"Weight Matrix:"<<endl;
            Matrix w = nn.getWeightMatrix(i);
            os<<w;
        }
        os<<"===================================================================="<<endl;

    }
    return os;
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

void NeuralNetwork::setErrors()
{
    if(target.size() == 0)
    {
        throw "Error: No Targets for this Neural Netork";
    }
    if(target.size() != layers[layers.size()-1].getNeurons().size() )
    {
        throw "Error: Dimensions Mismatch between Output Layer and Target";
    }
    
    int outputLayerIndex = layers.size()-1;
    Matrix outputMatrix = layers[outputLayerIndex].matrixifyActivatedVals();
    Matrix targetMatrix = Matrix(target);
    
    Matrix err = outputMatrix-targetMatrix;
    error = err.sum();
    errors = err.flatten();
    
    historicalErrors.push_back(error);
}