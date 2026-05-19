#include <iostream>
#include <climits>
#include "CVector.h"

using namespace std;

CVector::CVector()
{
    n = 0;
    v = NULL;
}

CVector::CVector(int soChieu)
{
    n = soChieu;
    if(n > 0)
        v = new double[n]{0};
    else
        v = NULL;
}

CVector::CVector(const CVector &other)
{
    n = other.n;
    v = new double[n];
    for(int i = 0; i < n; i++)
        v[i] = other[i];
}

CVector::~CVector()
{
    delete[] v;
    v = NULL;
}

CVector CVector::operator+ (const CVector &other) const
{
    if(n != other.n)
    {
        cout << "Không cộng được!\n";
        return CVector();
    }

    CVector res(n);
    for(int i = 0; i < n; i++)
        res[i] = v[i] + other[i];
    return res;
}

CVector CVector::operator- (const CVector &other) const
{
    if(n != other.n)
    {
        cout << "Không trừ được!\n";
        return CVector();
    }

    CVector res(n);
    for(int i = 0; i < n; i++)
        res[i] = v[i] - other[i];
    return res;
}

CVector CVector::operator* (double k) const
{
    CVector res(*this);
    for(int i = 0; i < n; i++)
        res[i] = k*res[i];
    return res;
}

CVector operator* (double k, const CVector &other)
{
    CVector res(other);
    for(int i = 0; i < other.n; i++)
        res[i] = k*res[i];
    return res;
}

double operator* (const CVector &a, const CVector &b)
{
    if(a.n != b.n)
    {
        cout << "Không nhân vô hướng được!";
        return INT_MIN;
    }
    double sum = 0;
    for(int i = 0; i < a.n; i++)
        sum += a[i] * b[i];
    return sum;
}

double& CVector::operator[](int index)
{
    return v[index];
}

const double& CVector::operator[](int index) const
{
    return v[index];
}

CVector& CVector::operator= (const CVector &other)
{
    if(this == &other)
        return *this;

    delete[] v;

    n = other.n;

    if(n > 0)
    {
        v = new double[n];
        for(int i = 0; i < n; i++)
            v[i] = other[i];
    }
    else
        v = NULL;

    return *this;
}

istream& operator>> (istream& in, CVector &v)
{
    while(true){
        cout << "Nhập số chiều: ";
        in >> v.n;
        if(in.fail() || in.peek() != '\n' || v.n < 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }
        break;
    }

    delete[] v.v;
    v.v = new double[v.n];
    while(true){
        bool fail = false;
        cout << "Nhập dữ liệu vector: ";
        for(int i = 0; i < v.n; i++)
        {
            in >> v[i];
            if(in.fail())
            {
                fail = true;
                break;
            }
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

ostream& operator<< (ostream& out, const CVector &v)
{
    out << '(';
    for(int i = 0; i < v.n; i++)
    {
        if(i == v.n - 1)
            out << v[i];
        else
            out << v[i] << ", ";
    }
    out << ')';
    return out;
}