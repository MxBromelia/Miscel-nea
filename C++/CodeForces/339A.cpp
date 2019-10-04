#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned int i, j;

	char pivot;
	string operation;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> operation;

	for(i = 2; i < operation.size(); i = i + 2)
	{
		pivot = operation[i];
		for(j = i - 2; j >= 0 && operation[j] > pivot; j = j - 2)
			operation[j + 2] = operation[j];
		operation[j+2] = pivot;
	}

	cout << operation << '\n';

	return 0;
}