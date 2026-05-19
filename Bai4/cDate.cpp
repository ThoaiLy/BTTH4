#include<iostream>
#include "cDate.h"

using namespace std;

cDate::cDate()
{
    iNgay = 1;
    iThang = 1;
    iNam = 2000;   
}

cDate::cDate(int ngay, int thang, int nam)
{
    iNgay = ngay;
    iThang = thang;
    iNam = nam;
}

cDate::cDate(const cDate& other)
{
    iNgay = other.iNgay;
    iThang = other.iThang;
    iNam = other.iNam;
}

istream& operator >> (istream& in, cDate& d)
{
    while (true)
	{
        cout << "Nhập ngày: ";
		in >> d.iNgay >> d.iThang >> d.iNam;
		if (in.fail() || in.peek() != '\n')
        {
            cout << "Dữ liệu nhập sai!\n";
            in.clear();
            in.ignore(10000, '\n');
            continue;
        }

		if (d.iNgay <= 0 || d.iThang <= 0 || d.iThang > 12 || d.iNam < 1800 || d.iNam > 2100 ) //Năm nhập chỉ giới hạn trong khoảng [1800 - 2100]
		{
			cout << "Dữ liệu nhập sai!\n";
			in.clear();
			in.ignore(10000, '\n');
			continue;
		}

		if (d.iThang == 2)
		{
			if ((d.iNam % 4 == 0 && d.iNam % 100 != 0) || d.iNam % 400 == 0)
			{
				if (d.iNgay > 29)
				{
					cout << "Dữ liệu nhập sai!\n";
					in.clear();
					in.ignore(10000, '\n');
					continue;
				}
			}
			else
			{
				if (d.iNgay > 28)
				{
					cout << "Dữ liệu nhập sai!\n";
					in.clear();
					in.ignore(10000, '\n');
					continue;
				}
			}
		}

		else if (d.iThang == 1 || d.iThang == 3 || d.iThang == 5 || d.iThang == 7 || d.iThang == 8 || d.iThang == 10 || d.iThang == 12)
		{
			if (d.iNgay > 31)
			{
				cout << "Dữ liệu nhập sai!\n";
				in.clear();
				in.ignore(10000, '\n');
				continue;
			}
		}

		else
		{
			if (d.iNgay > 30)
			{
				cout << "Dữ liệu nhập sai!\n";
				in.clear();
				in.ignore(10000, '\n');
				continue;
			}
		}

		break;
	}
    return in;
}

ostream& operator << (ostream& out, const cDate& d)
{
    out << d.iNgay << "/" << d.iThang << "/" << d.iNam;
    return out;
}

cDate& cDate::operator ++()
{
    Tang();
    return *this;
}

cDate& cDate::operator --()
{
    Giam();
    return *this;
}

cDate cDate::operator ++(int)
{
    cDate tmp = *this;
    Tang();
    return tmp;
}

cDate cDate::operator --(int)
{
    cDate tmp = *this;
    Giam();
    return tmp;
}

cDate cDate::operator +(int Ngay)
{
	cDate temp = *this;

    for(int i = 0; i < Ngay; i++)
        temp.Tang();

    return temp;
}

cDate cDate::operator -(int Ngay)
{
	cDate temp = *this;

    for(int i = 0; i < Ngay; i++)
        temp.Giam();

    return temp;
}

void cDate::Tang()
{
    if (iThang == 2)
	{
		if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
		{
			if (iNgay == 29)
			{
				iNgay = 1;
				iThang++;
			}
			else
				iNgay++;
		}
		else
		{
			if (iNgay == 28)
			{
				iNgay = 1;
				iThang++;
			}
			else
				iNgay++;
		}
	}
	else if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12)
	{
		if (iThang == 12 && iNgay == 31)
		{
			iThang = 1;
			iNgay = 1;
			iNam++;
		}
		else if (iNgay == 31)
		{
			iThang++;
			iNgay = 1;
		}
		else
			iNgay++;
	}
	else
	{
		if (iNgay == 30)
		{
			iThang++;
			iNgay = 1;
		}
		else
			iNgay++;
	}
}

void cDate::Giam()
{
    iNgay--;
    if(iNgay == 0)
    {
        iThang--;

        if(iThang == 0)
        {
            iThang = 12;
            iNam--;
        }

        if(iThang == 2)
        {
            if((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
                iNgay = 29;
            else
                iNgay = 28;
        }
        else if(iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11)
        {
            iNgay = 30;
        }
        else
        {
            iNgay = 31;
        }
    }
}