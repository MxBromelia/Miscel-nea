#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int cases;
	int num;
	int pivot;
	vector<int> alt;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cases;
	while(cases > 0)
	{
		cases--;

		cin >> num;

		while(num>0)
		{
			cin >> pivot;
			alt.emplace_back(pivot);

			num--;
		}

		sort(alt.begin(), alt.end());

		for(int k: alt)
		{
			cout << k << ' ';
		}
		cout << '\n';
	}
	return 0;
}