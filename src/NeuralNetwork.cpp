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
    error = 0.5* err.power(2).sum();
    errors = err.flatten();
    
    historicalErrors.push_back(error);
}

void NeuralNetwork::backPropagation()
{
    vector<Matrix> newWeights;
    
    int outputLayerIndex = layers.size()-1;
    Matrix derivedValsYToZ = layers[outputLayerIndex].matrixifyDerivedVals();
    Matrix gradientsYToZ = Matrix(errors).dot(derivedValsYToZ);
    int lastHiddenLayerIndex = outputLayerIndex -1;
    Layer lastHiddenLayer = layers[lastHiddenLayerIndex];
    Matrix weightsOutputToHidden = weightMatrices[lastHiddenLayerIndex];
    Matrix deltaOutputToHidden = (gradientsYToZ.transpose() * lastHiddenLayer.matrixifyActivatedVals()).transpose();
    Matrix newWeightsOutputToHidden = weightsOutputToHidden - deltaOutputToHidden;
    newWeights.push_back(newWeightsOutputToHidden);
    Matrix gradient = gradientsYToZ;
    for(int i = outputLayerIndex-1;i>=1;i--)
    {
        Layer l = layers[i];
        Matrix activatedHidden = l.matrixifyActivatedVals();
        Matrix derivedHidden = l.matrixifyDerivedVals();
        Matrix weightMatrix = weightMatrices[i];
        Matrix derivedGradients = (gradient * weightMatrix.transpose()).dot(activatedHidden);
        
        Matrix leftNeurons = (i-1) == 0 ? layers[0].matrixifyVals() : layers[i-1].matrixifyActivatedVals();
        Matrix deltaWeights = derivedGradients.transpose() * leftNeurons;
        
        Matrix newWeightsHidden = weightMatrices[i-1] - deltaWeights.transpose();
        
        newWeights.push_back(newWeightsHidden);
        gradient = derivedGradients;        
    }

    reverse(newWeights.begin(),newWeights.end());
    weightMatrices = newWeights;

}