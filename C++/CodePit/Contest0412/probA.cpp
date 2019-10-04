#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	double media;
	int N = 0;
	int num;
	string s;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin.ignore();
	while(getline(cin, s), cin >> num)
	{
		media = media + num;
		N++;

		cin.ignore();
	}
	cout << fixed << setprecision(1) << media/N << '\n';

	return 0;
}