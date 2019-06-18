#ifndef __COMPLEX__
#define __COMPLEX__

#include<iostream>
using std::ostream;
using std::istream;
#include<cmath>


class Complex{
    friend istream& operator>>(istream& is, Complex& c);//we can also accomplish this function without friend

    private:
        double re, im;
    public:
        Complex(double real = 0, double imagine = 0) : re(real), im(imagine){ }
        
        double real() const {return re;}
        double imagine() const {return im;}
        
        Complex& operator+=(const Complex&);
        Complex& operator+=(const int&);
        Complex& operator-=(const Complex&);
        Complex& operator-=(const int&);
        Complex& operator*=(const Complex&);
        Complex& operator*=(const int&);
        Complex& operator/=(const Complex&);
        Complex& operator/=(const int&);
};

Complex& Complex::operator+=(const Complex& c){
    re += c.real();
    im += c.real();
    return *this;
}
Complex& Complex::operator+=(const int& c){
    re += c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c){
    re -= c.real();
    im -= c.imagine();
    return *this;
}
Complex& Complex::operator-=(const int& c){
    re -= c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c){
    re = re*c.real() - im*c.imagine();
    im = re*c.imagine() + im* c.real();
    return *this;
}
Complex& Complex::operator*=(const int& c){
    re *= c;
    im *= c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c){
    re = (re*c.real() + im*c.imagine()) / (c.real()*re - c.imagine()*im);
    im = (im*c.real() - re*c.imagine()) / (c.real()*re - c.imagine()*im);
    return *this;
}
Complex& Complex::operator/=(const int& c){
    re /= c;
    im /= c;
    return *this;
}

Complex operator+(const Complex& c){
    return c;
}
Complex operator-(const Complex& c){
    return Complex(-c.real(), -c.imagine());
}

Complex Conjuate(const Complex& c){
    return Complex(c.real(), -c.imagine());
}

ostream& operator<<(ostream& os, const Complex& c){
    os<<'('<<c.real()<<','<<c.imagine()<<')';
    return os;
}
istream& operator>>(istream& is,Complex& c){
    is>>c.re>>c.im;
    if(!is)
        c = Complex();
    return is;
}

Complex operator+(const Complex& a, const Complex& b){
    return Complex(a.real() + b.real(), a.imagine() + b.imagine());
}
Complex operator+(const int& a, const Complex& b){
    return Complex(a + b.real(), b.imagine());
}
Complex operator+(const Complex& a, const int& b){
    return Complex(a.real() + b, a.imagine());
}

Complex operator-(const Complex& a, const Complex& b){
    return Complex(a.real() - b.real(), a.imagine() - b.imagine());
}
Complex operator-(const Complex& a, const int& b){
    return Complex(a.real() - b, a.imagine());
}
Complex operator-(const int& a, const Complex& b){
    return Complex(a - b.real(), - b.imagine());
}

Complex operator*(const Complex& a, const Complex& b){
    return Complex(a.real()*b.real() - a.imagine()*b.imagine(), 
    a.real()*b.imagine() + a.imagine()*b.real());
}
Complex operator*(const int& a, const Complex& b){
    return Complex(a * b.real(), a * b.imagine());
}
Complex operator*(const Complex& a, const int& b){
    return Complex(a.real() * b, a.imagine() * b);
}

Complex operator/(const Complex& a, const Complex& b){
    auto _r = (a.real()*b.real() + a.imagine()*b.imagine()) / (b.real()*b.real() - b.imagine()*b.imagine());
    auto _i = (a.imagine()*b.real() - a.real()*b.imagine()) / (b.real()*b.real() - b.imagine()*b.imagine());
    return Complex(_r, _i);
}
Complex operator/(const int& a, const Complex& b){
    auto _r = a / (b.real()*b.real() - b.imagine()*b.imagine()) * b.real();
    auto _i = a / (b.real()*b.real() - b.imagine()*b.imagine()) * b.imagine();
    return Complex(_r, _i);
}
Complex operator/(const Complex& a, const int& b){
    return Complex(a.real() / b, a.imagine() / b);
}

bool operator==(const Complex& a, const Complex& b){
    return a.real() == b.real() && a.imagine() == b.imagine();
}
bool operator!=(const Complex& a, const Complex& b){
    return a.imagine() != b.imagine() || a.real() != b.real();
}

double abs(const Complex& c){
    return sqrt(c.real()*c.real() + c.imagine()*c.imagine());
}
#endif
