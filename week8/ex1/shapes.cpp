#include <math.h>
#include "shapes.h"

Rectangle::Rectangle(double h, double w) {
    this->h = h;
    this->w = w;
}

double Rectangle::perimeter() {
    return 2 * h + 2 * w;
}

double Rectangle::area() {
    return w * h;
}

double Rectangle::height() {
    return h;
}

double Rectangle::width() {
    return w;
}

void Rectangle::rotate() {
    double tmp = h;
    h = w;
    w = tmp;
}

Square::Square(double length)
:Rectangle(length, length) { }

Circle::Circle(double radius) {
    this->radius = radius;
}

double Circle::area() {
    return M_PI * radius * radius;
}

double Circle::perimeter() {
    return 2 * M_PI * radius;
}

double Circle::height() {
    return 2 * radius;
}

double Circle::width() {
    return 2 * radius;
}

void Circle::rotate() {}
