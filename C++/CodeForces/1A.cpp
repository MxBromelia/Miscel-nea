#include <iostream>

using namespace std;

int main()
{
	int m, n;

	long long a;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> a;

	cout << ((m/a)+(m%a!=0))*((n/a)+(n%a!=0));

	return 0;
}