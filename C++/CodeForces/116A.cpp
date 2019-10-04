#include <iostream>

using namespace std;

int main()
{
	int num;
	int in, out;
	int passengers = 0;
	int max = 0;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	while(num)
	{
		cin >> out >> in;

		passengers -= out;
		passengers += in;

		if(passengers > max)
			max = passengers;

		num--;
	}

	cout << max;

	return 0;
}