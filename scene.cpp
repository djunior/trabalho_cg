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
	axis = false;
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

	// std::cout << "Scene::checkQuadrant() x,y,z = (" << x << "," << y << "," << z << ") index = " << index << std::endl;

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

void Scene::clearQuadrants(){
	for (int i = 0; i < 9; i++)
		quadrantList[i].clear();
}

void Scene::addSolidToQuadrantList(Solid* s){

	float w,h,l;
	s->getRotatedBounds(&w,&h,&l);

	int index = checkQuadrant(s->x, s->y, s->z);
	int secondIndex = checkQuadrant(s->x + w, s->y, s->z);
	int thirdIndex = checkQuadrant(s->x, s->y, s->z+l);

	for (int i = index; i <= secondIndex; i++){
		for (int j = index; j <= thirdIndex; j += 3){
			// std::cout << "Adicionando solido ao quadrante " << i+j-index << std::endl;
			quadrantList[i+j-index].push_back(s);
		}
	}
}

void Scene::buildQuadrantList(){
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++)
		addSolidToQuadrantList(*it);
}

void Scene::setMode(SceneMode m){
	mode = m;
	camera.setMode(mode);
	if (mode == SCENE_MODE_NAVIGATION){
		camera.setPosition(cameraPosition.x,cameraPosition.y,cameraPosition.z);
		clearQuadrants();
		buildQuadrantList();
	}
}

SceneMode Scene::getMode(){
	return mode;
}

void Scene::addSolid(Solid * s){
	solidList.push_back(s);
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
	GLdouble far = (near + sqrt( pow(width,2) + pow(length,2) ) ) / sin(camera.getVerticalAngle());

	gluPerspective((GLdouble) camera.getVisionAngle(),(GLdouble) width/height,near,far);
}

void Scene::init(){
	camera.setMode(mode);
	camera.setScreenBounds(screenX, screenY, width*2, height*2);
	camera.setSceneBounds(width,height,length);
	camera.setPosition(0.0,180,length);
}

void Scene::drawBase(){
	glColorMaterial(GL_FRONT,GL_AMBIENT);

	GLuint tId = getTextureHandler()->getTextureId("carpet.bmp");
	glBindTexture(GL_TEXTURE_2D,tId);

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		//Chao
		glColor3f(1.0,1.0,1.0);

		glTexCoord2f(0.0,0.0);
		glVertex3f(0.0,0.0,0.0);

		glTexCoord2f(1.0,0.0);
		glVertex3f(width,0.0,0.0);

		glTexCoord2f(1.0,1.0);
		glVertex3f(width,0.0,length);
		
		glTexCoord2f(0.0,1.0);
		glVertex3f(0.0,0.0,length);

		glColor3f(1.0,1.0,1.0);

		// glVertex3f(0.0,0.0,0.0);
		// glVertex3f(width,0.0,0.0);
		// glVertex3f(width,height,0.0);
		// glVertex3f(0.0,height,0.0);

		// glVertex3f(0.0,0.0,0.0);
		// glVertex3f(0.0,0.0,length);
		// glVertex3f(0.0,height,length);
		// glVertex3f(0.0,height,0.0);			

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

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-width,width,-height,height,-length,length);
	}

	// glColor3f(1.0,0.0,0.0);
	// glBegin(GL_LINES);
	// 	glVertex3f(-width,-height,0.0);
	// 	glVertex3f(width,-height,0.0);

	// 	glVertex3f(width,-height,0.0);
	// 	glVertex3f(width,height,0.0);

	// 	glVertex3f(width,height,0.0);
	// 	glVertex3f(-width,height,0.0);

	// 	glVertex3f(-width,height,0.0);
	// 	glVertex3f(-width,-height,0.0);
	// glEnd();

	camera.setupCamera();

	// if (mode != SCENE_MODE_NAVIGATION)
	// 	glScalef(scale,scale,scale);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-width/2,-height/2,-length/2);
	if (axis) {
		glLineWidth(2.5);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(width+40, 0, 0);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0, height + 20, 0);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0, 0, length + 40);
		glEnd();

		glBegin(GL_TRIANGLES);
			glVertex3f(width+40,0.0,-5.0);
			glVertex3f(width+40,0.0,5.0);
			glVertex3f(width+47,0.0,0.0);

			glVertex3f(-3.0,height+20,4.0);
			glVertex3f(3.0,height+20,-4.0);
			glVertex3f(0.0,height+27,0.0);

			glVertex3f(-5,0.0,length+40);
			glVertex3f(5,0.0,length+40);
			glVertex3f(0.0,0.0,length+47);
		glEnd();
	}

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

	camera.setScreenBounds(screenX, screenY, scale * viewportWidth, scale*viewportHeight );
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

	setScreenPosition((int) (viewportWidth*x), (int) (viewportHeight*y));
}

void Scene::showAxis(bool b){
	axis = b;
}

void Scene::remove(Solid *solid){
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++){
		Solid* s = *it;
		if (s == solid){
			solidList.erase(it);
			return;
		}
	}
}

void Scene::convertScreenToWorldCoord(int x,int y, float*wx, float *wy, float* wz){
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-width,width,-height,height,-length,length);

	camera.setupCamera();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-width/2,-height/2,-length/2);

	int viewport[4];
	GLdouble modelview[16],projection[16];
	Coord3<GLdouble> wc1,wc2;

	glGetIntegerv(GL_VIEWPORT, viewport); 
	glGetDoublev (GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev (GL_PROJECTION_MATRIX, projection);


	gluUnProject(x,viewport[3] - y,  0.0, modelview,  projection,  viewport,  &wc1.x,  &wc1.y,  &wc1.z);
	gluUnProject(x,viewport[3] - y,  1.0, modelview,  projection,  viewport,  &wc2.x,  &wc2.y,  &wc2.z);

	double f = wc1.y / ( wc2.y - wc1.y );
	double x2d = wc1.x - f * (wc2.x - wc1.x );
	double z2d = wc1.z - f * (wc2.z - wc1.z );

	*wx = (float) x2d;
	*wy = (float) 0;
	*wz = (float) z2d;

	//Retornando as matrizes aos valores iniciais
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

}

bool Scene::isSolidInsideScene(Solid*s){
	return isInsideScene(s->x,s->y,s->z,s->width,s->height,s->length);
}

bool Scene::isInsideScene(float x,float y,float z,float w,float h,float l){
	if (x < 0 || x+w > width)
		return false;

	if (y < 0 || y+h > height)
		return false;

	if (z < 0 || z+l > length)
		return false;

	return true;
}

Camera* Scene::getCamera(){
	return &camera;
}

void Scene::setCameraPosition(float x, float y, float z){
	cameraPosition.x = x;
	cameraPosition.y = y;
	cameraPosition.z = z;
}

void Scene::getCameraPosition(float *x, float *y, float *z){
	*x = cameraPosition.x;
	*y = cameraPosition.y;
	*z = cameraPosition.z;
}