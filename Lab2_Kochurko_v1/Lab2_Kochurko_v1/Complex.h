#pragma once
#include <stdio.h>
#include <cmath>

class Complex {
	friend Complex operator++(Complex b);
	friend Complex operator++(Complex b, int t);
private:
	double re;
	double im;
	int* arr;
	static int counter;
public:
	Complex();
	Complex(double _re, double _im);
	Complex(double b);
	Complex(const Complex& obj);
	~Complex();
	static void showCount();
	int& operator[](int index);
	double* get();
	void set(double re, double im);
	double getRe();
	double getIm();
	void setRe(double b);
	void setIm(double b);
	void print();
	double abs();
	Complex operator+(Complex b);
	Complex operator+(double b);
	Complex operator-(Complex b);
	Complex operator-(double b);
	Complex operator*(Complex b);
	Complex operator*(double b);
	Complex operator/(Complex b);
	Complex operator/(double b);
	Complex& operator=(const Complex& b);
};