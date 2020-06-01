/*
 * Complex.h
 *
 *  Created on: Sep 8, 2019
 *      Author: yunus
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Complex {
  // global block
  friend ostream& operator << (ostream &out, const Complex &c);
  friend istream& operator >> (istream &in, Complex &c);
  friend Complex operator + (const Complex &c1, const Complex &c2);
  // must overload > and < here to compare Complex objs in ComplexDB
  friend bool operator > (Complex &c1, Complex &c2);
  friend bool operator < (Complex &c1, Complex &c2);
  // we also need to overload the == operator - the = operator is already overloaded
  friend bool operator == (const Complex &c1, const Complex &c2);

public:
  Complex();
  // default constructor
  Complex(double r, double i);
  // regular constructor, real = r and imaginary = i
  Complex(const Complex &c);
  // copy constructor

  // operators
  double operator + (int i);
  Complex operator - (const Complex &c) {
    Complex c1;
    c1.real = real - c.real;
    c1.imaginary = imaginary - c.imaginary;
    return c1;
  }
  Complex operator - (int i) {
    Complex r;
    r.real = real - i;
    return r;
  }
  Complex& operator = (const Complex &c) {
    if (this == &c)
      return *this;
    real = c.real;
    imaginary = c.imaginary;
    return *this;
  }

  // find the value of any complex number
  // value of a+bi = sqrt((a*a)+(b*b))
  double find_value();

  // setter and getter functions
  // bc for some reason, Eclipse won't let me use private data members in friend functions
  void set_real(double REAL), set_imaginary(double IMAGINARY);
  double get_real() const, get_imaginary() const;
  void set_complex(double REAL, double IMAGINARY);
private:
  double real, imaginary;
};

#endif /* COMPLEX_H_ */
