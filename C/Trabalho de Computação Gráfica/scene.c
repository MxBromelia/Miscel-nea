#include "scene.h"
#include "texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct polygon
{
	int num;
	float *x, *y, *z;
};

struct texture
{
	int num;
	char **path;
};

struct scene
{
	struct polygon polygon;
	struct texture texture;
};

static struct scene scene;

void print_scene()
{
	printf("N:%d\n", scene.polygon.num);
	for(int i=0; i<scene.polygon.num;i++)
		printf("%02d-x: %04.3f, y: %04.3f, z: %04.3f\n", i, scene.polygon.x[i], scene.polygon.y[i], scene.polygon.z[i]);
}

int load_scene(const char *path)
{
	int i;
	struct polygon *p;
	struct texture *t;
	FILE *loader = fopen(path, "r");
	char linebuffer[80];
	
	p = &(scene.polygon);
	t = &(scene.texture);
	if(loader == NULL) return 0;
	
	fscanf(loader, "%s\n", linebuffer);
	fscanf(loader, "%s\n", linebuffer);
	fscanf(loader, "N:%d\n", &(t->num));
	t->path = (char**)malloc(sizeof(char*)*(t->num));
	for(i=0; i<(t->num); i++)
	{
		fscanf(loader, "%s\n", linebuffer);
		t->path[i] = (char*) malloc(sizeof(char)*(strlen(linebuffer)+1));
		strcpy(t->path[i], linebuffer);
	}
	
	load_textures(t->num, t->path);
	
	fscanf(loader, "%s\n", linebuffer);
	fscanf(loader, "N:%d\n\n", &(p->num));
	if(p->num < 0) return 0;
	
	p->x = (float*) malloc(sizeof(float)*(p->num));
	p->y = (float*) malloc(sizeof(float)*(p->num));
	p->z = (float*) malloc(sizeof(float)*(p->num));
	
	for(i=0; i<(p->num);i++)
		fscanf(loader, "%f %f %f\n", &(p->x[i]), &(p->y[i]), &(p->z[i]));
	fclose(loader);
	
	print_scene();
	
	return 1;
}

int pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
	int i, j, c = 0;
	for (i = 0, j = nvert-1; i < nvert; j = i++)
	{
		if( ((verty[i]>testy) != (verty[j]>testy)) &&
		  (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
				c = !c;
	}
	return c;
}

int get_scene_bits()
{
	extern struct scene scene;
	return scene.polygon.num;
}

float* get_scene_bit(int index)
{
	extern struct scene scene;
	float *vec = (float*) malloc(sizeof(float)*3);
	
	vec[0] = scene.polygon.x[index];
	vec[1] = scene.polygon.y[index];
	vec[2] = scene.polygon.z[index];
	
	return vec;
}

int collision_check(float pos_x, float pos_z, float vec_x, float vec_z)
{
	extern struct scene scene;
	struct polygon *polygon = &(scene.polygon);
	int current = pnpoly(polygon->num, polygon->x, polygon->z, pos_x, pos_z);
	int move = pnpoly(polygon->num, polygon->x, polygon->z, pos_x+vec_x, pos_z+vec_z);
	
	return (current == move);
}
