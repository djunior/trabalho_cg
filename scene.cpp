#include "scene.h"

Scene::Scene(){
	screenX = 0;
	screenY = 0;
	width = 1;
	height = 1;
	length = 1;
	mode = SCENE_MODE_NAVIGATION;
}

Scene::Scene(float w, float h, float l){
	setBounds(w,h,l);
}

Scene::~Scene(){

}

void Scene::setBounds(float w, float h, float l){
	width = w;
	height = h;
	length = l;	
}

void Scene::setMode(SceneMode m){
	mode = m;
}

SceneMode Scene::getMode(){
	return mode;
}

void Scene::addSolid(Solid * s){
	solidList.push_back(s);
}

void Scene::applyPerspective(){
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	GLdouble near = 0.01;
	GLdouble far = length + near;

	gluPerspective((GLdouble) camera.getVisionAngle(),(GLdouble) width/height,near,far);
}

void Scene::init(){
	camera.setMode(mode);
	camera.setScreenBounds(0, 0, width*2, height*2);
	camera.setPosition(1.0,180/length,1.0);
}

void Scene::draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (mode == SCENE_MODE_NAVIGATION)
		applyPerspective();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	camera.setupCamera();

	glTranslatef(-width/2,-height/2,-length/2);

	glColor3f(0.2,0.2,0.2);
	glColorMaterial(GL_FRONT,GL_AMBIENT);
	glBegin(GL_QUADS);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(width,0.0,0.0);
		glVertex3f(width,0.0,length);
		glVertex3f(0.0,0.0,length);

		glColor3f(1.0,1.0,1.0);

		glVertex3f(0.0,0.0,0.0);
		glVertex3f(width,0.0,0.0);
		glVertex3f(width,height,0.0);
		glVertex3f(0.0,height,0.0);

		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,length);
		glVertex3f(0.0,height,length);
		glVertex3f(0.0,height,0.0);
	glEnd();

	for (std::vector<Solid*>::iterator it = solidList.begin();it != solidList.end(); it++){
		(*it)->draw();
	}

	glPopMatrix();
	glutSwapBuffers();

}

Camera* Scene::getCamera(){
	return &camera;
}