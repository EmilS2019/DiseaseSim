#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
    public:
        Matrix(float* values);
        Matrix operator+(Matrix matrix);
        Matrix operator*(Matrix matrix);
        virtual ~Matrix();
        float* values;
    protected:

    private:

};

#endif // MATRIX_H
