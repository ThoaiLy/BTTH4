#include <iostream>
#include <Windows.h>
#include "cDate.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    cDate a, b;

    cout << "Nhập ngày a\n";
    cin >> a;

    cout << "Nhập ngày b\n";
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

    int ngay;

    //a sử dụng kết quả a sau --a và k thay đổi a
    cout << "\nNhập số ngày cần cộng/trừ: ";
    cin >> ngay;

    cout << "\na + " << ngay << " ngày = "
         << a + ngay << '\n';

    cout << "a - " << ngay << " ngày = "
         << a - ngay << '\n';

    return 0;
}