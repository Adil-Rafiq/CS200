
#ifndef complex_h
#define complex_h

class Complex
{
    float real, img;

public:
    Complex(){};
    void setRealValue(float);
    float getRealValue();
    void setImgValue(float);
    float getImgValue();
    void assign(Complex);
    void sum(Complex, Complex);
    void multiply(Complex, Complex);
    void inputNumber();
    void print();
};

#endif
