#include <iostream>

using namespace std;

int main()
{
	int r[5];
	int num;
	int resp;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;
	while(num != 0)
	{
		while(num > 0)
		{
			cin >> r[0] >> r[1] >> r[2] >> r[3] >> r[4];

			resp = !(r[0]/128) + !(r[1]/128)*2 + !(r[2]/128)*4 + !(r[3]/128)*8 + !(r[4]/128)*16;

			switch(resp)
			{
				case 1:
					cout << "A\n";
					break;
				case 2:
					cout << "B\n";
					break;
				case 4:
					cout << "C\n";
					break;
				case 8:
					cout << "D\n";
					break;
				case 16:
					cout << "E\n";
					break;
				default:
					cout << "*\n";
					break;
			}

			num--;
		}
		cin >> num;
	}

	return 0;
}