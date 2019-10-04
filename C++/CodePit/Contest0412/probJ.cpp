#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N;
	unsigned int i;
	int dif;
	char numA[1001], numB[1001];
	char* pivot;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N>0)
	{
		N--;

		cin >> numA >> numB;

		dif = strlen(numA) - strlen(numB);

		if(dif >= 0)
		{
			pivot = numA + dif;

			for(i=0;i<strlen(numB);i++)
				if(pivot[i] != numB[i])
				{
					cout << "nao ";
					break;
				}
		}
		else
			cout << "nao ";
		cout << "encaixa\n";
	}

	return 0;
}