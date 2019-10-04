#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, dif, N, sum;
	string A,B;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N>0)
	{
		cin >> A >> B;

		sum = 0;
		for(i=0;i<(int)A.length();i++)
		{
			dif = B[i]-A[i];

			if(dif < 0)
				dif = dif + 26;
			sum += dif;
		}
		cout << sum << '\n';

		N--;
	}

	return 0;
}