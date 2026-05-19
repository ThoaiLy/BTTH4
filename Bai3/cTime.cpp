#include<iostream>
#include "cTime.h"

using namespace std;

istream& operator >> (istream& in, cTime& t)
{
    while(true)
    {
        cout << "Nhập thời gian: ";
        in >> t.iGio >> t.iPhut >> t.iGiay;

        if(in.fail() || in.peek() != '\n')
        {
            cout << "Dữ liệu nhập sai!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }

        if(t.iGio < 0 || t.iGio >= 24 || t.iPhut < 0 || t.iPhut >= 60 || t.iGiay < 0 || t.iGiay >= 60) //Mặc định 24h là 0h
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

ostream& operator << (ostream& out, const cTime& t)
{
    if(t.iGio < 10) out << "0";
    out << t.iGio << ":";

    if(t.iPhut < 10) out << "0";
    out << t.iPhut << ":";

    if(t.iGiay < 10) out << "0";
    out << t.iGiay;

    return out;
}

cTime::cTime()
{
    iGio = iPhut = iGiay = 0;
}

cTime::cTime(int h, int p, int s)
{
    iGio = h;
    iPhut = p;
    iGiay = s;
}

cTime::cTime(const cTime& other)
{
    iGio = other.iGio;
    iPhut = other.iPhut;
    iGiay = other.iGiay;
}

cTime& cTime::operator ++()
{
    Tang();
    return *this;
}

cTime& cTime::operator --()
{
    Giam();
    return *this;
}

cTime cTime::operator ++(int)
{
    cTime temp = *this;
    Tang();
    return temp;
}

cTime cTime::operator --(int)
{
    cTime temp = *this;
    Giam();
    return temp;
}

cTime cTime::operator + (int giay)
{
    cTime tmp;
    int TongGiay = iGio * 3600 + iPhut * 60 + iGiay + giay;

    TongGiay %= 86400;

    if(TongGiay < 0) // tránh trường hợp - số giây khiến tổng bị âm
        TongGiay += 86400;
    
    tmp.iGio = TongGiay / 3600;
    TongGiay %= 3600;
    tmp.iPhut = TongGiay / 60;
    iGiay = TongGiay % 60;

    return tmp;
}

cTime cTime::operator - (int giay)
{
    return *this + (-giay);
}

void cTime::Tang()
{
    iGiay++; 
    if(iGiay == 60)
    {
        iGiay = 0;
        iPhut++;
        if(iPhut == 60)
        {
            iPhut = 0;
            iGio++;
            if(iGio == 24)
            {
                iGio = 0;
            }
        }
    }
}
void cTime::Giam()
{
    iGiay--; 
    if(iGiay == -1)
    {
        iGiay = 59;
        iPhut--;
        if(iPhut == -1)
        {
            iPhut = 59;
            iGio--;
            if(iGio == -1)
            {
                iGio = 23;
            }
        }
    }
}