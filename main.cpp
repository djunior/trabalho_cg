#include <iostream>
#include <GL/glut.h>
#include <vector>
#include <array>

#define _USE_MATH_DEFINES
#include <math.h>

#include "solid.h"
#include "scene.h"

int w = 720, h = 480;
int roomW = 284, roomL = 308, roomH = 250;

Scene scene;

void Reshape(int width,int height){
	glViewport(0,0,width,height);
	glMatrixMode(GL_MODELVIEW);
	//glutPostRedisplay();
}

void SceneDraw(){
	scene.draw();
}

void KeyHandler(unsigned char key,int x, int y){

	Camera* c = scene.getCamera();

	if (key == 'w'){
		c->moveForward();
	} else if ( key == 's') {
		c->moveBackward();
	} else if ( key == 'a') {
		c->moveLeft();
	} else if ( key == 'd') {
		c->moveRight();
	}

	glutPostRedisplay();
}

void MotionHandler(int x, int y){

	Camera* c = scene.getCamera();

	c->setFocus(x,y);

	glutPostRedisplay();
}

void setupLight(){

	GLfloat light_ambient[] = {0.8,0.8,0.8,1.0};
	GLfloat light_diffuse[] = {1.5,1.5,1.5,1.0};
	GLfloat light_specular[] = {1.5,1.5,1.5,1.0};
	GLfloat light_model_ambient[] = {0.9,0.0,0.0,1.0};
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_model_ambient);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,0.0);
	glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,0.0);
	glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,0.1);

	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

}

int main(int argc, char** argv){
	std::cout << "Iniciando Hello World..." << std::endl;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(roomW*2,roomL*2);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Hello World!");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	//glBlendFunc(GL_CONSTANT_COLOR,GL_ZERO);
	//glEnable(GL_RASTERIZER_DISCARD);
	//glEnable(GL_CULL_FACE);

	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-roomW,roomW,-roomH,roomH,-roomL,roomL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//setupLight();

	scene.setBounds(roomW,roomH,roomL);
	scene.init();

	//Armario
	Solid armario(
		0.0,0.0,0.0,
		(float) 57.5, roomH,60
	);
	scene.addSolid(&armario);
	
	//Divisoria
	Solid divisoria(
		0.0,0.0,(float) 60,
		(float) 168.8, (float) 120, (float) 10
	);
	scene.addSolid(&divisoria);

	Solid divisoria_virada(
		148.1,0.0,70,
		20.0,120.0,40.0
	);
	scene.addSolid(&divisoria_virada);

	//Cama
	Solid cama(
		0.0,0.0, (float) 70,
		(float) 148,(float) 75,(float) 188
	);
	scene.addSolid(&cama);

	//Prateleira
	Solid prateleira(
		0.0,roomH-84,(float) 60,
		(float) 30, (float) 84, (float) 200 
	);
	scene.addSolid(&prateleira);

	//Mesa
	Solid mesa(
		(float) roomW - 50, 0.0, (float) roomL - 140,
		50, (float) 50, 140
	); 
	scene.addSolid(&mesa);

	glutDisplayFunc(SceneDraw);
	//glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyHandler);
	glutPassiveMotionFunc(MotionHandler);
	glutMainLoop();

	return 0;
}