#include <GL/glut.h>
#include "camera.h"
#include "scene.h"
#include <math.h>

/* Código que lida com as funções relacionadas ao movimento da câmera */

GLbyte key_state[256];
GLbyte button_state[3];

GLfloat dir_y, dir_z, mov_x = 0, mov_y = 0, mov_z = 0;

void change_key(unsigned char key, int state)
{
	key_state[key] = state;
}

void change_mouse(int button, int state)
{
	button_state[button] = state;
}

void load_camera_transformations()
{
	glRotatef(dir_z,0,0,1);
	glRotatef(dir_y,0,1,0);
	glTranslatef(-mov_x,-mov_y,-mov_z);
}

void move_hero(GLfloat signal, GLfloat rot)
{
	const GLfloat magnitude = 0.5;
	GLdouble rad = (dir_y+rot)*M_PI/180;
	float vec_x, vec_z;
	
	vec_x = cos(rad)*magnitude*signal;
	vec_z += sin(rad)*magnitude*signal;
	
	if(collision_check(mov_x,mov_z,vec_x,vec_z))
	{
		mov_x += vec_x;
		mov_z += vec_z;
	}
}

void mouse_handle()
{
	if(button_state[left] == TRUE) move_hero(1,90);
	if(button_state[right] == TRUE) move_hero(-1,90);
}

void keyboard_handle()
{
	const GLfloat sx = 2;
	if(key_state['W'] == TRUE || key_state['w'] == TRUE) move_hero(1, 0);
	if(key_state['S'] == TRUE || key_state['s'] == TRUE) move_hero( 1, 180);
	if(key_state['A'] == TRUE || key_state['a'] == TRUE) dir_y -= sx;
	if(key_state['D'] == TRUE || key_state['d'] == TRUE) dir_y += sx;
	if(key_state['Q'] == TRUE || key_state['q'] == TRUE) dir_z += sx;
	if(key_state['Z'] == TRUE || key_state['z'] == TRUE) dir_z -= sx;
	if(key_state[0x20] == TRUE) mov_y += 1;
}

void events_handle()
{
	mouse_handle();
	keyboard_handle();
}
