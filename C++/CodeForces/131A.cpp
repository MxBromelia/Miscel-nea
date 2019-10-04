#include <iostream>
#include <string>

using namespace std;

int main()
{
	string buffer;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> buffer;

	if(buffer[0]/32 == 3)
	{
		for(char &c: buffer)
			c = c+32;
		buffer[0] -= 64;
	}

	cout << buffer;

	return 0;
}