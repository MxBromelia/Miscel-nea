#include <stdio.h>
#include <string.h>

int main()
{
	char remix[201];
	char *pos1, *pos2;
	int len, i;

	scanf("%s", remix);

	pos1 = strchr(remix, 'W');

	while(pos1 != NULL)
	{
		pos2 = strchr(pos1+1, 'W');

		if(*(pos1+1) == 'U' && *(pos1+2) == 'B')
		{
			while(pos2 != NULL && (*(pos2+1) != 'U' || *(pos2+2) != 'B'))
			{
				pos2 = strchr(pos2+1, 'W');
			}

			pos1 = pos1+3;
			len = (pos2 != NULL)?(pos2-pos1):(strlen(remix)-(int)pos1+1);

			for(i = 0; i < len; i++)
			{
				printf("%c", *(pos1+i));
			}

			if(len != 0)
				printf(" ");
		}

		pos1 = pos2;
	}

	return 0;
}