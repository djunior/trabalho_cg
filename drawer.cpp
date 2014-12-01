#include "drawer.h"

Drawer::Drawer(float w, float h, float l) : Solid(w,h,l){

}

Drawer::Drawer(float x,float y,float z,float w, float h, float l) : Solid(x,y,z,w,h,l){

}

Drawer::~Drawer(){

}

SolidType Drawer::getType(){
	return SOLID_TYPE_DRAWER;
}

void Drawer::drawDrawers(float x, float y, float z, float w, float h, float l){
	drawBase("wood.bmp",x,y,z,w,h,l);

	float handleWidth = 2, handleHeight = 1, handleLength = 10;
	float handleX = x + w;
	float handleY = y + (h - handleHeight)/2;
	float handleZ = z + (l - handleLength)/2;

	drawBase("metal.bmp",handleX,handleY,handleZ,2,1,1);
	drawBase("metal.bmp",handleX+1,handleY,handleZ+1,1,1,handleLength-2);
	drawBase("metal.bmp",handleX,handleY,handleZ+9,2,1,1);
}

void Drawer::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(x,y,z);
	rotate();

	drawBase("wood.bmp",0,0,0,width-4,height,length);

	int numberOfDrawers = (height-3)/16;
	for (int i = 0; i < numberOfDrawers; i++)
		drawDrawers(width-4,height-2-(16)*(i+1),2,2,15,length-4);

	glPopMatrix();
}