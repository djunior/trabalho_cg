#ifndef __BED_H__
#define __BED_H__

#include "utils.h"
#include "solid.h"
#include "textureHandler.h"

class Bed : public Solid{
private:
	void drawBase();
	void drawTop();
public:

	Bed();
	Bed(float,float,float);
	Bed(float,float,float,float,float,float);
	~Bed();

	SolidType getType();
	void draw();	
};

#endif