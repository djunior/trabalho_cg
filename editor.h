#ifndef __EDITOR_H__

#define __EDITOR_H__

#include "utils.h"
#include "scene.h"
#include "solid.h"

class Editor{
private:
	Scene* mainScene;
	Scene scene;

	Solid *activeSolid;
	std::vector<Solid*> solidList;

	float width,height,length;

public:

	Editor();
	~Editor();

	void setSceneBounds(float, float, float);
	void setMainScene(Scene*);
	void createSolid(float,float,float);
	void setMousePosition(int,int);
	void init();
	void draw();
	void setSceneMode(SceneMode);
	void finalize();
};

#endif