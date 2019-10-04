#include <iostream>

using namespace std;

int main()
{
	int kg;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> kg;

	cout << (((kg < 4) | (kg % 2))?("NO"):("YES"));

	return 0;
}