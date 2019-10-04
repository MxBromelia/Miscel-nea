#ifndef SCENE_H
#define SCENE_H

int load_scene(const char*);

int collision_check(float,float,float,float);

int get_scene_bits();

float* get_scene_bit(int);

#endif
