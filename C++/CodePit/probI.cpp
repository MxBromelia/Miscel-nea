#include<iostream>
#include<string>

using namespace std;

int main()
{
	string remix;
	string buffer;
	int i;
	size_t pos1, pos2;

	cin >> remix;

	pos1 = remix.find("WUB");

	while(pos1 != string::npos)
	{
		pos2 = remix.find("WUB", pos1+1);

		buffer = remix.substr(pos1+3, pos2-pos1-3);

		cout << buffer<< " ";

		pos1 = pos2;
	}

	cout << endl;

	return 0;
}