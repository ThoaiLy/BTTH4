#pragma once
#include <iostream>
#include "CVector.h"

using namespace std;

class cMatrix{
    private:
        int row, col;
        double **matrix;
    public:
        cMatrix();
        cMatrix(int r, int c);
        cMatrix(const cMatrix& other);
        ~cMatrix();
        double& operator()(int i, int j);
        const double& operator()(int i, int j) const;
        cMatrix operator + (const cMatrix& other) const;
        cMatrix operator - (const cMatrix& other) const;
        cMatrix operator * (const cMatrix& other) const;
        cMatrix operator * (double x) const;
        friend cMatrix operator * (double x, const cMatrix& other);
        CVector operator*(const CVector& v) const;
        cMatrix& operator= (const cMatrix& other);
        friend istream& operator >> (istream& in, cMatrix& other);
        friend ostream& operator << (ostream& out, const cMatrix& other);
};