#ifndef __CAMERA_H__

#define __CAMERA_H__

#include "utils.h"

class Camera{
public:
	Camera();
	Camera(SceneMode);
	~Camera();

	void setPosition(float,float,float);
	void setupCamera();
	void moveForward( bool (*callback)(float,float,float) );
	void moveBackward(bool (*callback)(float,float,float));
	void moveLeft(bool (*callback)(float,float,float));
	void moveRight(bool (*callback)(float,float,float));
	void getEyePosition(float*,float*,float*);
	void getFocusPosition(float*,float*,float*);
	void getNormal(float *, float *, float *);
	void setScreenBounds(float,float,float,float);
	void setSceneBounds(float,float,float);
	void setMode(SceneMode);
	void setVisionAngle(float);
	float getVisionAngle();
	float getVerticalAngle();

	void notifyMousePressed(int, int);
	void notifyMouseDrag(int, int);
	void notifyMouseReleased(int, int);
	bool notifyMouseMotion(int,int);

private:
	SceneMode mode;
	float angleOffset, visionAngle;
	Bounds2<float> screenBounds;
	Bounds3<float> sceneBounds;
	Coord2<int> dragBegin;
	Coord2<float> anglePercentage;
	Coord3<float> eye, focus, normal;
	bool isDragging;

	void setFocusPosition();
};

#endif