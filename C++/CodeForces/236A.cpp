#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	unsigned int i, j;

	char nick[101];
	char unique[101];

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> nick;

	unique[0] = nick[0];

	for(i=1, j=1;i<strlen(nick);i++)
		if(strchr(unique, nick[i]) == NULL)
		{
			unique[j] = nick[i];
			j++;
		}
	unique[j] = '\0';

	if(strlen(unique) % 2)
		cout << "IGNORE HIM!" << '\n';
	else
		cout << "CHAT WITH HER!" << '\n';

	return 0;
}