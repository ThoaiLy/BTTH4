#pragma once
#include <iostream>
using namespace std;

class SoPhuc{
    private:
        double dThuc, dAo;
    public:
        SoPhuc(double thuc = 0, double ao = 0);
        friend istream& operator >> (istream& in, SoPhuc& sp);
        friend ostream& operator << (ostream& out, const SoPhuc& sp);
        SoPhuc operator + (const SoPhuc& other) const;
        SoPhuc operator + (double a) const;
        friend SoPhuc operator + (double a, const SoPhuc& other);
        SoPhuc operator - (const SoPhuc& other) const;
        SoPhuc operator - (double a) const;
        friend SoPhuc operator - (double a, const SoPhuc& other);
        SoPhuc operator *(const SoPhuc& other) const;
        SoPhuc operator * (double a) const;
        friend SoPhuc operator * (double a, const SoPhuc& other);
        SoPhuc operator / (const SoPhuc& other) const;
        SoPhuc operator / (double a) const;
        friend SoPhuc operator / (double a, const SoPhuc& other);
        bool operator == (const SoPhuc& other);
        bool operator != (const SoPhuc& other);
};