#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include<iostream>
using namespace std;

class Neuron
{
    public:
        //Constructor
        Neuron(double val);

        //Fast Sigmoid Function
        //f(x) = x / (1+ |x|)
        void activate(); 

        //Derivative for Fast Sigmoid Function
        //f'(x) = f(x) * (1-f(x))
        void derive();

        //Setter Function
        void setVal(double);

        //Getter Functions
        double getVal() {return val;}
        double getActivatedVal() {return activatedVal;}
        double getDerivedVal() {return derivedVal;}


    private:
        double val;
        double activatedVal;
        double derivedVal;

};

#endif