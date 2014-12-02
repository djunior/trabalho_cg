#include "editor.h"

Editor::Editor(){
	activeSolid = 0;
	editing = false;
}

Editor::~Editor(){
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++){
		delete *it;
	}
	solidList.clear();
	activeSolid = 0;
}

void Editor::draw(){
	scene.draw();
}

void Editor::setMainScene(Scene* s){
	mainScene = s;
	mainScene->getBounds(&width,&height,&length);
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

void Editor::createSolid(SolidType t, float w, float h, float l){
	// scene.clear();
	if (t == SOLID_TYPE_GENERIC)
		activeSolid = new Solid(0,0,0,w,h,l);
	else if (t == SOLID_TYPE_TABLE)
		activeSolid = new Table(0,0,0,w,h,l);
	else if (t == SOLID_TYPE_BED)
		activeSolid = new Bed(0,0,0,w,h,l);
	else if (t == SOLID_TYPE_CHAIR)
		activeSolid = new Chair(0,0,0,w,h,l);
	else if (t == SOLID_TYPE_DRAWER)
		activeSolid = new Drawer(0,0,0,w,h,l);
	else if (t == SOLID_TYPE_DRESSER)
		activeSolid = new Dresser(0,0,0,w,h,l);

	solidList.push_back(activeSolid);
	scene.addSolid(activeSolid);
}

void Editor::createSolid(float w, float h, float l){
	createSolid(SOLID_TYPE_GENERIC,w,h,l);
}

void Editor::createSolid(SolidType t, float x, float y, float z, float w, float h, float l, float r){
	createSolid(t,w,h,l);
	activeSolid->setPosition(x,y,z);
	activeSolid->rotation = r;
	mainScene->addSolid(activeSolid);
}

void Editor::setSceneMode(SceneMode m){
	scene.setMode(m);
}

void Editor::finalize(){
	stopEditing();
	activeSolid = 0;
}

void Editor::removeSolid(){
	std::cout << "Editor::removeSolid() activeSolid = " << activeSolid << std::endl;
	if (activeSolid == 0)
		return;

	mainScene->remove(activeSolid);
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++){
		Solid* s = *it;
		if (s == activeSolid){
			solidList.erase(it);
			break;
		}
	}
	delete activeSolid;
	activeSolid = 0;
}

void Editor::clear(){
	mainScene->clear();
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++){
		delete *it;
	}
	solidList.clear();
}

void Editor::save(std::string filename){
	std::ofstream output(filename.c_str());
	float sceneWidth, sceneHeight, sceneLength;

	mainScene->getBounds(&sceneWidth,&sceneHeight,&sceneLength);

	output << sceneWidth << " " << sceneHeight << " " << sceneLength << std::endl;
	for (std::vector<Solid*>::iterator it = solidList.begin(); it != solidList.end(); it++){
		Solid* s = *it;
		int t = s->getType();
		int x = s->x, y = s->y, z = s->z;
		int w = s->width, h = s->height, l = s->length;
		int r = s->rotation;
		output << t << " " << x << " " << y << " " << z << " " << w << " " << h << " " << l << " " << r << std::endl;
	}

	output.close();
}

void Editor::load(std::string filename){
	std::ifstream input( filename.c_str() );
	
	//primeira linha
	int sceneWidth, sceneHeight, sceneLength;
	std::string firstLine; 
	std::getline( input, firstLine );

	std::istringstream firstStringStream(firstLine);

	firstStringStream >> sceneWidth >> sceneHeight >> sceneLength;
	mainScene->setBounds(sceneWidth,sceneHeight,sceneLength);

	for( std::string line; std::getline( input, line );)
	{
		std::istringstream iss(line);
		int t,x,y,z,w,h,l,r;
		iss >> t >> x >> y >> z >> w >> h >> l >> r;
		createSolid((SolidType) t,x,y,z,w,h,l,r);
		finalize();
	}

	input.close();
}

Solid* Editor::getActiveSolid(){
	return activeSolid;
}

bool Editor::isEditing(){
	return (activeSolid != 0 && editing);
}

void Editor::startEditing(){
	editing = true;
}

void Editor::stopEditing(){
	editing = false;
}

void Editor::setSolidPosition(float x, float y, float z){
	std::cout << "Editor::setSolidPosition(float x, float y, float z)" << std::endl;
	if (! isEditing())
		return;
	std::cout << "Editor::setSolidPosition(float x, float y, float z) checking bounds" << std::endl;
    if (mainScene->isInsideScene(x,y,z,activeSolid->width,activeSolid->height,activeSolid->length)){
    	std::cout << "Editor::setSolidPosition(float x, float y, float z) positioning solid" << std::endl;
        activeSolid->setPosition(x,y,z);
    }
}

