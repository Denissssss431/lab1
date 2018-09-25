#include <iostream>
using namespace std;

double intervals[10] = {};

void intervalsDistribution(double x) {
	if (x > 0 && x <= 0.1) { intervals[0]++; }
	else if (x > 0.1 && x <= 0.2) { intervals[1]++; }
	else if (x > 0.2 && x <= 0.3) { intervals[2]++; }
	else if (x > 0.3 && x <= 0.4) { intervals[3]++; }
	else if (x > 0.4 && x <= 0.5) { intervals[4]++; }
	else if (x > 0.5 && x <= 0.6) { intervals[5]++; }
	else if (x > 0.6 && x <= 0.7) { intervals[6]++; }
	else if (x > 0.7 && x <= 0.8) { intervals[7]++; }
	else if (x > 0.8 && x <= 0.9) { intervals[8]++; }
	else if (x > 0.9 && x <= 1) { intervals[9]++; }
}

void anotherIntervalsDistribution(double mas[])
{
	for (int i = 0; i < 200; i++)
	{
		if (mas[i] > -3 && mas[i] <= -2.4) { intervals[0]++; }
		else if (mas[i] > -2.4 && mas[i] <= -1.8) { intervals[1]++; }
		else if (mas[i] > -1.8 && mas[i] <= -1.2) { intervals[2]++; }
		else if (mas[i] > -1.2 && mas[i] <= -0.6) { intervals[3]++; }
		else if (mas[i] > -0.6 && mas[i] <= 0.0) { intervals[4]++; }
		else if (mas[i] > 0.0 && mas[i] <= 0.6) { intervals[5]++; }
		else if (mas[i] > 0.6 && mas[i] <= 1.2) { intervals[6]++; }
		else if (mas[i] > 1.2 && mas[i] <= 1.8) { intervals[7]++; }
		else if (mas[i] > 1.8 && mas[i] <= 2.4) { intervals[8]++; }
		else if (mas[i] > 2.4 && mas[i] <= 3) { intervals[9]++; }
	}
}
int x_n = 5, y_n = 2, mod = 0;

int firstMethod(int x_0) {
	int a = 7;
	int c = 13;
	int m = 3571;
	int x_n1 = (a*x_0 + c) % m;
	return x_n1;
}

int secondMethod(int x_0) {
	int a = 156;
	int c = 13;
	int m = 1025;
	int d = 65;
	int x_n1 = (d*x_0*x_0 + a * x_0 + c) % m;
	return x_n1;
}

int thirdMethod(int x_0) {
	int prev = x_0;
	int m = 3571;
	int x_n1 = (x_0 + prev) % m;
	return x_n1;
}

int fourthMethod(int x_0) {
	int value = 0;
	int a = 7;
	int c = 13;
	int m = 3571;
	while (x_0*value % m != 1)
	{
		value++;
	}
	if (value == m)
	{
		value = 0;
	}
	int x_n1 = (a * value + c) % m;
	return x_n1;
}

int fifthMethod(int x_0) {
	int m = 797;
	x_n = firstMethod(x_n);
	y_n = secondMethod(y_n);
	int x_n1 = abs(x_n - y_n) % m;
	return x_n1;
}

int sixthMethod(int x_0) {
	double value = x_0;
	int m = 3571;
	double intervals[200] = {};
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			value = firstMethod(value);
			intervals[i] += value / m;
		}
		intervals[i] -= 6;
		cout << intervals[i] << " ";
	}
	anotherIntervalsDistribution(intervals);
	return value;
}
int main() {

	
	int methodType;
	cout << "Method number: ";
	cin >> methodType;
	int x_0;
	cout << "x_0= ";
	cin >> x_0;
	int(*pMethods)(int) = nullptr;
		switch (methodType) {

		case 1: pMethods = firstMethod; mod = 3571; break;
		case 2: pMethods = secondMethod; mod = 1025; break;
		case 3: pMethods = thirdMethod; mod = 3571; break;
		case 4: pMethods = fourthMethod; mod = 3571; break;
		case 5: pMethods = fifthMethod; mod = 797; break;
		case 6: pMethods = sixthMethod; break;
		default: cout << "There is no method with this number"; break;
		}
		
		x_0 = pMethods(x_0);
		if (methodType >= 1 && methodType <= 5) {
			for (int i = 0; i < 200; i++)
			{
				cout << x_0 << " ";
				intervalsDistribution(float(x_0) / mod);
				x_0 = pMethods(x_0);
			}
		}
		else if(methodType>=6 && methodType<=8 )
		{
		
		}
	for (int i = 0; i < 10; i++)
	{
		cout <<endl<< intervals[i] / 200;
	}
	cout << "" << endl;
	system("pause");
	return 0;
}

