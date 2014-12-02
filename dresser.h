#ifndef __DRESSER_H__
#define __DRESSER_H__

#include "utils.h"
#include "solid.h"

class Dresser : public Solid{
private:
	void drawDoor(int,float,float,float,float,float,float);
public:
	Dresser();
	~Dresser();

	Dresser(float,float,float);
	Dresser(float,float,float,float,float,float);

	SolidType getType();
	void draw();
};

#endif