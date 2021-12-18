#include <iostream>
using namespace std;


class CircularMatrix {
	int n = 0;
	double* a;
public:
	CircularMatrix(int n) {
		this->n = n;
		a = new double[n];
		a[0] = 10 * n;
		for (int i = 1; i < n; i++)
			a[i] = n - i;
	}

	CircularMatrix(double* a, int n) {
		this->n = n;
		this->a = new double[n];
		for (int i = 0; i < n; i++)
			this->a[i] = a[i];

	}


	void Print() {



		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';

		cout << endl;
	}




	void CalcX(double* x)
	{

		double* y = new double[n];

		double* xprev = new double[n + 1];
		double* yprev = new double[n + 1];


		int k = 0;
		x[k] = 1 / a[0];
		y[k] = 1 / a[0];


		for (k = 1; k < n; k++)
		{

			double F = 0;
			double G = 0;

			for (int i = 0; i < k; i++)
			{
				F += a[k - i] * x[i];
				G += a[n - 1 - i] * y[i];
			}

			double r = 1 / (1 - (F * G));
			double s = -r * F;
			double t = -r * G;



			for (int i = 0; i <= k; i++)
			{
				xprev[i] = i == k ? 0 : x[i];
				yprev[i] = i == 0 ? 0 : y[i - 1];
			}


			for (int i = 0; i <= k; i++)
			{

				x[i] = xprev[i] * r + yprev[i] * s;
				y[i] = xprev[i] * t + yprev[i] * r;

			}




		}


		delete[] y;
		delete[] yprev;
		delete[] xprev;
	}




	void Calc(double* b, double* res) {
		double* x = new double[n];
		CalcX(x);

		for (int i = 0; i < n; i++) {
			res[i] = 0;
			for (int j = 0; j < n; j++) {
				int k = i - j >= 0 ? i - j : n + (i - j);
				res[i] += x[k] * b[j];
			}
		}

		delete[] x;
	}


	~CircularMatrix() {
		delete[] a;
	}

};
