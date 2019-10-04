#include <stdio.h>

int main()
{
	int i;
	int positivo = 0;
	
	double nums[6];
	double media;

	for(i=0;i<6;i++)
	{
		scanf("%lf", &nums[i]);

		if(nums[i]>0)
		{
			positivo++;

			media = media + nums[i];
		}
	}

	media = media/positivo;

	printf("%d valores positivos\n", positivo);
	printf("%.1lf\n", media);

	return 0;
}