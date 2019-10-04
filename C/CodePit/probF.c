#include <stdio.h>
#include <string.h>

int main()
{
	char str1[51], str2[51];
	int N;
	int i, pos;

	scanf("%d", &N);

	while(N > 0)
	{
		scanf("%s %s", str1, str2);

		for(i=0, pos=0; i<=strlen(str1)+strlen(str2); i=i+2, pos++)
		{
			if(pos < strlen(str1))
				printf("%c", str1[pos]);
			if(pos < strlen(str2))
				printf("%c", str2[pos]);
		}
		printf("\n");

		N--;
	}

	return 0;
}