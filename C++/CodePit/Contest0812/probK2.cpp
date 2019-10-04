#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float cycles=0;
	int cores;
	string buffer;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> buffer >> cores)
	{
		for(char c: buffer)
			if(c == 'R')
				cycles += (double)1/cores;
			else
				cycles++;

		cout << (int)(cycles)/*+(cycles - floor(cycles) == 0) */<< '\n';
	}

	return 0;
}