#include "bed.h"

Bed::Bed(float w, float h, float l) : Solid(w,h,l){

}

Bed::Bed(float x,float y,float z,float w, float h, float l) : Solid(x,y,z,w,h,l){

}

Bed::~Bed(){

}

SolidType Bed::getType(){
	return SOLID_TYPE_BED;
}

void Bed::drawBase(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	float tx1 = 10/(width+20);
	float tx2 = (width+10)/(width+20);

	float tz1 = 10/(length+20);
	float tz2 = (length+10)/(length+20);

	float h = height*0.6;

	GLuint tId = getTextureHandler()->getTextureId("wood.bmp");
	glBindTexture(GL_TEXTURE_2D,tId);

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

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,h,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,h,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,length);

		glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,length);

	 	// Fundo
	 	glNormal3f(0.0,0.0,-1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,length);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,length);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,length);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,0,length);
	 	
	 	// Lado Direito
	 	glNormal3f(1.0,0.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(width,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,0,length);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,length);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(width,h,0);
	 	
	 	// Lado Esquerdo
	 	glNormal3f(-1.0,0.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(0,h,length);
	 	
	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(0,0,length);

		// Frente
	 	glNormal3f(0.0,0.0,1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,0,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,0);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,0);

	glEnd();

	glPopMatrix();

}

void Bed::drawTop(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	float h = height*0.4;

	glScalef((width-10)/width,1,(length-10)/length);
	glTranslatef(5.0,height - h,5.0);

	GLuint tId = getTextureHandler()->getTextureId("fabric.bmp");
	glBindTexture(GL_TEXTURE_2D,tId);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		//baixo
	 	glNormal3f(0.0,-1.0,0.0);

	 	glVertex3f(0.0,0,0.0);
	 	glVertex3f(0.0,0,length);
	 	glVertex3f(width,0,length);
	 	glVertex3f(width,0,0);

	 	// Topo
	 	glNormal3f(0.0,1.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,h,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,h,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,length);

		glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,length);

	 	// Fundo
	 	glNormal3f(0.0,0.0,-1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,length);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,length);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,length);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,0,length);
	 	
	 	// Lado Direito
	 	glNormal3f(1.0,0.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(width,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,0,length);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,length);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(width,h,0);
	 	
	 	// Lado Esquerdo
	 	glNormal3f(-1.0,0.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(0,h,length);
	 	
	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(0,0,length);

		// Frente
	 	glNormal3f(0.0,0.0,1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(width,0,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(width,h,0);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,0);

	glEnd();

	glPopMatrix();
}

void Bed::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(x,y,z);

	drawBase();
	drawTop();
	
	glPopMatrix();
}
