#include <iostream>
#include <Windows.h>
#include "PhanSo.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    PhanSo a, b;
    cout << "Nhập phân số a\n"; cin >> a;
    cout << "Nhập phân số b\n"; cin >> b;

    cout << "\na = " << a << '\n';
    cout << "b = " << b << '\n';

    cout << "\na + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';
    cout << "a / b = " << a / b << '\n';

    if(a == b)
        cout << "Hai phân số bằng nhau";
    else if(a > b)
        cout << "Phân số a lớn hơn phân số b";
    else
        cout << "Phân số a nhỏ hơn phân số b";

    return 0;
}