#include "scene.h"

Scene::Scene(){
	screenX = 0;
	screenY = 0;
	width = 1;
	viewportWidth = 1;
	viewportHeight = 1;
	height = 1;
	length = 1;
	scale = 1;
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

	//distancia maxima = diagonal horizontal da cena
	GLdouble far = near + sqrt( pow(width,2) + pow(length,2) );

	gluPerspective((GLdouble) camera.getVisionAngle(),(GLdouble) width/height,near,far);
}

void Scene::init(){
	camera.setMode(mode);
	camera.setScreenBounds(screenX, screenY, width*2, height*2);
	camera.setPosition(-width/2,180/height,length/2);
	camera.setSceneBounds(width,height,length);
}

void Scene::drawBase(){
	glColorMaterial(GL_FRONT,GL_AMBIENT);

	GLuint tId = getTextureId();
	glBindTexture(GL_TEXTURE_2D,tId);

	glBegin(GL_QUADS);
		//Chao
		glColor3f(0.2,0.2,0.2);
		glVertex3f(0.0,0.0,0.0);
		glTexCoord2f(0.0,0.0);

		glVertex3f(width,0.0,0.0);
		glTexCoord2f(1.0,0.0);

		glVertex3f(width,0.0,length);
		glTexCoord2f(1.0,1.0);
		glVertex3f(0.0,0.0,length);
		glTexCoord2f(0.0,1.0);

		glColor3f(1.0,1.0,1.0);

		glVertex3f(0.0,0.0,0.0);
		glVertex3f(width,0.0,0.0);
		glVertex3f(width,height,0.0);
		glVertex3f(0.0,height,0.0);

		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,length);
		glVertex3f(0.0,height,length);
		glVertex3f(0.0,height,0.0);			

		if (mode == SCENE_MODE_NAVIGATION){
			glVertex3f(width,0.0,0.0);
			glVertex3f(width,0.0,length);
			glVertex3f(width,height,length);
			glVertex3f(width,height,0.0);

			glVertex3f(0.0,0.0,length);
			glVertex3f(0.0,height,length);
			glVertex3f(width,height,length);
			glVertex3f(width,0.0,length);
		}

	glEnd();
}

void Scene::draw(){

	if (mode == SCENE_MODE_NAVIGATION)
		applyPerspective();
	else{
		glPushMatrix();

		float aspect = width / height;

		// if (aspect > 1){

		// }
		std::cout << "Scene::draw() aspect = " << aspect << std::endl;
		if (aspect > 1){
			float w = scale * viewportWidth/aspect;
			float h = scale * viewportHeight;
			glViewport(screenX + (viewportWidth - w)/2, screenY, scale * viewportWidth/aspect, scale * viewportHeight );
		}else{
			glViewport(screenX, screenY, scale * viewportWidth * aspect, scale * viewportHeight );
		}

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-width,width,-height,height,-height,height);

	}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex3f(-width,-height,0.0);
		glVertex3f(width,-height,0.0);

		glVertex3f(width,-height,0.0);
		glVertex3f(width,height,0.0);

		glVertex3f(width,height,0.0);
		glVertex3f(-width,height,0.0);

		glVertex3f(-width,height,0.0);
		glVertex3f(-width,-height,0.0);
	glEnd();


	camera.setupCamera();

	// if (mode != SCENE_MODE_NAVIGATION)
	// 	glScalef(scale,scale,scale);

	glTranslatef(-width/2,-height/2,-length/2);

	drawBase();

	for (std::vector<Solid*>::iterator it = solidList.begin();it != solidList.end(); it++){
		(*it)->draw();
	}

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glPopMatrix();
	
}

void Scene::setScale(float s){
	scale = s;
}

void Scene::setViewport(int w, int h){
	viewportWidth = w;
	viewportHeight = h;
}

void Scene::setScreenPosition(int x, int y){
	screenX = (float) x;
	screenY = (float) y;

	camera.setScreenBounds(x,y, scale * viewportWidth, scale*viewportHeight );
}

void Scene::setScreenPosition(float x, float y){
	//Testando valores invalidos
	if (x > 1 || y > 1)
		return;

	setScreenPosition((int) (getScreenWidth()*x), (int) (getScreenHeight()*y));
}


Camera* Scene::getCamera(){
	return &camera;
}