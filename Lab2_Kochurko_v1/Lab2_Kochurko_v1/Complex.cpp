#include <stdio.h>
#include <cmath>
#include "Complex.h"

int Complex::counter = 0;

Complex::Complex() : re(0), im(0)
{
	arr = new int[100];
	counter++;
}

Complex::Complex(double _re, double _im) : re(_re), im(_im) 
{
	arr = new int[100];
	counter++;
}

Complex::Complex(double b) : re(b), im(0) 
{
	arr = new int[100];
	counter++;
};

Complex::Complex(const Complex& obj) 
{
	this->re = obj.re;
	this->im = obj.im;
	this->arr = new int[100];
	for (int i = 0; i < 100; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}

Complex::~Complex()
{
	delete[] arr;
}

void Complex::print()
{
	printf("%s%f", "Re = ", re);
	printf("%s%f", "\tIm = ", im );
	printf("\n%f%+f%s", re, im, "i\n");
}

void Complex::showCount()
{
	printf("%s%d%c", "Counter = ",counter, '\n');
}

double Complex::abs()
{
	return sqrt(re * re + im * im);
}

double* Complex::get()
{
	double complexNumber[2];
	complexNumber[0] = this->re;
	complexNumber[1] = this->im;
	return complexNumber;
}

void Complex::set(double re, double im)
{
	this->re = re;
	this->im = im;
}

double Complex::getRe()
{
	return this->re;
}

void Complex::setRe(double b)
{
	this->re = b;
}

double Complex::getIm()
{
	return this->im;
}

void Complex::setIm(double b)
{
	this->im = b;
}

Complex Complex::operator+(Complex b)
{
	return Complex(this->re + b.re, this->im + b.im);
}

Complex Complex::operator+(double b) 
{
	return Complex(this->re + b, this->im);
}

Complex Complex::operator-(Complex b) 
{
	return Complex(this->re - b.re, this->im - b.im);
}

Complex Complex::operator-(double b)
{
	return Complex(this->re - b, this->im);
}

Complex Complex::operator*(Complex b)
{
	return Complex(this->re * b.re - this->im * b.im, this->re * b.im + this->im * b.re);
}

Complex Complex::operator*(double b)
{
	return Complex(this->re * b - this->im * 0, this->re * 0 + this->im * b);
}

Complex Complex::operator/(Complex b)
{
	return Complex((this->re * b.re + this->im * b.im) / ((b.re * b.re) + (b.im * b.im)), (b.re * this->im - b.im * this->re) / ((b.re * b.re) + (b.im * b.im)));
}

Complex Complex::operator/(double b)
{
	return Complex((this->re * b + this->im * 0) / (b * b), (b * this->im - 0 * this->re) / (b * b));

}

Complex& Complex::operator=(const Complex &b)
{
	this->re = b.re;
	this->im = b.im;
	this->arr = new int[100];
	for (int i = 0; i < 100; i++)
	{
		this->arr[i] = b.arr[i];
	}
	return *this;
}

Complex operator++(Complex b)
{
	return Complex(b.re + 1, b.im);
}

Complex operator++(Complex b, int t)
{
	return Complex(b.re + 1, b.im);
}

int& Complex::operator[](int index)
{
	return arr[index];
}


