#include <iostream>

using namespace std;

//int x;

int main()
{
	int num;
	int x = 0;
	char op[3];

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	while(num > 0)
	{
		cout << num << '\n';
		num--;

		cin >> op;
		if(op[1] == '+')
			x++;
		else
			x--;
	}

	cout << x << '\n';

	return 0;
}