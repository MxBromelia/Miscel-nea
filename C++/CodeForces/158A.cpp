#include <iostream>

using namespace std;

int main()
{
	int i;
	int n, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	int a[n];

	for(int &p: a)
		cin >> p;

	if(a[k-1] > 0)
	{
		while(a[k] == a[k-1])
			k++;
		cout << k;
	}
	else
	{
		i = k-2;

		while(i>-1 && a[i] == 0)
			i--;

		cout << i+1;
	}

	return 0;
}