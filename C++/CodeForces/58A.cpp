#include <iostream>
#include <string>

using namespace std;

int main()
{
	string buffer;
	string out = "NO";
	size_t pos;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> buffer;

	if((pos = buffer.find('h', 0)) != string::npos)
		if((pos = buffer.find('e', pos+1)) != string::npos)
			if((pos = buffer.find('l', pos+1)) != string::npos)
				if((pos = buffer.find('l', pos+1)) != string::npos)
					if((pos = buffer.find('o', pos+1)) != string::npos)
						out = "YES";

	cout << out << '\n';

	return 0;
}