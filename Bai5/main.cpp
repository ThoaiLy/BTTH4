#include <iostream>
#include <Windows.h>
#include "cDaThuc.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    cDaThuc a, b;
    cout << "Nhập đa thức a\n";
    cin >> a;
    cout << "Nhập đa thức b\n";
    cin >> b;

    cout << "\na = " << a << '\n';
    cout << "b = " << b << '\n';

    cout << "\na + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';
    
    return 0;
}