#include "../include/Neuron.hpp"
#include<math.h>

//Constructor
Neuron::Neuron(double val)
{
    this->val = val;
    activate();
    derive();
}

void Neuron::setVal(double val)
{
    this->val = val;
    activate();
    derive();
}
//Fast Sigmoid Activation
void Neuron::activate()
{
    this->activatedVal = (this->val) / (1 + abs(this->val) );
}

//Derivative of Fast Sigmoid
void Neuron::derive()
{
    this->derivedVal = this->activatedVal *(1-this->activatedVal);
}