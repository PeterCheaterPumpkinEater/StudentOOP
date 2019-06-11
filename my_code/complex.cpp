#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

Complex::Complex(double real, double imag) : real(real), imag(imag) {};

bool operator== (const Complex& c1, const Complex& c2) {
    double r1 , r2, i1 , i2;
    r1 = c1.get_real();
    r2 = c2.get_real();
    i1 = c1.get_imag();
    i2 = c2.get_imag();
    return (r1 == r2 and i1 == i2);
}

bool operator-= (const Complex& c1, const Complex& c2) {
    return !(c1 == c2);
}

ostream& operator<< (ostream& os, const Complex& c) {
    double real, imag;
    real = c.get_real();
    imag = c.get_imag();
    os << real << " + " << imag << 'i';
    return os;
    
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    cout << "Real:" << endl;
    is >> c.real;
    cout << "Imaginary:" << endl;
    is >> c.imag;
    return is;
}


Complex::operator bool() const {
    double real, imag;
    real = this -> real;
    imag = this -> imag;
    return !(real == 0 and imag == 0);
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp = *this;
    real++;
    return temp;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator--(int dummy) {
    Complex temp = *this;
    real--;
    return temp;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    double r1 , r2, i1 , i2;
    r1 = c1.get_real();
    r2 = c2.get_real();
    i1 = c1.get_imag();
    i2 = c2.get_imag();
    Complex c3(r1 + r2, i1 + i2);
    return c3;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
    Complex c(i * real, i * imag);
    return c;
}

Complex Complex:: operator-=(const Complex& c) {
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
}
