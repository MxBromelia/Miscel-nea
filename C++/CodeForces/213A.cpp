#include <iostream>

using namespace std;

int main()
{
	int num;
	int resp[3];
	int r = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	while(num)
	{
		num--;

		cin >> resp[0] >> resp[1] >> resp[2];

		r += (resp[0]+resp[1]+resp[2])/2;
	}

	cout << r << '\n';

	return 0;
}