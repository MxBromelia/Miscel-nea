#include<stdint.h>
#include<inttypes.h>
#include<wctype.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct map_inst {
	uint16_t pos[2];
};

struct map {
	uint32_t size;
	uint8_t *layout;
	struct map_inst insts;
	struct map_inst *ch;
};

void map_make(struct map *map)
{
	uint32_t size = size;

	uint32_t in = rand() % size;
	uint32_t out = rand() % size;

	for(uint32_t i = 0; i < size; i++)
		map->layout[i] = 'X';

	//layout[out] = 'O';
	//layout[size*(size-1)+in] = 'O';
}

void map_draw(const uint8_t map[], const uint32_t size)
{
	
	for (uint32_t i=0; i < size + 2; i++)
		printf("#");
	printf("\n");

	for(uint32_t i=0; i < size*10; i+=10)
	{
		printf("#");
		for(uint32_t j=0; j < size; j++)
			printf("%c", map[i+j]);
		printf("#\n");
	}

	for (uint32_t i=0; i < size + 2; i++)
		printf("#");
	printf("\n");
}

int main()
{	
	uint8_t test[10*10] = {[0 ... 99]='X'};
	struct map map;
	map.size = 10;
	map.layout = (uint8_t*) malloc(sizeof(uint8_t)*(map.size)*(map.size));

	srand(time(NULL));
	setlocale(LC_ALL,"");

	map_make(&map);
	map_draw(test,10);

	return 0;
}