#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char base32(int alg)
{
	if(alg<10)
		return '0' + alg;
	else
		return 55 + alg;
}
int main()
{
	unsigned long long number;
	vector<char> b32;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> number;

	while(number > 0)
	{
		while(number > 0)
		{
			b32.emplace_back(base32(number%32));
			number = number >> 5;
		}
		reverse(b32.begin(), b32.end());
		
		for(auto &c: b32)
			cout << c;
		cout << '\n';
		b32.clear();

		cin >> number;
	}

	cout << "0\n";

	return 0;
}