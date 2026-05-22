#include<iostream>
#include <Windows.h>
#include "cTime.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    cTime a, b;

    cout << "Nhập thời gian a\n";
    cin >> a;

    cout << "Nhập thời gian b\n";
    cin >> b;

    cout << "\na = " << a << '\n';
    cout << "b = " << b << '\n';

    cout << "\na++ = " << a++ << '\n';
    cout << "Sau a++ : " << a << '\n';

    cout << "\n++b = " << ++b << '\n';
    cout << "Sau ++b : " << b << '\n';

    cout << "\n--a = " << --a << '\n';
    cout << "Sau --a : " << a << '\n';

    cout << "\nb-- = " << b-- << '\n';
    cout << "Sau b-- : " << b << '\n';

    int giay;

    cout << "\nNhập số giây cần cộng: ";
    cin >> giay;

    //a sử dụng kết quả a sau --a và k thay đổi a
    cout << "a + " << giay << " giây = "
         << a + giay << '\n';

    cout << "a - " << giay << " giây = "
         << a - giay << '\n';

    return 0;
}