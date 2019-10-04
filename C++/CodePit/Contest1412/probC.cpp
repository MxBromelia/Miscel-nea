#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int cases;
	int num;
	int insts[101];
	int i;
	int pos;
	char* k;

	string inst;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cases;

	while(cases>0)
	{
		cin >> num;
		pos = 0;

		for(i=1;i<=num;i++)
		{
			cin >> inst;

			insts[i] = (inst[0] == 'L') - (inst[0] == 'R');

			if(! insts[i])
			{
				insts[i] = atoi((k = &inst[8]));
				insts[i] = insts[insts[i]];
			}

			pos = pos + insts[i];
		}
		cout << pos << '\n';
		num--;
	}

	return 0;
}