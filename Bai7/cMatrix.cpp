#include <iostream>
#include "cMatrix.h"
#include "CVector.h"

using namespace std;

cMatrix::cMatrix()
{
    row = col = 0;
    matrix = NULL;
}

cMatrix::cMatrix(int r, int c)
{
    row = r;
    col = c;

    matrix = new double*[row];
    for(int i = 0; i < row; i++)
        matrix[i] = new double[col]{0};
}

cMatrix::cMatrix(const cMatrix& other)
{
    row = other.row;
    col = other.col;

    matrix = new double*[row];
    for(int i = 0; i < row; i++)
    {
        matrix[i] = new double[col];
        for(int j = 0; j < col; j++)
            matrix[i][j] = other(i, j);
    }
}

cMatrix::~cMatrix()
{
    if(matrix != NULL)
    {
        for(int i = 0; i < row; i++)
            delete[] matrix[i];

        delete[] matrix;
    }

    matrix = NULL;
}

double& cMatrix::operator()(int i, int j)
{
    return matrix[i][j];
}

const double& cMatrix::operator()(int i, int j) const
{
    return matrix[i][j];
}

cMatrix cMatrix::operator + (const cMatrix& other) const
{
    if(row != other.row || col != other.col)
    {
        cout << "Không cộng được!\n";
        return cMatrix();
    }
    cMatrix res(row, col);
    for(int i = 0; i < other.row; i++)
        for(int j = 0; j < other.col; j++)
            res(i, j) = matrix[i][j] + other(i, j);
    return res;
}

cMatrix cMatrix::operator - (const cMatrix& other) const
{
    if(row != other.row || col != other.col)
    {
        cout << "Không trừ được!\n";
        return cMatrix();
    }
    cMatrix res(row, col);
    for(int i = 0; i < other.row; i++)
        for(int j = 0; j < other.col; j++)
            res(i, j) = matrix[i][j] - other(i, j);
    return res;
}

cMatrix cMatrix::operator * (const cMatrix& other) const
{
    if(col != other.row)
    {
        cout << "Không nhân được!\n";
        return cMatrix();
    }
    cMatrix res(row, other.col);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < other.col; j++) {
            res(i, j) = 0;
            for(int k = 0; k < col; k++)
                res(i, j) += matrix[i][k] * other(k, j);
        }
    }
    return res;
}

cMatrix cMatrix::operator * (double x) const
{
    cMatrix res(*this);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            res(i, j) *= x;
    return res;
}

cMatrix operator * (double x, const cMatrix& other)
{
    cMatrix res(other);
    for(int i = 0; i < res.row; i++)
        for(int j = 0; j < res.col; j++)
            res(i, j) *= x;
    return res;
}

CVector cMatrix::operator*(const CVector& v) const
{
    if(col != v.getN())
    {
        cout << "Không nhân được!\n";
        return CVector();
    }
    CVector res(row);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            res[i] += matrix[i][j] * v[j];
        }
    }
    return res;
}

cMatrix& cMatrix::operator= (const cMatrix& other)
{
    if(this == &other)
        return *this;

    for(int i = 0; i < row; i++)
        delete[] matrix[i];

    delete[] matrix;

    row = other.row;
    col = other.col;

    matrix = new double*[row];

    for(int i = 0; i < row; i++)
    {
        matrix[i] = new double[col];

        for(int j = 0; j < col; j++)
            matrix[i][j] = other(i, j);
    }

    return *this;
}

istream& operator >> (istream& in, cMatrix& other)
{
    if(other.matrix != NULL)
    {
        for(int i = 0; i < other.row; i++)
            delete[] other.matrix[i];

        delete[] other.matrix;
        other.matrix = NULL;
    }
    while (true)
    {
        cout << "Nhập số dòng và số cột: ";
        in >> other.row >> other.col;
        if(in.fail() || in.peek() != '\n' || other.row <= 0 || other.col <= 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }
        break;
    }

    other.matrix = new double*[other.row];
    for(int i = 0; i < other.row; i++)
        other.matrix[i] = new double[other.col];
    while(true)
    {
        bool fail = false;
        for(int i = 0; i < other.row; i++)
        {
            for(int j = 0; j < other.col; j++) {
                cout << "a[" << i << "][" << j << "] = ";
                in >> other.matrix[i][j];
                if(in.fail())
                {
                    fail = true;
                    break;
                }
            }
            if(fail)
                break;
        }
        if(in.fail() || in.peek() != '\n')
            fail = true;
        if(fail)
        {
            cout << "Dữ liệu nhập sai!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }

        break;
    }

    return in;
}

ostream& operator << (ostream& out, const cMatrix& other)
{
    for(int i = 0; i < other.row; i++)
    {
        for(int j = 0; j < other.col; j++) {
            out << other.matrix[i][j] << ' ';
        }
        out << '\n';
    }

    return out;
}