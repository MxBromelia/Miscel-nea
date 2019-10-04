#include <GL/glut.h>
#include "camera.h"
#include "light.h"
#include "draw_test.h"
#include "scene.h"

#define WIDTH 640
#define HEIGHT 480

/* Código Principal */

void init()
{
	load_scene("dungeon");
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//init_light();
	
	gluPerspective(25.f,(float)WIDTH/(float)HEIGHT,0.1,250);
	gluLookAt( 0, 2, 0,
			   1, 2, 0,
			   0, 1, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	
	load_camera_transformations();
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	draw_scene_walls(5);
	draw_test();
	
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
	glutSwapBuffers();
}

void key_up(unsigned char key, int x, int y)
{
	change_key(key, FALSE);
}

void key_down(unsigned char key, int x, int y)
{
	change_key(key, TRUE);
}

void mouse(int button, int state,int x, int y)
{
	enum mouse button_enum;
	int button_state;
	
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			button_enum = left;
			break;
		case GLUT_MIDDLE_BUTTON:
			button_enum = middle;
			break;
		case GLUT_RIGHT_BUTTON:
			button_enum = right;
			break;
	}
	
	switch(state)
	{
		case GLUT_UP:
			button_state = FALSE;
			break;
		case GLUT_DOWN:
			button_state = TRUE;
			break;
	}
	
	change_mouse(button_enum, button_state);
}

void timeline(int bogus)
{
	events_handle();
	
	glutTimerFunc(16,timeline,0);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("New move");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(key_down);
	glutKeyboardUpFunc(key_up);
	glutMouseFunc(mouse);
	glutTimerFunc(16, timeline, 0);
	
	init();
	
	
	glutMainLoop();
	return 0;
}
