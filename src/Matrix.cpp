#include "../include/Matrix.hpp"
#include<random>
#include<iostream>

double Matrix::getRandomNumber() 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,1);
    return dis(gen);
}

Matrix::Matrix(int numRows, int numCols, bool isRandom)
{
    this->numRows = numRows;
    this->numCols = numCols;

    for(int i = 0;i<numRows;i++)
    {
        vector<double> colValues;
        for(int j = 0;j<numCols;j++)
        {
            double r = 0.00;
            if(isRandom){
                r = getRandomNumber();
            }
            colValues.push_back(r);
        }
        this->values.push_back(colValues);
    }
}

void Matrix::printToConsole()
{
    for(int i = 0;i<numRows;i++)
    {
        for(int j = 0;j<numCols;j++)
        {
            std::cout<<values[i][j]<<" ";
        }
        std::cout<<endl;
    }
}

Matrix Matrix::transpose()
{
    Matrix m(numCols,numRows,false);
    for(int i = 0;i<numCols;i++)
    {
        for(int j = 0;j<numRows;j++)
        {
            m.setVal(i,j,values[j][i]);
        }
    }
    return m;
}

void Matrix::setVal(int r, int c, double val)
{
    values[r][c] = val;
}

double Matrix::getVal(int r,int c)
{
    return values[r][c]; 
}

Matrix operator * (Matrix&  m1,Matrix&  m2)
{
    if(m1.numCols != m2.numRows)
    {
        throw "Error: Incorrect Dimensions for Matrices";
    }
    Matrix res(m1.numRows,m2.numCols,false);
    for(int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m2.numCols;j++)
        {
            for(int k = 0;k<m1.numCols;k++)
            {
                res.setVal(i,j,res.getVal(i,j)+m1.getVal(i,k)*m2.getVal(k,j));
            }
        }
    }
    return res;
}

Matrix operator * (Matrix& m1,double v)
{
    Matrix res(m1.numRows,m1.numCols,false);
    for(int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,v*m1.getVal(i,j));
        }
    }
    return res;
}
Matrix operator *(double v ,Matrix& m1)
{
    return m1*v;
}

Matrix operator + (Matrix& m1,Matrix& m2)
{
    if(m1.numRows!= m2.numRows || m1.numCols!=m2.numCols)
    {
        throw "Error: Dimensions Mismatch";
    }
    Matrix res(m1.numRows,m1.numCols,false);
    for( int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,m1.getVal(i,j)+m2.getVal(i,j));
        }
    }
    return res;
}

Matrix operator + (Matrix& m1,double v)
{
    Matrix res(m1.numRows,m1.numCols,false);
    for( int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,m1.getVal(i,j)+v);
        }
    }
    return res;
}

Matrix operator + (double v,Matrix& m1)
{
    return m1+v;
}

Matrix operator - (Matrix& m1,Matrix& m2)
{
    if(m1.numRows!= m2.numRows || m1.numCols!=m2.numCols)
    {
        throw "Error: Dimensions Mismatch";
    }
    Matrix res(m1.numRows,m1.numCols,false);
    for( int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,m1.getVal(i,j)-m2.getVal(i,j));
        }
    }
    return res;
}

Matrix operator - (Matrix& m1,double v)
{
    Matrix res(m1.numRows,m1.numCols,false);
    for( int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,m1.getVal(i,j)-v);
        }
    }
    return res;
}

Matrix operator / (Matrix& m1,double v)
{
    if(v == 0)
    {
        throw "Error: Divide by Zero";
    }
    Matrix res(m1.numRows,m1.numCols,false);
    for( int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,m1.getVal(i,j)/v);
        }
    }
    return res;
}

Matrix operator - (Matrix &m1)
{
    Matrix res(m1.numRows,m1.numCols,false);
    for( int i = 0;i<m1.numRows;i++)
    {
        for(int j = 0;j<m1.numCols;j++)
        {
            res.setVal(i,j,-m1.getVal(i,j));
        }
    }
    return res;
}

ostream& operator <<(ostream& os,Matrix& m)
{
    for(int i = 0;i<m.numRows;i++)
    {
        for(int j = 0;j<m.numCols;j++)
        {
            os<<m.getVal(i,j)<<"\t";
        }
        os<<endl;
    }
    return os;
}

vector<double>& Matrix::operator[](int index)
{
    if(index< 0 || index >= numRows)
    {
        throw "Error: Index Out of Bounds";
    }
    return values[index];
}

vector<double> Matrix::flatten()
{
    vector<double> flat;
    for(int i =0 ;i<numRows;i++)
    {
        for(int j = 0;j<numCols;j++)
        {
            flat.push_back(values[i][j]);
        }
    }
    return flat;
}