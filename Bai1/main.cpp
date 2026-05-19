#include<iostream>
#include<iomanip>
#include <Windows.h>
#include "SoPhuc.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    SoPhuc a, b;
    cout << "Nhập số phức a\n";
    cin >> a;
    cout << "Nhập số phức b\n";
    cin >> b;

    cout << "\na = " << a << '\n';
    cout << "b = " << b << '\n';

    cout << "\na + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';
    cout << "a / b = " << a / b << '\n';

    if(a == b)
        cout << "\nHai số phức bằng nhau.\n";
    else
        cout << "\nHai số phức không bằng nhau.\n";

    return 0;
}