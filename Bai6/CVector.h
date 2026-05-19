#pragma once
#include <iostream>

using namespace std;

class CVector{
    private:
        int n;
        double *v;
    public:
        CVector();
        CVector(int soChieu);
        CVector(const CVector &other);
        ~CVector();
        CVector operator+ (const CVector &other) const;
        CVector operator- (const CVector &other) const;
        CVector operator* (double k) const;
        friend CVector operator* (double k, const CVector &other);
        friend double operator* (const CVector &a, const CVector &b); //Nhân vô hướng
        double& operator[] (int index); //Truy cập và chỉnh sửa phần tử
        const double& operator[] (int index) const; //Chỉ truy cập phần tử
        CVector& operator= (const CVector &other);
        friend istream& operator>> (istream& is, CVector &v);
        friend ostream& operator<< (ostream& os, const CVector &v);
};