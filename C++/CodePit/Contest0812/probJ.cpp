#include <iostream>

using namespace std;

int main()
{
	long long num, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	if(num > 2)
	{
		if(num%2)
		{
			k = (num*num-1)/2;
			cout << k << " " << k+1 << '\n';
		}
		else
		{
			k = (num*num-4)/4;
			cout << k << " " << k+2 << '\n';
		}
	}
	else
		cout << "-1\n";

	return 0;
}