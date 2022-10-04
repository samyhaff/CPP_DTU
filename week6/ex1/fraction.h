#ifndef _fraction_h
#define _fraction_h

#include <numeric>

class Fraction {

private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction();
    Fraction(int n, int d);

    void add(Fraction f);
    void mult(Fraction f);
    void div(Fraction f);

    void display(void);
};

#endif
