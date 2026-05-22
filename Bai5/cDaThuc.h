#pragma once
#include <iostream>

using namespace std;

class cDaThuc
{
    private:
        int n;
        double *heso;
    public:
        cDaThuc();
        cDaThuc(int size);
        cDaThuc(const cDaThuc &other);
        ~cDaThuc();
        cDaThuc operator + (const cDaThuc &a) const;
        cDaThuc operator + (double x) const;
        friend cDaThuc operator + (double x, const cDaThuc &a);
        cDaThuc operator - (const cDaThuc &a) const;
        cDaThuc operator - (double x) const;
        friend cDaThuc operator - (double x, const cDaThuc &a);
        cDaThuc operator * (const cDaThuc &a) const;
        cDaThuc operator * (double x) const;
        friend cDaThuc operator * (double x, const cDaThuc &a);
        cDaThuc& operator = (const cDaThuc &other);
        friend istream& operator >> (istream& in, cDaThuc &a);
        friend ostream& operator << (ostream& out, const cDaThuc &a);
};