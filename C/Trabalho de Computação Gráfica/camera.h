#ifndef CAMERA_H
#define CAMERA_H

#define FALSE 0
#define  TRUE 1

enum mouse{left, middle, right};

void change_key(unsigned char, int);
void change_mouse(int, int);

void load_camera_transformations();

void events_handle();

#endif
