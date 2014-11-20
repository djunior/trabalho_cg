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
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void setFocus(int,int);
	void setScreenBounds(float,float,float,float);
	void setMode(SceneMode);
	void setVisionAngle(float);
	float getVisionAngle();

private:
	SceneMode mode;
	float anglePercentage, visionAngle, eye[3],focus[3],normal[3], screenBounds[4];
};

#endif