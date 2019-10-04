#include <stdio.h>

int main()
{
	int nums[5];
	int i;

	int even = 0;

	for(i=0;i<5;i++)
	{
		scanf("%d", &nums[i]);

		if(nums[i] % 2 == 0)
			even++;
	}

	printf("%d valores pares\n", even);

	return 0;
}