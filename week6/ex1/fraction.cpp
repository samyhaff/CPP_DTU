#include <iostream>
#include "fraction.h"

using namespace std;

Fraction::Fraction() {
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::mult(Fraction f) {
    this->numerator *= f.numerator;
    this->denominator *= f.denominator;
    this->simplify();
}

void Fraction::div(Fraction f) {
    this->numerator *= f.denominator;
    this->denominator *= f.numerator;
    this->simplify();
}

void Fraction::add(Fraction f) {
    this->numerator = this->numerator * f.denominator
        + this->denominator * f.numerator;
    this->denominator *= f.denominator;
    this->simplify();
}

void Fraction::display() {
    cout << numerator << " / " << denominator;
}
