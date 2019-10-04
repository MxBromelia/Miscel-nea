#include <iostream>
#include <string>

using namespace std;

int bracketsCheck(string operation)
{
	int i;
	int len = operation.size();
	int brackets = 0;

	for(i=0;i<len;i++)
	{
		if(operation[i] == '(')
			brackets++;
			else
				if(operation[i] == ')')
				{
					brackets--;

					if(brackets<0)
						return 0;
				}
	}

	if(brackets != 0)
		return 0;

	return 1;
}


int main()
{
	int n;
	char buffer[1001];

	cin >> n;

	while(n > 0)
	{
		cin >> buffer;

		if(bracketsCheck(buffer) == 0)
			cout << "in";
		cout << "correct" << endl;

		n--;
	}

	return 0;
}
