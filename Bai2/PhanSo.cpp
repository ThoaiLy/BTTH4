#include <iostream>
#include <numeric>
#include "PhanSo.h"

using namespace std;

istream& operator >> (istream& in, PhanSo& ps)
{
    while(true)
    {
        cout << "Nhập tử số và mẫu số: ";
        in >> ps.iTu >> ps.iMau;
        if(in.fail() || in.peek() != '\n' || ps.iMau == 0)
        {
            cout << "Dữ liệu nhập sai!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }
        break;
    }
    ps.RutGon();
    return in;
}

ostream& operator << (ostream& out, const PhanSo& ps)
{
    if(ps.iTu == 0)
        out << 0;
    else if(ps.iMau == 1)
        out << ps.iTu;
    else
        out << ps.iTu << "/" << ps.iMau;
    return out;
}

PhanSo::PhanSo(int tu, int mau)
{
    iTu = tu;
    iMau = mau;

    RutGon();
}

PhanSo::PhanSo(const PhanSo& other)
{
    iTu = other.iTu;
    iMau = other.iMau;

    RutGon();
}

void PhanSo::RutGon()
{
    if(iMau < 0)
    {
        iTu = -iTu;
        iMau = -iMau;
    }
    int g = gcd(abs(iTu), abs(iMau));
    iTu = iTu / g;
    iMau = iMau / g;
}

PhanSo PhanSo::operator + (const PhanSo& other) const
{
    return PhanSo(iTu * other.iMau + iMau * other.iTu, iMau * other.iMau);
}

PhanSo PhanSo::operator + (int a) const
{
    return PhanSo(iMau * a + iTu, iMau);
}

PhanSo operator + (int a, const PhanSo& other)
{
    return PhanSo(a * other.iMau + other.iTu, other.iMau);
}

PhanSo PhanSo::operator - (const PhanSo& other) const
{
    return PhanSo(iTu * other.iMau - iMau * other.iTu, iMau * other.iMau);
}

PhanSo PhanSo::operator - (int a) const
{
    return PhanSo(iTu - iMau * a, iMau);
}

PhanSo operator - (int a, const PhanSo& other)
{
    return PhanSo(a * other.iMau - other.iTu, other.iMau);
}

PhanSo PhanSo::operator * (const PhanSo& other) const
{
    return PhanSo(iTu * other.iTu, iMau * other.iMau);
}

PhanSo PhanSo::operator * (int a) const
{
    return PhanSo(iTu * a, iMau);
}

PhanSo operator * (int a, const PhanSo& other)
{
    return PhanSo(a * other.iTu, other.iMau);
}

PhanSo PhanSo::operator / (const PhanSo& other) const
{
    if(other.iTu == 0)
    {
        cout << "Không thể chia cho 0!\n";
        return PhanSo();
    }
    return PhanSo(iTu * other.iMau, iMau * other.iTu);
}

PhanSo PhanSo::operator / (int a) const
{
    if(a == 0)
    {
        cout << "Không thể chia cho 0!\n";
        return PhanSo();
    }
    return PhanSo(iTu, iMau * a);
}

PhanSo operator / (int a, const PhanSo& other)
{
    if(other.iTu == 0)
    {
        cout << "Không thể chia cho 0!\n";
        return PhanSo();
    }
    return PhanSo(a * other.iMau, other.iTu);
}

bool PhanSo::operator == (const PhanSo& other) const
{
    return iTu * other.iMau == iMau * other.iTu;
}

bool PhanSo::operator > (const PhanSo& other) const
{
    return iTu * other.iMau > iMau * other.iTu;
}

bool PhanSo::operator < (const PhanSo& other) const
{
    return iTu * other.iMau < iMau * other.iTu;
}