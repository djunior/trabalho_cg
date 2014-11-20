#ifndef __SCENE_H__

#define __SCENE_H__

#include "utils.h"

#include <vector>
#include "solid.h"
#include "camera.h"

class Scene{
public:
	Scene();
	Scene(float,float,float);
	~Scene();

	void addSolid(Solid*);
	void setMode(SceneMode);
	SceneMode getMode();
	void draw();
	void init();
	void setScreenPosition();	
	void setBounds(float,float,float);
	Camera* getCamera();
private:
	void applyPerspective();
	SceneMode mode;
	std::vector<Solid *> solidList;
	float screenX, screenY, width,height,length;
	Camera camera;
};

#endif