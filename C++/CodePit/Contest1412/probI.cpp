#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int cases;
	int num;
	int pivot;
	int swaps;
	int i,j;

	vector<int> vagao;

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
			vagao.emplace_back(pivot);
		}

		swaps = 0;
		for(i=0;i<num-1;i++)
			for(j=i+1;j<num;j++)
				if(vagao[i] > vagao[j])
				{
					swaps++;

					pivot = vagao[i];
					vagao[i] = vagao[j];
					vagao[j] = pivot;
				}

		cout << "Optimal train swapping takes " << swaps << " swaps.\n";
		vagao.clear();
	}

	return 0;
}