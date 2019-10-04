#include <iostream>

using namespace std;

int main()
{
	char row[51];
	int len;
	int i;
	int eq = 0;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> len >> row;

	for(i=1;i<len;i++)
		if(row[i] == row[i-1])
			eq++;

	cout << eq << '\n';

	return 0;
}