#include <iostream>

using namespace std;

double Newton(double* Arg, double* Val, int size, double x)
{
	double** wspolczynniki = new double*[size];
	for (int i = 0; i < size; i++)
	{
		wspolczynniki[i] = new double[size - i-1];
	}

	for (int i = 0; i < size-1;i++)
	{
		wspolczynniki[0][i] = (Val[i + 1] - Val[i]) / (Arg[i+1]-Arg[i]);
	}

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i - 1;j++)
		{
			wspolczynniki[i][j] = (wspolczynniki[i - 1][j + 1] - wspolczynniki[i - 1][j]) / (Arg[j+i+1]-Arg[j]);
			//cout << "(" <<wspolczynniki[i - 1][j + 1] << " - " << wspolczynniki[i - 1][j] << ")" << " / (" << Arg[j + i+1] << " - " << Arg[j] << ")" << endl;
		}
	}
	/*
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i-1; j++)
		{
			cout << wspolczynniki[i][j] << ", ";
		}
		cout << endl;
	}
	*/

	double result = Val[0];
	cout << Val[0];
	double tmp=1;
	for (int i = 0; i < size - 1; i++)
	{
		//cout << "+" << wspolczynniki[i][0] << " * " << tmp <<endl;
		tmp *= (x - Arg[i]);
		result += wspolczynniki[i][0] * tmp;
	}

	for (int i = 0; i < size; i++)
	{
		delete [] wspolczynniki[i];
	}
	delete [] wspolczynniki;
	return result;
}

void fill(double* T, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> T[i];
	}
}


int main()
{

	int size;
	cout << "Podaj liczbe znanych punktow w wielomianie" << endl;
	cin >> size;
	double* Arg = new double[size];
	double* Val = new double[size];
	cout << "Podaj argumenty znanych punktow" << endl;
	fill(Arg, size);
	cout << "Podaj wartosci w znanych punktach" << endl;
	fill(Val, size);
	cout << "Podaj liczbe dla ktorej chcesz policzyc wartosc wielomianu" << endl;
	int x;
	cin >> x;
	cout << "Wartosc funkcji w tym punkcie wynosi: " << Newton(Arg, Val, size, x) << endl;
	delete[] Arg;
	delete[] Val;
	system("pause");
}