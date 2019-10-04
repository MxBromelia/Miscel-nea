#include <iostream>

using namespace std;

int main()
{
	unsigned int pointer_a;
	unsigned int pointer_b;
	int cycles;
	int cores;
	int index;
	int inst;
	char label[] = {'R', 'W'};
	string buffer;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> buffer >> cores)
	{
		index = (buffer[0] == 'R' ? 0 : 1);
		cycles = 0;
		pointer_a = 0;

		while(pointer_a != string::npos)
		{
			pointer_b = buffer.find(label[index], pointer_a+1);

			inst = (pointer_b != string::npos ? pointer_b : buffer.length()) - pointer_a;
			if(index == 0)
			{
				cycles = cycles + inst;
			}
			else
			{
				cycles = cycles + inst/cores + (inst % cores != 0);
				cout << inst << '/' << cores << " = " << inst/cores << '\n';	
			}

			index = (index+1)%2;
			pointer_a = pointer_b;
		}

		cout << cycles << '\n';
	}

	return 0;
}