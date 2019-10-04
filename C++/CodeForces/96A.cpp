#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned int i;
	int group = 0;
	char current;
	string pos;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> pos;

	current = pos[0];
	for(i=1;group < 6 && i<pos.size();i++)
	{
		if(pos[i] == current)
			group++;
		else
		{
			group = 0;
			current = pos[i];
		}
	}

	cout << (group == 6 ? "YES" : "NO");

	return 0;
}