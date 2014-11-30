#ifndef __CHAIR_H__
#define __CHAIR_H__

#include "utils.h"
#include "solid.h"

class Chair : public Solid{
private:
	void drawLeg(float,float,float);
	void drawBase();
	void drawBase(float,float,float);
	void drawTop();
public:
	Chair(float,float,float);
	Chair(float,float,float,float,float,float);
	~Chair();

	SolidType getType();

	void draw();	
};

#endif