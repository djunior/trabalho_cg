#ifndef __UTILS_H__

#define __UTILS_H__

#include <GL/glut.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


typedef enum SceneMode{
	SCENE_MODE_ISOMERIC,
	SCENE_MODE_TOP,
	SCENE_MODE_LEFT,
	SCENE_MODE_RIGHT,
	SCENE_MODE_NAVIGATION
} SceneMode;

#endif