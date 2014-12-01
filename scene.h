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
	Coord3<float> cameraPosition;

	void applyPerspective();
	int checkQuadrant(float,float,float);
	void drawBase();
	void addSolidToQuadrantList(Solid*);
	void clearQuadrants();
	void buildQuadrantList();

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
	void setCameraPosition(float,float,float);
	void getCameraPosition(float*,float*,float*);
	void remove(Solid*);
};

#endif