#ifndef __TABLE_H__
#define __TABLE_H__

#include "utils.h"
#include "solid.h"
#include "textureHandler.h"

class Table : public Solid{
private:
	void drawLeg(float,float,float);
	void drawTop();
public:

	Table();
	Table(float,float,float);
	Table(float,float,float,float,float,float);
	~Table();

	SolidType getType();

	void draw();

};


#endif