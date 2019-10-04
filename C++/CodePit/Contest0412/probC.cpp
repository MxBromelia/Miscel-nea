#include <iostream>
#include <map>	

using namespace std;

int main()
{
	
	int n;
	int sum;
	char number[10];

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n, cin >> number)
	{
		sum = 0;
		while(n>0)
		{
			n--;
			sum += number[n] - '0';
		}

		cout << sum << " ";

		if(sum%3)
			cout << "nao" << '\n';
		else
			cout << "sim" << '\n';
	}

	return 0;
}