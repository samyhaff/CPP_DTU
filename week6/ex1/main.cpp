#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    int a, b, c, d;
    string op, bar;
    Fraction f1, f2;

    while (cin >> a >> bar >> b >> op >> c >> bar >> d) {
        f1 = Fraction(a, b);
        f2 = Fraction(c, d);

        if (op == "+") f1.add(f2);
        else if (op == "*") f1.mult(f2);
        else f1.div(f2);

        f1.display(); cout << endl;
    }

    return 0;
}
