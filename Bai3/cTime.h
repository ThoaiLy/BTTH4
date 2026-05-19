#pragma once
#include <iostream>

using namespace std;

class cTime
{
    private:
        int iGio, iPhut, iGiay;
    public:
        cTime();
        cTime(int h, int p, int s);
        cTime(const cTime& other);
        friend istream& operator >> (istream& in, cTime& t);
        friend ostream& operator << (ostream& out, const cTime& t);
        cTime& operator ++();
        cTime& operator --();
        cTime operator ++(int);
        cTime operator --(int);
        cTime operator +(int giay);
        cTime operator -(int giay);
        void Tang();
        void Giam();
};