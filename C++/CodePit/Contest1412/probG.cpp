#include <iostream>
#include <vector>
#include <algorithm>

#define abs(x) (x > 0 ? x : -x)
#define pir(x, i, j) x[i+j][j]

using namespace std;

int dif[90][90];

int main()
{
	int i, j;
	int k, l;
	int n, r;
	int pivot;
	int found;

	vector<int> rest;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r;

	while( n != 0 && r != 0)
	{
		for(i=0;i<r; i++)
		{
			cin >> pivot;
			rest.emplace_back(pivot);
		}

		sort(rest.begin(), rest.end());

		for(i=0; i<r;i++)
		{
			for(j=i; j<r; j++)
			{
				dif[i][j] = abs((rest[j]-rest[i]));
				//cout << dif[i][j] << ' ';
			}
			//cout << '\n';
		}

		rest.clear();

		for(k = n, found = 1; k >= 0 && found; k--)
		{
			found = 0;
			//cout << "k = " << k << '\n';
			for(l = 0; l<= n-k && !found; l++)
			{
				//cout << "l = " << l << '\n';
				for(i = 0, j = r-l-1; j <= r-1 && !found; i++, j++)
				{
					//cout << "(i, j) = (" << i <<',' << j << ")\n";
					//cout << "dif(i,j) = " << dif[i][j] << "; k = " << k << '\n';
					if(dif[i][j] == k)
					{
						//cout << "Found!\n";
						found = 1;
					}
				}
			}
		}

		if(found == 1)
			cout << "Y\n";
		else
			cout << "N\n";

		cin >> n >> r;
	}

	return 0;
}