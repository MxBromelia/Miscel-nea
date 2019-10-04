#include <iostream>
#include <string>

using namespace std;

int main()
{
	char strfinal[101];
	string str1, str2;
	int str1_size, str2_size;

	int N;

	int pos;
	int i;

	cin >> N;

	while(N > 0)
	{
		cin >> str1;
		cin >> str2;

		str1_size = str1.size();
		str2_size = str2.size();

		for(i=0, pos = 0; i<= str1_size + str2_size; i = i+2, pos++)
		{
			if(pos < str1_size)
				strfinal[i] = str1[pos];

			if(pos < str2_size)
				strfinal[i+1] = str2[pos];
		}
		cout << strfinal << endl;

		N--;
	}

	return 0;
}