#include <iostream>
using namespace std;
#include "complex.h"

void Complex::setRealValue(float input)
{
    real = input;
}

float Complex::getRealValue()
{
    return real;
}

void Complex::setImgValue(float input)
{
    img = input;
}

float Complex::getImgValue()
{
    return img;
}

void Complex::assign(Complex c)
{
    real = c.real;
    img = c.img;
}

void Complex::sum(Complex c1, Complex c2)
{
    real = c1.real + c2.real;
    img = c1.img + c2.img;
}

void Complex::multiply(Complex c1, Complex c2)
{
    real = (c1.real * c2.real) - (c1.img * c2.img);
    img = (c1.real * c2.img) + (c1.img * c2.real);
}

void Complex::print()
{
    cout << real << " + " << img << "i" << endl;
}

void Complex::inputNumber()
{
    cout << "Enter real part: ";
    cin >> real;
    cout << "Enter imaginary part: ";
    cin >> img;
}

