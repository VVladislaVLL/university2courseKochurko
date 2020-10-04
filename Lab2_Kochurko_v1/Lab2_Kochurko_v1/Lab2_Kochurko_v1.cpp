#include <stdio.h>
#include <cmath>
#include "Complex.h"

const int N = 5;

Complex* createVector(const int N)
{
	Complex* vector = new Complex[N];
	return vector;
}

Complex* sumCopmplexVector(Complex* firstVector, Complex* secondVector)
{
	Complex* resultVector = new Complex[N];
	for (int i = 0; i < N; i++)
	{
		resultVector[i] = Complex(firstVector[i] + secondVector[i]);
	}
	return resultVector;
}

void printComplexVector(Complex* resultVector)
{
	for (int i = 0; i < N; i++)
	{
		resultVector[i].print();
		printf("\n");
	}
}

int main()
{
	Complex* firstVector;
	firstVector = createVector(N);
	firstVector[0] = Complex(1, 2);
	firstVector[1] = Complex(3, 4);
	firstVector[2] = Complex(5, 6);
	firstVector[3] = Complex(7, 8);
	firstVector[4] = Complex(9, 10);

	Complex* secondVector;
	secondVector = createVector(N);
	secondVector[0] = Complex(1, 2);
	secondVector[1] = Complex(3, 4);
	secondVector[2] = Complex(5, 6);
	secondVector[3] = Complex(7, 8);
	secondVector[4] = Complex(9, 10);

	Complex* resultVector;
	resultVector = sumCopmplexVector(firstVector, secondVector);
	printComplexVector(resultVector);

	return 0;
}