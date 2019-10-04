#include <iostream>

using namespace std;

int main()
{
	int num;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	cout << (((num % 4) && (num % 7) && (num % 44) && (num % 47) && (num % 74) && (num % 77) && (num % 444) && (num % 447) && (num % 474) && (num % 477) && (num % 744) && (num % 747) && (num % 774) && (num % 777))?("NO\n"):("YES\n"));

	return 0;
}