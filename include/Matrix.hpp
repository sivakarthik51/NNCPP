#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include<iostream>
#include<vector>

using namespace std;

class Matrix
{
    public:
        //Constructor
        Matrix(int numRows,int numCols, bool isRandom);
        Matrix(vector<double>&);

        Matrix transpose();

        void setVal(int r, int c, double v);

        double getVal(int r,int c);

        int getNumRows() {return numRows;}
        int getNumCols() {return numCols;}
        double getRandomNumber();
        void printToConsole();

        vector<double> flatten();

        //Multiply two matrices
        friend Matrix operator * (Matrix&,Matrix&);

        //Multiply Matrix by scalar
        friend Matrix operator * (Matrix&,double);
        friend Matrix operator *(double,Matrix&);

        //Add Two Matrices
        friend Matrix operator + (Matrix&,Matrix&);

        //Add Sclar to Matrix
        friend Matrix operator + (Matrix&,double);
        friend Matrix operator + (double,Matrix&);

        //Subtract Matrices
        friend Matrix operator - (Matrix&, Matrix&);

        //Subtract Scalar from Matrix
        friend Matrix operator - (Matrix&, double);

        // Divide Matrix by Scalar
        friend Matrix operator / (Matrix&, double);

        //Unary Minus
        friend Matrix operator - (Matrix&);

        //Output Operator Overload
        friend ostream& operator <<(ostream&,Matrix&);

        vector<double>& operator[](int);

        double sum();

    private:
        int numRows;
        int numCols;
        //bool isRandom;
        vector<vector<double>> values;
        

};

#endif