#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int num[20];
	int i;

	for(i=0; i<20;i++)
		cin >> num[i];

	for(i=0;i<20;i++)
		cout << "N[" << i << "] = " << num[19-i] << '\n';

	return 0;
}