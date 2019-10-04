#include <iostream>
#include <cstring>

using namespace std;

const char* vowel= "aeiouy";

int main()
{
	string word;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> word;

	for(char c: word)
	{
		c = c%32+96;
		if(strchr(vowel, c) == NULL)
			cout << '.' << c;
	}
	cout << '\n';

	return 0;
}