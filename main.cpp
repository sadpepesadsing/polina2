#include <iostream>
#include "a.h"

int main() {
    mnog a(4, new int[4]{5, 1, 2, 3}, 2);
    mnog b(3, new int[3]{4, 7, 10}, 3);
    cout << "a + b = " << a + b << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    a = b;
    cout << "a = b: " << a << endl;
    mnog c(4, new int[4]{5, 1, 2, 3}, 2);
    mnog d(3, new int[3]{4, 7, 10}, 3);
    cout << "c - d = " << c - d << endl;
    mnog e(4, new int[4]{5, 1, 2, 3}, 2);
    mnog f(3, new int[3]{4, 7, 10}, 3);
    cout << "e * f = " << e * f << endl;
    mnog g(4, new int[4]{8, 1, 2, 3}, 2);
    mnog h(3, new int[3]{4, 7, 10}, 3);
    cout << "g = " << g << endl;
    cout << "h = " << h << endl;
    cout << "g / h = " << g / h << endl;
}
