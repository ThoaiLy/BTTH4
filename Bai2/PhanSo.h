#pragma once
#include <iostream>
using namespace std;

class PhanSo{
    private:
        int iTu, iMau;
    public:
        friend istream& operator >> (istream& in, PhanSo& ps);
        friend ostream& operator << (ostream& out, const PhanSo& ps);
        PhanSo(int tu = 0, int mau = 1);
        PhanSo(const PhanSo& other);
        void RutGon();
        PhanSo operator + (const PhanSo& other) const;
        PhanSo operator + (int a) const;
        friend PhanSo operator + (int a, const PhanSo& other);
        PhanSo operator - (const PhanSo& other) const;
        PhanSo operator - (int a) const;
        friend PhanSo operator - (int a, const PhanSo& other);
        PhanSo operator * (const PhanSo& other) const;
        PhanSo operator * (int a) const;
        friend PhanSo operator * (int a, const PhanSo& other);
        PhanSo operator / (const PhanSo& other) const;
        PhanSo operator / (int a) const;
        friend PhanSo operator / (int a, const PhanSo& other);
        bool operator == (const PhanSo& other) const;
        bool operator > (const PhanSo& other) const;
        bool operator < (const PhanSo& other) const;
};