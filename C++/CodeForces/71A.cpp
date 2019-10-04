#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	int size;
	string word;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N > 0)
	{
		N--;

		cin >> word;

		size = word.size();

		if(size > 10)
			cout << word[0] << size-2 << word[size-1] << '\n';
		else
			cout << word << '\n';
	}

	return 0;
}