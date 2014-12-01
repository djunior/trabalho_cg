#include "solid.h"

Solid::Solid(){
	width = 1.0;
	height = 1.0;
	length = 1.0;
	rotation = 0;
}

Solid::~Solid(){

}

Solid::Solid(float w, float h, float l){
	width = w;
	height = h;
	length = l;
	rotation = 0;
}

Solid::Solid(float x,float y,float z,float w, float h, float l){
	width = w;
	height = h;
	length = l;
	setPosition(x,y,z);
	rotation = 0;
}

SolidType Solid::getType(){
	return SOLID_TYPE_GENERIC;
}

void Solid::getRotatedBounds(float *w, float *h, float *l){
	float radians = rotation / 180;
	*w = abs(width*cos(radians*M_PI) + length*sin(radians*M_PI));
	*h = height;
	*l = abs(length*cos(radians*M_PI) + width*sin(radians*M_PI));
}

bool Solid::hit(float testX, float testY, float testZ){
	bool hitX = false, hitY = false, hitZ = false;

	float posBoundsX, posBoundsY, posBoundsZ;
	getRotatedBounds(&posBoundsX,&posBoundsY,&posBoundsZ);

	if (testX >= x && testX <= x+posBoundsX)
		hitX = true;

	if (testY >= y && testY <= y+posBoundsY)
		hitY = true;

	if (testZ >= z && testZ <= z+posBoundsZ)
		hitZ = true;

	return hitX && hitY && hitZ;
}

void Solid::drawBase(std::string textureName, float x, float y, float z, float w, float h, float l){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLuint tId = getTextureHandler()->getTextureId(textureName);
	glBindTexture(GL_TEXTURE_2D,tId);

	glTranslatef(x,y,z);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		//baixo
	 	glNormal3f(0.0,-1.0,0.0);

	 	glVertex3f(0,0,0);
	 	glVertex3f(0,0,l);
	 	glVertex3f(w,0,l);
	 	glVertex3f(w,0,0);

	 	// Topo
	 	glNormal3f(0.0,1.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,h,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(w,h,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(w,h,l);

		glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,l);

	 	// Fundo
	 	glNormal3f(0.0,0.0,-1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,l);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,l);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(w,h,l);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(w,0,l);
	 	
	 	// Lado Direito
	 	glNormal3f(1.0,0.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(w,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(w,0,l);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(w,h,l);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(w,h,0);
	 	
	 	// Lado Esquerdo
	 	glNormal3f(-1.0,0.0,0.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(0,h,l);
	 	
	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(0,0,l);

		// Frente
	 	glNormal3f(0.0,0.0,1.0);

	 	glTexCoord2f(0.0,0.0);
	 	glVertex3f(0,0,0);

	 	glTexCoord2f(1.0,0.0);
	 	glVertex3f(w,0,0);

	 	glTexCoord2f(1.0,1.0);
	 	glVertex3f(w,h,0);

	 	glTexCoord2f(0.0,1.0);
	 	glVertex3f(0,h,0);

	glEnd();

	glPopMatrix();

}

void Solid::setPosition(float _x, float _y, float _z){
	x = _x;
	y = _y;
	z = _z;
}

void Solid::rotate(){
	if (rotation == 0 )
		return;

	float rw,rh,rl;
	getRotatedBounds(&rw,&rh,&rl);

	glTranslatef(rw/2,rh/2,rl/2);
	glRotatef(rotation,0,1,0);
	glTranslatef(-width/2,-height/2,-length/2);
}

void Solid::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(x,y,z);
	rotate();

	glColor3f(0.4,0.4,0.8);
	glBegin(GL_QUADS);
		//baixo
	 	glNormal3f(0.0,-1.0,0.0);
	 	glVertex3f(0,0,0);
	 	glNormal3f(0.0,-1.0,0.0);
	 	glVertex3f(0,0,length);
	 	glNormal3f(0.0,-1.0,0.0);
	 	glVertex3f(width,0,length);
	 	glNormal3f(0.0,-1.0,0.0);
	 	glVertex3f(width,0,0);

	 	// Topo
	 	glColor3f(0.4,0.4,0.8);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(0,height,0);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(width,height,0);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(width,height,length);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(0,height,length);

	 	// Fundo
	 	glColor3f(1.0,0.0,0.0);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(0,0,length);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(0,height,length);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(width,height,length);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(width,0,length);
	 	
	 	// Lado Direito
	 	glColor3f(0.0,1.0,0.0);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,0,0);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,0,length);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,height,length);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,height,0);
	 	
	 	// Lado Esquerdo
	 	glColor3f(0.0,0.0,1.0);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,0,0);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,height,0);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,height,length);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,0,length);

		// Frente
		glColor3f(1.0,1.0,1.0);
	 	glNormal3f(0.0,0.0,1.0);
	 	glVertex3f(0,0,0);
	 	glNormal3f(0.0,0.0,1.0);
	 	glVertex3f(width,0,0);
	 	glNormal3f(0.0,0.0,1.0);
	 	glVertex3f(width,height,0);
	 	glNormal3f(0.0,0.0,1.0);
	 	glVertex3f(0,height,0);

	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		// base
	 	glVertex3f(0,0,0);
	 	glVertex3f(0,0,length);

	 	glVertex3f(0,0,length);
	 	glVertex3f(width,0,length);

	 	glVertex3f(width,0,length);
	 	glVertex3f(width,0,0);

	 	glVertex3f(width,0,0);
		glVertex3f(0,0,0);
	 	
	 	// laterais
		glVertex3f(0,0,0);
		glVertex3f(0,height,0);

		glVertex3f(0,0,length);
		glVertex3f(0,height,length);

		glVertex3f(width,0,length);
		glVertex3f(width,height,length);

		glVertex3f(width,0,0);
		glVertex3f(width,height,0);

		// topo
	 	glVertex3f(0,height,0);
	 	glVertex3f(width,height,0);

	 	glVertex3f(width,height,0);
	 	glVertex3f(width,height,length);

	 	glVertex3f(width,height,length);
	 	glVertex3f(0,height,length);

	 	glVertex3f(0,height,length);
	 	glVertex3f(0,height,0);
	glEnd();

	glPopMatrix();
}
