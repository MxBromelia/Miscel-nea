#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

static int *texture;

void set_default_parameters()
{
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
}

int get_texture_id(int index)
{
	return texture[index];
}

int load_texture(int index, const char *path)
{
	texture[index] = SOIL_load_OGL_texture
	(
		path,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	
	if(texture[index] == 0) return 0;
	
	set_default_parameters();
	
	return 1;
}

int load_textures(int num, char **path)
{
	extern int *texture;
	int index = 0;
	int result;
	
	texture = (int*) malloc(sizeof(int)*num);
	for(index=0; index<num; index++)
	{
		result = load_texture(index, path[index]);
		
		printf("%d(%s):%s\n", index, path[index], (result ? "Hit!" : "Miss"));
	}
}

void draw_texture_test()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f,0.0f); glVertex3d(0.0f,0.0f,0.0f);
		glTexCoord2f(1.0f,0.0f); glVertex3d(8.0f,0.0f,0.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3d(8.0f,8.0f,0.0f);
		glTexCoord2f(0.0f,1.0f); glVertex3d(0.0f,8.0f,0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
