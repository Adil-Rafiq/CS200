
#include <iostream>
using namespace std;

#include "complex.h"

int main()
{
    Complex c1, c2, c3, sum, product;
    c1.inputNumber();
    c1.print();

    c2.setRealValue(4);
    c2.setImgValue(3);
    c2.print();

    c3.assign(c2);
    c3.print();

    sum.sum(c1, c3);
    sum.print();

    product.multiply(c1, c2);
    product.print();

    return 0;
}
