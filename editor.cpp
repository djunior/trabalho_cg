#include "editor.h"

Editor::Editor(){

}

Editor::~Editor(){
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++){
		delete *it;
	}
	solidList.clear();
}

void Editor::draw(){
	scene.draw();
}

void Editor::setMainScene(Scene* s){
	mainScene = s;
	mainScene->getBounds(&width,&height,&length);
	//std::cout << "Editor::setMainScene() width = " << width << ", height = " << height << ", length = " << length << std::endl;
}

void Editor::setMousePosition(int screenX, int screenY){

	if (scene.getMode() == SCENE_MODE_TOP) {

		if (!activeSolid)
			return;

		float x = screenX - width/2;
		float z = screenY - length/2;

		if (x < 0)
			x = 0;
		else if (x + activeSolid->width > width)
			x = width - activeSolid->width;

		if (z < 0)
			z = 0;
		else if(z + activeSolid->length > length)
			z = length - activeSolid->length;

		activeSolid->setPosition(x,activeSolid->y,z);

	} else if (scene.getMode() == SCENE_MODE_RIGHT) {

		if (!activeSolid)
			return;

		float z = length - activeSolid->length - (screenX - (width - length/2)) ;
		float y = height - activeSolid->height/2 - (screenY - height/2);

		if (y < 0)
			y = 0;
		else if (y + activeSolid->height > height)
			y = height - activeSolid->height;

		if (z < 0)
			z = 0;
		else if(z + activeSolid->length > length)
			z = length - activeSolid->length;

		activeSolid->setPosition(activeSolid->x,y,z);		

	}
}

void Editor::init(){
	scene.setBounds(width,height,length);
	scene.setMode(SCENE_MODE_TOP);
	scene.init();
}

void Editor::setSceneBounds(float w, float h, float l){
	width = w;
	height = h;
	length = l;
}

void Editor::createSolid(float w, float h, float l){
	scene.clear();
	activeSolid = new Solid(0,0,0,w,h,l);
	solidList.push_back(activeSolid);
	scene.addSolid(activeSolid);
}

void Editor::setSceneMode(SceneMode m){
	scene.setMode(m);
}

void Editor::finalize(){
	mainScene->addSolid(activeSolid);
}