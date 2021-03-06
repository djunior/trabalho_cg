#ifndef __SOLID_H__

#define __SOLID_H__

#include <iostream>

#include "utils.h"

class Solid{
protected:
	void rotate();
	void drawBase(std::string,float,float,float,float,float,float);
	void drawBase(float,float,float);
public:
	float x,y,z,width,height,length,rotation;

	Solid();
	Solid(float,float,float);
	Solid(float,float,float,float,float,float);

	virtual ~Solid();

	void setPosition(float,float,float);
	void getRotatedBounds(float*,float*,float*);
	//void getPosition(&float,&float,&float);

	void setColor(float,float,float);
	// void draw();
	virtual void draw();
	virtual SolidType getType();

	bool hit(float, float, float);
};

#endif