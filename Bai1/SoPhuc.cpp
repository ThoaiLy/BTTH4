#include <iostream>
#include "SoPhuc.h"

using namespace std;

istream& operator >> (istream& in, SoPhuc& sp)
{
    while(true)
    {
        cout  << "Nhập phần thực: ";
        in >> sp.dThuc;
        if(in.fail() || in.peek() != '\n')
        {
            cout << "Nhập sai dữ liệu!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }
        break;
    }

    while(true)
    {
        cout << "Nhập phần ảo: ";
        in >> sp.dAo;
        if(in.fail() || in.peek() != '\n')
        {
            cout << "Nhập sai dữ liệu!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }
        break;
    }
    return in;
}

ostream& operator << (ostream& out, const SoPhuc& sp)
{
    if(sp.dThuc == 0)
    {
        if(sp.dAo == 1)
            out << "i";
        else if(sp.dAo == -1)
            out << "-i";
        else if(sp.dAo == 0)
            out << 0;
        else
            out << sp.dAo << "i";
    }
    else
    {
        out << sp.dThuc;

        if(sp.dAo > 0)
        {
            if(sp.dAo == 1)
                out << "+i";
            else
                out << "+" << sp.dAo << "i";
        }
        else if(sp.dAo < 0)
        {
            if(sp.dAo == -1)
                out << "-i";
            else
                out << sp.dAo << "i";
        }
    }
    return out;
}

SoPhuc::SoPhuc(double thuc, double ao)
{
    dThuc = thuc;
    dAo = ao;
}

SoPhuc SoPhuc::operator + (const SoPhuc& other) const
{
    return SoPhuc(dThuc + other.dThuc, dAo + other.dAo);
}

SoPhuc SoPhuc::operator + (double a) const
{
   return SoPhuc(a + dThuc, dAo);
}

SoPhuc operator + (double a, const SoPhuc& other)
{
    return SoPhuc(a + other.dThuc, other.dAo);
}

SoPhuc SoPhuc::operator - (const SoPhuc& other) const
{
    return SoPhuc(dThuc - other.dThuc, dAo - other.dAo);
}

SoPhuc SoPhuc::operator - (double a) const
{
   return SoPhuc(dThuc - a, dAo);
}

SoPhuc operator - (double a, const SoPhuc& other)
{
    return SoPhuc(a - other.dThuc, -other.dAo);
}

SoPhuc SoPhuc::operator *(const SoPhuc& other) const
{
    return SoPhuc(
        dThuc * other.dThuc - dAo * other.dAo,
        dThuc * other.dAo + dAo * other.dThuc
    );
}

SoPhuc SoPhuc::operator * (double a) const
{
    return SoPhuc(a * dThuc, a * dAo);
}

SoPhuc operator * (double a, const SoPhuc& other)
{
    return SoPhuc(a * other.dThuc, a * other.dAo);
}

SoPhuc SoPhuc::operator / (const SoPhuc& other) const
{
    double mau = other.dThuc * other.dThuc + other.dAo * other.dAo;

    if(mau == 0)
    {
        cout << "Không thể chia!\n";
        return SoPhuc();
    }

    return SoPhuc(
        (dThuc * other.dThuc + dAo * other.dAo) / mau,
        (dAo * other.dThuc - dThuc * other.dAo) / mau
    );
}

SoPhuc SoPhuc::operator / (double a) const
{
    if(a == 0)
    {
        cout << "Không thể chia!\n";
        return SoPhuc();
    }

    return SoPhuc(dThuc / a, dAo / a);
}

SoPhuc operator / (double a, const SoPhuc& other)
{
    double mau = other.dThuc * other.dThuc
               + other.dAo * other.dAo;

    if(mau == 0)
    {
        cout << "Không thể chia!\n";
        return SoPhuc();
    }
    return SoPhuc(
        a * other.dThuc / mau,
        -a * other.dAo / mau
    );
}

bool SoPhuc::operator == (const SoPhuc& other)
{
    return dThuc == other.dThuc && dAo == other.dAo;
}

bool SoPhuc::operator != (const SoPhuc& other)
{
    return !(*this == other);
}