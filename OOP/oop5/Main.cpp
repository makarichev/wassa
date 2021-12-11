#include <iostream>
#include <Windows.h>
using namespace std;




template<class T>
void randomize(T* a, int size) {

	srand(static_cast<unsigned int>(time(0)));
	int r0 = rand();

	for (int i = 0; i < size; i++) {
		double f = 100 * (double)rand() / RAND_MAX;
		a[i] = f;
	}
}



void randomize(char* a, int size, string symbols) {
	cout << "overload for char" << endl;


	srand(static_cast<unsigned int>(time(0)));
	int r0 = rand();

	for (int i = 0; i < size; i++) {
		int f = symbols.length() * rand() / RAND_MAX;
		a[i] = symbols[f];
	}


}



template<class T>
int minPosition(T* a, int size) {

	int min = 0;

	for (int i = 0; i < size; i++)
		if (a[i] <= a[min]) min = i;
	
	return min;
}

template<class T>
void print(T* a, int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i];
		if (i != size - 1) cout << ',';
	}
	cout << endl;
}



int main()
{
	SetConsoleOutputCP(1251);

	int size = 20;

	cout << "int array:" << endl;

	int* intArray = new int[size];
	randomize(intArray, size);
	print(intArray, size);

	int min = minPosition(intArray, size);
	cout << "Минимальное значение:" << intArray[min] << " в позиции:" << min << endl;

	delete[] intArray;



	cout << "double array:" << endl;

	double* dblArray = new double[size];
	randomize(dblArray, size);
	print(dblArray, size);

	min = minPosition(dblArray, size);
	cout << "Минимальное значение:" << dblArray[min] << " в позиции:" << min << endl;


	delete[] dblArray;




	cout << "char array:" << endl;

	char* charArray = new char[size];
	
	randomize(charArray, size, "xo");
	print(charArray, size);

	min = minPosition(charArray, size);
	cout << "Минимальное значение:" << charArray[min] << " в позиции:" << min << endl;




	delete[] charArray;


}

