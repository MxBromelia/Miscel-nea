#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned int i, j;
	unsigned int N;
	unsigned int maior;
	string nome[50];

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N>0)
	{
		maior = 0;
		for(i=0;i<N;i++)
		{
			cin >> nome[i];

			if(nome[i].length() > maior)
				maior = nome[i].length();
		}

		for(i=0;i<N;i++)
		{
			for(j=0;j<maior - nome[i].length(); j++)
				cout << ' ';

			cout << nome[i] << '\n';
		}
		cin >> N;

		if(N>0)
			cout << '\n';
	}

	return 0;
}