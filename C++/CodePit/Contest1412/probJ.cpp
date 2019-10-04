#include <iostream>

using namespace std;

typedef struct
{
	int num;
	int freq;
}
Num;

int main()
{
	Num it;
	int it_1;
	int it_2;
	int len = 0;
	int in;

	cin >> in;

	Num out[in];

	for(it_1=0;it_1 < in; it_1++)
	{
		cin >> it.num;
		it.freq = 1;

		//Busca
		it_2 = 0;
		while(it_2 < len && out[it_2].num != it.num)
			it_2++;

		//Inserção
		if(it_2 < len)
			out[it_2].freq++;
		else
		{
			it_2--;
			while(out[it_2].num > it.num && it_2 >= 0)
			{
				out[it_2+1] = out[it_2];
				it_2--;
			}
			out[it_2+1] = it;
			len++;
		}
	}

	for(it_1 = 0; it_1 < len; it_1++)
		cout << out[it_1].num << " aparece " << out[it_1].freq << " vez(es)\n";

	return 0;
}