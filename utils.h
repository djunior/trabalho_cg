#ifndef __UTILS_H__

#define __UTILS_H__

#include <GL/glut.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "textureHandler.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

typedef enum SceneMode{
	SCENE_MODE_ISOMERIC,
	SCENE_MODE_TOP,
	SCENE_MODE_LEFT,
	SCENE_MODE_RIGHT,
	SCENE_MODE_NAVIGATION
} SceneMode;

enum SolidType{
	SOLID_TYPE_GENERIC,
	SOLID_TYPE_TABLE,
	SOLID_TYPE_BED,
	SOLID_TYPE_CHAIR,
	SOLID_TYPE_DRAWER
};

template <typename T>
struct Coord2{
	T x;
	T y;
};

template <typename T>
struct Coord3{
	T x;
	T y;
	T z;
};

template <typename T>
struct Bounds2{
	Coord2<T> position;
	T width;
	T height;
};

template <typename T>
struct Bounds3{
	Coord3<T> position;
	T width;
	T height;
	T length;
};

TextureHandler* getTextureHandler();

#endif