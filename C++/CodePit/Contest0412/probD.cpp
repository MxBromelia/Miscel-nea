#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//Variáveis
	int N;
	double suprimentos;
	int dias;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	//Algoritmo

	cin >> N;

	while(N>0)
	{
		cin >> suprimentos;

		for(dias=0;suprimentos>1;dias++)
			suprimentos /= 2;

		cout << dias << " dias\n";

		N--;
	}

	return 0;
}