#include "dresser.h"

Dresser::Dresser(float w, float h, float l) : Solid(w,h,l){

}

Dresser::Dresser(float x, float y, float z, float w, float h, float l) : Solid(x,y,z,w,h,l){

}

Dresser::~Dresser(){

}

SolidType Dresser::getType(){
	return SOLID_TYPE_DRESSER;
}

void Dresser::drawDoor(int index, float dx, float dy, float dz, float w, float h, float l){
	drawBase("wood.bmp",dx,dy,dz,w,h,l);

	float handleWidth = 2, handleHeight = 20, handleLength = 1;
	float handleX = dx + w;
	float handleY = dy + (h - handleHeight)/2;
	float handleZ = dz + (l-2)*index + 1;

	drawBase("metal.bmp",handleX,handleY,handleZ,handleWidth,1,handleLength);
	drawBase("metal.bmp",handleX+1,handleY+1,handleZ,1,handleHeight-2,handleLength);
	drawBase("metal.bmp",handleX,handleY+19,handleZ,handleWidth,1,handleLength);
}

void Dresser::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(x,y,z);
	rotate();

	drawBase("wood.bmp",0,0,0,width-4,height,length);

	if ( (length-10) <= 48){
		drawDoor(0,width-4,4,4,2,height-8,length-8);
	} else {
		float doorLength = (length-10)/2;
		drawDoor(1,width-4,4,4,2,height-8,doorLength);
		drawDoor(0,width-4,4,6+doorLength,2,height-8,doorLength);
	}

	 glPopMatrix();
}