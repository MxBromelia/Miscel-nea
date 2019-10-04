#include <iostream>
#include <string>

using namespace std;

const int led[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	int N;
	unsigned int i;
	int leds;
	string num;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N > 0)
	{
		N--;
		leds = 0;

		cin >> num;

		for(i=0;i<num.length();i++)
			leds = leds + led[(int)num[i]-'0'];

		cout << leds << " leds\n";
	}

	return 0;
}