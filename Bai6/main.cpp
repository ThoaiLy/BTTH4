#include <iostream>
#include <Windows.h>
#include "CVector.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    CVector a, b;

    cout << "Nhập vector a:\n";
    cin >> a;

    cout << "\nNhập vector b:\n";
    cin >> b;

    cout << "\na = " << a << '\n';
    cout << "b = " << b << '\n';

    cout << "\na + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';

    double tichVoHuong = a * b;
    if(tichVoHuong != INT_MIN)
        cout << "a * b = " << tichVoHuong << '\n';

    double k;
    cout << "\nNhập số thực k: ";
    cin >> k;

    cout << "a * k = " << a * k << '\n';
    cout << "k * b = " << k * b << '\n';


    return 0;
}