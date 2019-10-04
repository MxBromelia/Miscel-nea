#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int cases;
	int num;
	int pivot;
	int i;
	vector<int> alt;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cases;
	while(cases > 0)
	{
		cases--;

		cin >> num;

		for(i=0;i<num;i++)
		{
			cin >> pivot;
			alt.emplace_back(pivot);
		}

		sort(alt.begin(), alt.end());

		for(i=0;i<num-1;i++)
			cout << alt[i] << ' ';
		cout << alt[i] << '\n';
		alt.clear();
	}
	return 0;
}