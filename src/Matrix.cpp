#include "Matrix.h"
#include <iostream>
#define LOG(x) std::cout << x << std::endl
#include <iterator>

Matrix::Matrix(float* values)
{
    this->values = values;
}

Matrix::~Matrix()
{
    //dtor
}


Matrix Matrix::operator+(Matrix matrix)
{

    Matrix newMatrx();
    LOG(matrix.values[0]);

}
