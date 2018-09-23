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

int firstMethod(int x_0) {
	int a = 7;
	int c = 13;
	int m = 3571;
	int x_n1 = (a*x_0 + c) % m;
	intervalsDistribution((float)x_n1 / m);
	return x_n1;
}

int secondMethod(int x_0) {
	int a = 156;
	int c = 13;
	int m = 1025;
	int d = 65;
	int x_n1 = (d*x_0*x_0 + a * x_0 + c) % m;
	intervalsDistribution((float)x_n1 / m);
	return x_n1;
}

int thirdMethod(int x_0) {
	int prev = x_0;
	int m = 3571;
	int x_n1 = (x_0 + prev) % m;
	intervalsDistribution(float(x_n1) / m);
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
	intervalsDistribution(float(x_n1) / m);
	return x_n1;
}

//int fifthMethod(int x_0) {
	//int m = 1489;
	 //x_0 = thirdMethod(x_0);
	// y= firstMethod(y);
	//int x_n1 = abs(x_0 - y) % m;
	//intervalsDistribution(float(x_n1) / m);
	//return x_n1;
//}

//int sixthMethod(int x_0) {

//}
int main() {

	int x_0;
	cout << "x_0= ";
	cin >> x_0;
	int methodType;
	cout << "Method number: ";
	cin >> methodType;
	for (int i = 0; i < 200; i++)
	{
		cout << x_0 << " ";
		switch (methodType) {

		case 1: x_0 = firstMethod(x_0); break;
		case 2: x_0 = secondMethod(x_0); break;
		case 3: x_0 = thirdMethod(x_0); break;
		case 4: x_0 = fourthMethod(x_0); break;
			//	case 5: x_0 = fifthMethod(x_0); break;
				//case 6: x_0 = sixthMethod(x_0); break;
		default: break;
		}
	}
	/*for (int i = 0; i < 500; i++)
	{
		cout << x_0 << " ";
		intervalsDistribution(float(x_0) / m);
		//x_0 = pFunc(x_0);
	}*/
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << intervals[i] / 200 << endl;
	}
	system("pause");
	return 0;
}


/*int methodType;
cout << "Method number: ";
cin >> methodType;
switch (methodType) {
case 1:
	for (int i = 0; i < 200; i++)
	{
		cout << x_0 << " ";
		x_0 = firstMethod(x_0);
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << intervals[i] / 200 << endl;
	}
	break;
case 2:
	for (int i = 0; i < 200; i++)
	{
		cout << x_0 << " ";
		x_0 = secondMethod(x_0);
	}
	 cout << endl;
	 for (int i = 0; i < 10; i++)
	{
		cout << intervals[i] / 200 << endl;
	}
	 break;
case 3:
	for (int i = 0; i < 20; i++)
	{//		cout << x_0 << " ";
		x_0 = thirdMethod(x_0);
		//cout<<i<<"" << thirdMethod(i);
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << intervals[i] / 200 << endl;
	}
	break;
//case'4':
case 5:
	for (int i = 0; i < 200; i++)
	{
		cout << x_0 << " ";
		x_0 = fifthMethod(x_0);
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << intervals[i] / 200 << endl;
	}
	break;*/

