#include <iostream>
#include "CircularMatrix.h"


using namespace std;

int main()
{
	int n = 50000;
	CircularMatrix m(n);
	

	double* b = new double[n];
	for (int i = 0; i < n; i++)
		b[i] = 1;

	double* res = new double[n];

	m.Calc(b, res);


	//for (int i = 0; i < n; i++)
	//	cout << res[i] << '\t';

	//cout << endl;


	delete[] res;


}
