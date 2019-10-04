#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const char vowel[] = "aeiou";

int main()
{
	int i_0, i_f;
	string risada;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> risada;

	i_0 = 0;
	i_f = risada.length()-1;

	while(i_0 < i_f)
	{
		while(! strchr(vowel, risada[i_0]))
			i_0++;

		while(! strchr(vowel, risada[i_f]))
			i_f--;

		if(risada[i_0] != risada[i_f])
			break;

		i_0++;
		i_f--;
	}

	cout << ((i_0<i_f)?("N\n"):("S\n"));

	return 0;
}