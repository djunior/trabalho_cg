#ifndef __SOLID_H__

#define __SOLID_H__

#include <GL/glut.h>
#include <iostream>

class Solid{
private:

public:
	float x,y,z,width,height,length;

	Solid();
	Solid(float,float,float);
	Solid(float,float,float,float,float,float);

	~Solid();

	void setPosition(float,float,float);
	//void getPosition(&float,&float,&float);

	void setColor(float,float,float);
	void draw();

	bool hit(float, float, float);
};

#endif