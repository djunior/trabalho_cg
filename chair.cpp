#include "chair.h"

Chair::Chair(float w, float h, float l) : Solid(w,h,l){

}

Chair::Chair(float x,float y,float z,float w, float h, float l) : Solid(x,y,z,w,h,l){

}

Chair::~Chair() {

}

SolidType Chair::getType(){
	return SOLID_TYPE_CHAIR;
}

void Chair::drawTop(){
	drawBase(10/width,height*0.05,1.0);
}

void Chair::drawBase(){
	drawBase(1.0,1.0,1.0);
}

void Chair::drawBase(float xScale, float yScale, float zScale){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(0,height*0.5-10,0);
	glScalef(xScale,yScale,zScale);

	float tx1 = 10/(width+20);
	float tx2 = (width+10)/(width+20);

	float tz1 = 10/(length+20);
	float tz2 = (length+10)/(length+20);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		//baixo
	 	glNormal3f(0.0,-1.0,0.0);

	 	glVertex3f(0,0,0);
	 	glVertex3f(0,0,length);
	 	glVertex3f(width,0,length);
	 	glVertex3f(width,0,0);

	 	// Topo
	 	glNormal3f(0.0,1.0,0.0);

		glTexCoord2f(tx1,tz1);
	 	glVertex3f(0,10,0);

	 	glTexCoord2f(tx1,tz2);
	 	glVertex3f(width,10,0);

	 	glTexCoord2f(tx2,tz2);
	 	glVertex3f(width,10,length);

	 	glTexCoord2f(tx2,tz1);
	 	glVertex3f(0,10,length);

	 	// Fundo
	 	glNormal3f(0.0,0.0,-1.0);

	 	glTexCoord2f(1.0,tz1);
	 	glVertex3f(0,0,length);

	 	glTexCoord2f(tx2,tz1);
	 	glVertex3f(0,10,length);

		glTexCoord2f(tx2,tz2);
	 	glVertex3f(width,10,length);

	 	glTexCoord2f(1.0,tz2);
	 	glVertex3f(width,0,length);
	 	
	 	// Lado Direito
	 	glNormal3f(1.0,0.0,0.0);

	 	glTexCoord2f(tx1,1.0);
	 	glVertex3f(width,0,0);

	 	glTexCoord2f(tx2,1.0);
	 	glVertex3f(width,0,length);

	 	glTexCoord2f(tx2,tz2);
	 	glVertex3f(width,10,length);

	 	glTexCoord2f(tx1,tz2);
	 	glVertex3f(width,10,0);
	 	
	 	// Lado Esquerdo
	 	glNormal3f(-1.0,0.0,0.0);

	 	glTexCoord2f(tx1,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(tx1,tz1);
	 	glVertex3f(0,10,0);

	 	glTexCoord2f(tx2,tz1);
	 	glVertex3f(0,10,length);

	 	glTexCoord2f(tx2,0.0);
	 	glVertex3f(0,0,length);

		// Frente
	 	glNormal3f(0.0,0.0,1.0);

	 	glTexCoord2f(0.0,tz1);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(0.0,tz2);
	 	glVertex3f(width,0,0);

	 	glTexCoord2f(tx1,tz2);
	 	glVertex3f(width,10,0);

	 	glTexCoord2f(tx1,tz1);
	 	glVertex3f(0,10,0);

	glEnd();

	glPopMatrix();
}


void Chair::drawLeg(float legX, float legY, float legZ){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(legX,legY,legZ);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		//baixo
	 	glNormal3f(0.0,-1.0,0.0);
	 	glVertex3f(0,0,0);
	 	glVertex3f(0,0,10);
	 	glVertex3f(10,0,10);
	 	glVertex3f(10,0,0);

	 	// Fundo
	 	glNormal3f(0.0,0.0,-1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,10);

	 	glTexCoord2f(0.25,0.0);
	 	glVertex3f(0,height*0.5 - 10,10);

	 	glTexCoord2f(0.25,1.0);
	 	glVertex3f(10,height*0.5 - 10,10);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(10,0,10);
	 	
	 	// Lado Direito
	 	glNormal3f(1.0,0.0,0.0);

	 	glTexCoord2f(0.25,0.0);
	 	glVertex3f(10,0,0);

	 	glTexCoord2f(0.25,1.0);
	 	glVertex3f(10,0,10);

	 	glTexCoord2f(0.5,1.0);
	 	glVertex3f(10,height*0.5 - 10,10);

	 	glTexCoord2f(0.5,0.0);
	 	glVertex3f(10,height*0.5 - 10,0);
	 	
	 	// Lado Esquerdo
	 	glNormal3f(-1.0,0.0,0.0);

	 	glTexCoord2f(0.75,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(0,height*0.5 - 10,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(0,height*0.5 - 10,10);

	 	glTexCoord2f(0.75,1.0);
	 	glVertex3f(0,0,10);

		// Frente
	 	glNormal3f(0.0,0.0,1.0);

	 	glTexCoord2f(0.5,0.0);
	 	glVertex3f(0,0,0);

		glTexCoord2f(0.5,1.0);
	 	glVertex3f(10,0,0);

	 	glTexCoord2f(0.75,1.0);
	 	glVertex3f(10,height*0.5 - 10,0);

	 	glTexCoord2f(0.75,0.0);
	 	glVertex3f(0,height*0.5 - 10,0);

	glEnd();

	glPopMatrix();
}

void Chair::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(x,y,z);
	rotate();

	GLuint tId = getTextureHandler()->getTextureId("wood.bmp");
	glBindTexture(GL_TEXTURE_2D,tId);

	drawTop();
	drawBase();
	drawLeg(0,0,0);
	drawLeg(width-10,0,0);
	drawLeg(width-10,0,length-10);
	drawLeg(0,0,length-10);

	glPopMatrix();
}