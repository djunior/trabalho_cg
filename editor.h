#ifndef __EDITOR_H__

#define __EDITOR_H__

#include "utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "scene.h"
#include "solid.h"
#include "table.h"
#include "bed.h"
#include "chair.h"
#include "drawer.h"

class Editor{
private:
	Scene* mainScene;
	Scene scene;

	Solid *activeSolid;
	std::vector<Solid*> solidList;

	float width,height,length;

	bool editing;

public:

	Editor();
	~Editor();

	void setSceneBounds(float, float, float);
	void setMainScene(Scene*);
	void createSolid(float,float,float);
	void createSolid(SolidType,float,float,float);
	void createSolid(SolidType,float,float,float,float,float,float,float);
	void setMousePosition(int,int);
	void init();
	void draw();
	void setSceneMode(SceneMode);
	void finalize();
	void load(std::string);
	void save(std::string);
	void clear();
	void startEditing();
	void stopEditing();
	bool isEditing();
	void setSolidPosition(float,float,float);
	void removeSolid();

	Solid* getActiveSolid();
	//void setSolidPosition(float x, float y, float z);
};

#endif