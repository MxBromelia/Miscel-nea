#include <stdio.h>
#include <string.h>

int main()
{
	int cases;
	int open= 0;
	int close = 0;
	unsigned int i;
	char campo[1001];

	scanf("%d", &cases);

	while(cases > 0)
	{
		scanf("%s", campo);

		for(i=0;i<strlen(campo);i++)
			if(campo[i] == '<')
				open++;
			else
				if(open >= close && campo[i] == '>')
					close++;

		printf("%d\n", (open < close ? open : close));

		open = close = 0;
		cases--;
	}

	return 0;
}