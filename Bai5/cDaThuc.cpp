#include <iostream>
#include "cDaThuc.h"

using namespace std;

cDaThuc::cDaThuc()
{
    n = 0;
    heso = new double[n + 1]{0};
}

cDaThuc::cDaThuc(int bac)
{
    n = bac;
    heso = new double[n + 1]{0};
}

cDaThuc::cDaThuc(const cDaThuc &other)
{
    n = other.n;
    heso = new double[n + 1];
    for(int i = 0; i <= n; i++)
        heso[i] = other.heso[i];
}

cDaThuc::~cDaThuc()
{
    delete[] heso;
    heso = NULL;
}

cDaThuc cDaThuc::operator + (const cDaThuc &a) const
{
    int bacMax = max(n, a.n);
    cDaThuc tmp(bacMax);

    for(int i = 0; i <= bacMax; i++)
    {
        double hs1 = (i <= n) ? heso[i] : 0;
        double hs2 = (i <= a.n) ? a.heso[i] : 0;
        
        tmp.heso[i] = hs1 + hs2;
    }
    
    return tmp;
}

cDaThuc cDaThuc::operator + (double x) const
{
    cDaThuc tmp(*this);
    tmp.heso[0] += x;
    return tmp;
}

cDaThuc operator + (double x, const cDaThuc &a)
{
    cDaThuc tmp(a);
    tmp.heso[0] += x;
    return tmp;
}

cDaThuc cDaThuc::operator - (const cDaThuc &a) const
{
    int bacMax = max(n, a.n);
    cDaThuc tmp(bacMax);

    for(int i = 0; i <= bacMax; i++)
    {
        double hs1 = (i <= n) ? heso[i] : 0;
        double hs2 = (i <= a.n) ? a.heso[i] : 0;
        
        tmp.heso[i] = hs1 - hs2;
    }
    
    return tmp;
}

cDaThuc cDaThuc::operator - (double x) const
{
    cDaThuc tmp(*this);
    tmp.heso[0] -= x;
    return tmp;
}

cDaThuc operator - (double x, const cDaThuc &a)
{
    cDaThuc tmp(a);
    for(int i = 0; i <= tmp.n; i++)
        tmp.heso[i] = -tmp.heso[i];
    tmp.heso[0] += x;
    return tmp;
}

cDaThuc cDaThuc::operator * (const cDaThuc &a) const
{
    cDaThuc tmp(n + a.n);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= a.n; j++)
            tmp.heso[i + j] += heso[i] * a.heso[j];
    
    return tmp;
}

cDaThuc cDaThuc::operator * (double x) const
{
    cDaThuc tmp(*this);
    for(int i = 0; i <= tmp.n; i++)
        tmp.heso[i] *= x;
    return tmp;
}

cDaThuc operator * (double x, const cDaThuc &a)
{
    cDaThuc tmp(a);
    for(int i = 0; i <= tmp.n; i++)
        tmp.heso[i] *= x;
    return tmp;
}

cDaThuc& cDaThuc::operator = (const cDaThuc &other)
{
    if(this == &other)
        return *this;

    delete[] heso;

    n = other.n;

    heso = new double[n + 1];

    for(int i = 0; i <= n; i++)
        heso[i] = other.heso[i];

    return *this;
}

istream& operator >> (istream& in, cDaThuc &a)
{
    while(true)
    {
        cout << "Nhập bậc của đa thức(n >= 0): ";
        in >> a.n;
        if(in.fail() || in.peek() != '\n' || a.n < 0)
        {
            cout << "Dữ liệu nhập sai!\n ";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }
        break;
    }

    delete[] a.heso;
    a.heso = new double[a.n + 1];
    for(int i = a.n; i >= 0; i--)
    {
        cout << "Nhập hệ số thứ của x^" << i << ": ";
        while (true)
        {
            in >> a.heso[i];
            if(in.fail() || in.peek() != '\n')
            {
                cout << "Dữ liệu nhập sai!\n ";
                in.clear();
                in.ignore(10000, '\n');
                continue;
            }
            break;
        }
    }
    return in;
}

ostream& operator << (ostream& out, const cDaThuc &a)
{
    bool first = true;
    for(int i = a.n; i >= 0; i--)
    {
        if(a.heso[i] == 0)
            continue;
        if(!first && a.heso[i] > 0)
            out << "+";
        first = false;

        if(i == 0)
            out << a.heso[i];
        else if(i == 1)
        {
            if(a.heso[i] == 1)
                out << "x";
            else if(a.heso[i] == -1)
                out << "-x";
            else
                out << a.heso[i] << "x";
        }
        else
        {
            if(a.heso[i] == 1)
                out << "x^" << i;
            else if(a.heso[i] == -1)
                out << "-x^" << i;
            else
                out << a.heso[i] << "x^" << i;
        }
    }
    if(first)
        out << 0;
    
    return out;
}