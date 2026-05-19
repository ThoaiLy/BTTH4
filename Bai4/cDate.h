#pragma once
#include <iostream>

using namespace std;

class cDate
{
    private:
        int iNgay, iThang, iNam;
    public:
        cDate();
        cDate(int ngay, int thang, int nam);
        cDate(const cDate& other);
        friend istream& operator >> (istream& in, cDate& d);
        friend ostream& operator << (ostream& out, const cDate& d);
        cDate& operator ++();
        cDate& operator --();
        cDate operator ++(int);
        cDate operator --(int);
        cDate operator +(int Ngay);
        cDate operator -(int Ngay);
        void Tang();
        void Giam();
};