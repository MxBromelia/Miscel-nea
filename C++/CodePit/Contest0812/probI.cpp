#include <iostream>

using namespace std;

int main()
{
	int k_1, k_2, N;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	k_1 = (N%2 ? 9 : 4);
	k_2 = N - k_1;

	if(k_1 > k_2)
		cout << k_2 << ' ' << k_1 << '\n';
	else
		cout << k_1 << ' ' << k_2 << '\n';

	return 0;
}