#include <GL/glut.h>
#include "texture.h"
#include "scene.h"
#include <math.h>

float distance(float* v1, float* v2)
{
	float dx = pow(v1[0] - v2[0], 2);
	float dy = pow(v1[1] - v2[1], 2);
	float dz = pow(v1[2] - v2[2], 2);
	
	return sqrt(dx+dy+dz);
}

void draw_floor()
{
	const float k = 2.0;
	float w;
	
	glColor3f(1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, get_texture_id(1));
	glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0); glVertex3d(-100.0, 0.0, -100.0);
		glTexCoord2d(100.0, 0.0); glVertex3d( 100.0, 0.0, -100.0);
		glTexCoord2d(100.0, 100.0); glVertex3d( 100.0, 0.0,  100.0);
		glTexCoord2d(0.0, 100.0); glVertex3d(-100.0, 0.0,  100.0);
	glEnd();
}

void draw_scene_walls(float wall_height)
{
	const float k = 2.0;
	float w;
	int num = get_scene_bits();
	int i, j;
	float *vertex, *vertex0;
	
	glColor3f(1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, get_texture_id(0));
	glBegin(GL_QUAD_STRIP);
		for (i=0, j=0, w=0; i<num; j=i++)
		{
			vertex = get_scene_bit(i);
			vertex0 = get_scene_bit(j);
			w+= distance(vertex,vertex0);
			
			glTexCoord2d(w/k, 0.0); glVertex3fv(vertex);
			vertex[1] += wall_height;
			glTexCoord2d(w/k, wall_height/k); glVertex3fv(vertex);

		}
		vertex = get_scene_bit(0);
		vertex0 = get_scene_bit(num-1);
		
		w+= distance(vertex,vertex0);
		glTexCoord2d(w/k, 0.0); glVertex3fv(vertex);
		vertex[1] += wall_height;
		glTexCoord2d(w/k, wall_height/k); glVertex3fv(vertex);
	glEnd();
}

void draw_texture_test1()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, get_texture_id(0));
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f,0.0f); glVertex3d(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f,0.0f); glVertex3d(8.0f,0.0f,0.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3d(8.0f,8.0f,0.0f);
		glTexCoord2f(0.0f,1.0f); glVertex3d(0.0f,8.0f,0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void draw_grid(double from, double to, double each)
{
	#ifdef NO_TEST
	return;
	#endif
	
	GLfloat current;
	
	glColor3f(0.5f,0.5f,0.5f);
	glBegin(GL_LINES);
	for(current = from; current < to; current += each)
	{
		if(current > -1e-10 && current < 1e-10) current += each;
		glVertex3d(current, 0,from);
		glVertex3d(current, 0,  to);
		
		glVertex3d(from, 0,current);
		glVertex3d(to  , 0,current);
	}
	
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3d(0,0.01,0);
		glVertex3d(to,0.01,0);
		
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3d(0,0,0);
		glVertex3d(0,to,0);
		
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3d(0,0.01,0);
		glVertex3d(0,0.01,to);
	glEnd();
}

void draw_cube_fancely()
{
	GLdouble cube_v[] =	{0.0,0.0,0.0,
						1.0,0.0,0.0,
						1.0,0.0,1.0,
						0.0,0.0,1.0,
						0.0,1.0,0.0,
						1.0,1.0,0.0,
						1.0,1.0,1.0,
						0.0,1.0,1.0};
	GLint order[] =	{0,1,2,3,	//bottom
					 7,6,5,4,	//up
					 3,2,6,7,	//front
					 4,5,1,0,	//back
					 1,5,6,2,	//right
					 0,4,7,3};	//left
	GLfloat color_v[] = {1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f,
						 1.0f, 0.0f, 0.0f};
							 
		
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glVertexPointer(3,GL_DOUBLE,0,cube_v);
	glColorPointer(3,GL_DOUBLE,0,cube_v);
	
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, order);
}

void draw_test()
{
	draw_cube_fancely();
	//draw_walls();
	draw_grid(-100,100,2);
	draw_floor();
}
