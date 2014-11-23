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
	mode = SCENE_MODE_NAVIGATION;
}

Scene::~Scene(){
	solidList.clear();

	for (int i = 0; i<9; i++)
		quadrantList[i].clear();
}

int Scene::checkQuadrant(float x, float y, float z){
	int index = 0;

	if (x < width/3)
		index = 0;
	else if (x < 2*width/3)
		index = 1;
	else
		index = 2;

	if (z < length/3)
		index += 0;
	else if (z < 2*length/3)
		index += 3;
	else
		index += 6;

	std::cout << "Scene::checkQuadrant() x,y,z = (" << x << "," << y << "," << z << ") index = " << index << std::endl;

	return index;
}

void Scene::setBounds(float w, float h, float l){
	width = w;
	height = h;
	length = l;	
}

void Scene::getBounds(float*w,float*h,float*l){
	*w = width;
	*h = height;
	*l = length;
}

void Scene::setMode(SceneMode m){
	mode = m;
	camera.setMode(mode);
}

SceneMode Scene::getMode(){
	return mode;
}

void Scene::addSolid(Solid * s){
	solidList.push_back(s);

	int index = checkQuadrant(s->x, s->y, s->z);
	int secondIndex = checkQuadrant(s->x + s->width, s->y, s->z);
	int thirdIndex = checkQuadrant(s->x, s->y, s->z+s->length);

	for (int i = index; i <= secondIndex; i++){
		for (int j = index; j <= thirdIndex; j += 3){
			// std::cout << "Adicionando solido ao quadrante " << i+j-index << std::endl;
			quadrantList[i+j-index].push_back(s);
		}
	}

}

bool Scene::checkCollision(float x, float y, float z){
	int index = checkQuadrant(x,y,z);

	if (x <= 0 || x >= width )
		return true;

	if (y < 0 || y >= height)
		return true;

	if (z <= 0 || z >= length)
		return true;

	for (std::vector<Solid*>::iterator it = quadrantList[index].begin(); it != quadrantList[index].end(); it++){
		if ((*it)->hit(x,y,z))
			return true;
	}

	return false;
}

void Scene::clear(){
	solidList.clear();
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
	camera.setPosition(-width/2,180/height,length/2);
	camera.setSceneBounds(width,height,length);
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

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glutSwapBuffers();

}

Camera* Scene::getCamera(){
	return &camera;
}