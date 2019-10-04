#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int i, j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	j = 0;
	for(i=1; i<= n; i++)
	{
		switch(i%4)
		{
			case 1:
				while(j<m)
				{
					cout << '#';
					j++;
				}
				cout << '\n';
				break;
			case 2:
				while(j>1)
				{
					cout << '.';
					j--;
				}
				j--;
				cout << "#\n";
				break;
			case 3:
				while(j<m)
				{
					cout << '#';
					j++;
				}
				cout << '\n';
				break;
			case 0:
				cout << '#';
				while(j>1)
				{
					cout << '.';
					j--;
				}
				j--;
				cout << '\n';
				break;
		}
	}

	return 0;
}