#include "solid.h"

Solid::Solid(){
	width = 1.0;
	height = 1.0;
	length = 1.0;
}

Solid::~Solid(){

}

Solid::Solid(float w, float h, float l){
	width = w;
	height = h;
	length = l;
}

Solid::Solid(float x,float y,float z,float w, float h, float l){
	width = w;
	height = h;
	length = l;
	setPosition(x,y,z);
}

void Solid::setPosition(float _x, float _y, float _z){
	x = _x;
	y = _y;
	z = _z;
}

void Solid::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslatef(x,y,z);

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
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(0,height,0);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(width,height,0);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(width,height,length);
	 	glNormal3f(0.0,1.0,0.0);
	 	glVertex3f(0,height,length);

	 	// Fundo
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(0,0,length);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(0,height,length);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(width,height,length);
	 	glNormal3f(0.0,0.0,-1.0);
	 	glVertex3f(width,0,length);
	 	
	 	// Lado Direito
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,0,0);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,0,length);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,height,length);
	 	glNormal3f(1.0,0.0,0.0);
	 	glVertex3f(width,height,0);
	 	
	 	// Lado Esquerdo
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,0,0);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,height,0);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,height,length);
	 	glNormal3f(-1.0,0.0,0.0);
	 	glVertex3f(0,0,length);

		// Frente
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
