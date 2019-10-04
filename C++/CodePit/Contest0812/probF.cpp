#include <iostream>

using namespace std;

int main()
{
	long long n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << (n%2 ? -(n+1)/2 : n/2) << '\n';

	return 0;
}