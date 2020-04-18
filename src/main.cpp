#include<iostream>
#include "../include/Neuron.hpp"
#include "../include/Matrix.hpp"
#include "../include/NeuralNetwork.hpp"

using namespace std;

int main(int argc,char **argv)
{
    vector<int> top{3,2,3};
    NeuralNetwork nn(top);
    vector<double> inputs{0.5,0.6,0.7};
    vector<double> targets{1,0,1};
    nn.setCurrentInput(inputs);
    nn.setCurrentTarget(targets);
    
    for(int i = 0;i<100000;i++)
    {
        nn.feedForward();
        nn.setErrors();
        nn.backPropagation();
        if(i%1000 == 0)
        {
            cout<<"Total Error:"<<nn.getTotalError()<<endl;
            cout<<"Output:"<<nn.getActivatedNeuronMatrix(2);
        }


    }


    // Matrix m1(2,3,true);
    
    // cout<<m1;
    // cout<<m1.power(2);
    
    
    // Matrix m3 = m1*m1.transpose();
    // cout<<m3;
    
    
    // cout<<"Multiplication End"<<endl;
    // m3.printToConsole();

    // Matrix m4 =  m1 * 2.0;

    // Matrix m5 = 2.0 * m1;

    // Matrix m6 = m4-m5;

    // cout<<m6;


    // m1->printToConsole();
    // cout<< "Value is: "<< n->getVal() <<endl;
    // cout<< "Activated Value is: "<< n->getActivatedVal() <<endl;
    // cout<< "Derived Value is: "<< n->getDerivedVal() <<endl;

    
}