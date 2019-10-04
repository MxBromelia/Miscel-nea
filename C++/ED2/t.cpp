#include<iostream>

using namespace std;

int main()
{
	int *a = new int[3]{1,2,3};

	for(int i=0;i<4;i++)
		cout << a[i] << " ";
	cout << endl;

	delete[] a;

	for(int i=0;i<3;i++)
		cout << a[i] << " ";
	cout << endl;

	a = new int[7];

	for(int i=0;i<7;i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}