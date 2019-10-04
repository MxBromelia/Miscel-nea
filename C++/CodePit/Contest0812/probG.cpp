#include <iostream>

using namespace std;

int main()
{
	int maior, menor;
	int i;
	int number;
	int altura[100];

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> number;

	maior = 0;
	menor = 0;

	for(i=0;i<number;i++)
	{
		cin >> altura[i];

		if(altura[i] > maior)
			maior = i;
		else
			if(altura[i] < menor)
				menor = i;
	}

	cout << maior + (number-menor-1) + (maior < menor) << '\n';

	return 0;
}