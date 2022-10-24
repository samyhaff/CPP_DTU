#pragma once

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual double height() = 0;
    virtual double width() = 0;
    virtual void rotate() = 0;
};

class Rectangle : public Shape {
protected:
    double h;
    double w;
public:
    Rectangle(double h, double w);
    virtual double area();
    virtual double perimeter();
    virtual double height();
    virtual double width();
    virtual void rotate();
};

class Square : public Rectangle {
public:
    Square(double length);
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double radius);
    virtual double area();
    virtual double perimeter();
    virtual double height();
    virtual double width();
    virtual void rotate();
};
