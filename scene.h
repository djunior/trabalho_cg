#ifndef __SCENE_H__

#define __SCENE_H__

#include "utils.h"

#include <vector>
#include "solid.h"
#include "camera.h"
#include "textureHandler.h"

class Scene{
private:
	
	SceneMode mode;
	std::vector<Solid *> solidList, quadrantList[9];
	float screenX, screenY, width,height,length, scale;
	int viewportWidth, viewportHeight;
	Camera camera;

	void applyPerspective();
	int checkQuadrant(float,float,float);
	void drawBase();

	bool axis;

public:
	Scene();
	Scene(float,float,float);
	~Scene();

	void addSolid(Solid*);
	void setMode(SceneMode);
	SceneMode getMode();
	void draw();
	void init();
	void setScreenPosition(int,int);	
	void setBounds(float,float,float);
	void getBounds(float*,float*,float*);
	bool checkCollision(float,float,float);
	Camera* getCamera();
	void clear();
	void setScale(float);
	void setViewport(int,int);
	void setScreenPosition(float,float);
	void showAxis(bool b);
	void convertScreenToWorldCoord(int,int,float*,float*,float*);
	bool isSolidInsideScene(Solid*);
	bool isInsideScene(float,float,float,float,float,float);
};

#endif