#include <iostream>

using namespace std;

int pig[5];

int main()
{
	int people;
	int numGroup;
	int taxis;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> people;

	while(people)
	{
		people--;
		cin >> numGroup;

		pig[numGroup]++;
	}

	taxis = pig[4] + pig[3];
	pig[1] = (pig[1]-pig[3])*(pig[1] > pig[3]);
	taxis+= pig[2]/2 + pig[2]%2;
	pig[1] -= 2*(pig[2]%2);
	pig[1] *= (pig[1] > 0);
	taxis += (pig[1]/4) + ((pig[1] % 4) != 0);

	cout << taxis;

	return 0;
}