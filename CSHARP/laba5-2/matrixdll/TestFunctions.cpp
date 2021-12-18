#include "pch.h"
#include "TestFunctions.h"
#include "CircularMatrix.h"

int Test1(const int n, const int repeats) {



	time_t tStart = time(nullptr);

	CircularMatrix m(n);

	double* b = new double[n];
	for (int i = 0; i < n; i++)
		b[i] = 1;

	double* res = new double[n];

	for (int i = 1; i < repeats; i++) {
		m.Calc(b, res);
	}

	delete[] b;
	delete[] res;

	time_t tEnd = time(nullptr);

	return tEnd - tStart;



}



void Calc(const int n, double* a, double* b, double* result) {

	CircularMatrix m(a, n);
	m.Calc(b, result);

}