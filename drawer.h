#ifndef __DRAWER_H__
#define __DRAWER_H__

#include "utils.h"
#include "solid.h"

class Drawer : public Solid {
private:
	void drawDrawers(float, float, float, float, float, float);
public:
	Drawer();
	Drawer(float,float,float);
	Drawer(float,float,float,float,float,float);
	~Drawer();
	SolidType getType();
	void draw();
};

#endif