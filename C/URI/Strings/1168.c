#include <stdio.h>
#include <string.h>

int main()
{
	int trials;
	char num[103];

	int leds = 0;
	int led[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int i;

	scanf("%d", &trials);
	while(trials > 0)
	{
		scanf("%s", num);

		for(i=0;i<strlen(num);i++)
			leds += led[(int)num[i] - '0'];

		printf("%d leds\n", leds);

		leds = 0;
		trials--;
	}

	return 0;
}