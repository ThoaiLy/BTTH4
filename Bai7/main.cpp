#include <iostream>
#include <Windows.h>
#include "cMatrix.h"
#include "CVector.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    cMatrix A, B;
    CVector v;

    cout << "Nhập ma trận A:\n";
    cin >> A;
    cout << "Nhập ma trận B:\n";
    cin >> B;

    cout << "\nMa trận A:\n";
    cout << A;
    cout << "Ma trận B:\n";
    cout << B;

    cout << "\nA + B:\n";
    cout << A + B;
    cout << "\nA - B:\n";
    cout << A - B;
    cout << "\nA * B:\n";
    cout << A * B;

    int k;
    cout << "\nNhập k: "; cin >> k;
    cout << k << " * A:\n" << k * A << '\n'; 
    cout <<"B * " << k << ":\n" << B * k << '\n'; 

    cout << "\nNhập vector v:\n";
    cin >> v;
    cout << "\nVector v = " << v << '\n';

    cout << "\nA * v = ";
    cout << A * v << '\n';

    return 0;
}