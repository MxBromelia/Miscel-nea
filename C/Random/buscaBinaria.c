#include<stdio.h>

int main()
{
	int v[] = {1,6,11,16,21,26,31,36,41,46,51,56};
	int i, k;

	int top, bottom;

	for(i=1;i<2;i++)
	{
		top = 0;
		bottom = 11;

		while(top > bottom)
		{
			k = (top+bottom)/2;

			if(i > v[k])
				bottom = k;
			else
				top = k;
		}

		printf("%2d - %2d|%2d\n", i, k, v[k]);
	}

	return 0;
}