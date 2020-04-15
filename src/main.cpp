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
    nn.setCurrentInput(inputs);

    nn.feedForward();
    nn.printToConsole();

    //nn->printToConsole();

    Matrix m1(2,3,true);
    cout<<"Multiplying"<<endl;
    Matrix m2 = m1.transpose();
    cout<<m2;
    cout<<"Transposed"<<endl;
    
    Matrix m3 = m1*m2;
    cout<<m3;
    
    
    cout<<"Multiplication End"<<endl;
    //m3.printToConsole();

    Matrix m4 =  m1 * 2.0;

    Matrix m5 = 2.0 * m1;

    cout<<m4[0][0]<<endl;
    cout<<m5[0][0]<<endl;


    // m1->printToConsole();
    // cout<< "Value is: "<< n->getVal() <<endl;
    // cout<< "Activated Value is: "<< n->getActivatedVal() <<endl;
    // cout<< "Derived Value is: "<< n->getDerivedVal() <<endl;

    
}