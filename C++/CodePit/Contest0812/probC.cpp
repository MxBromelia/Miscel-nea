#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned int i;
	int N;
	int cifra;
	string cifrado;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N > 0)
	{
		N--;

		cin >> cifrado >> cifra;


		for(i=0;i<cifrado.size();i++)
			cout << (char)(65 + (cifrado[i] - 39 - cifra)%26);
		cout << '\n';
	}

	return 0;
}