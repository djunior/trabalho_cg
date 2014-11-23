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
	void setFocusPosition(int,int);
	void getEyePosition(float*,float*,float*);
	void getFocusPosition(float*,float*,float*);
	void getNormal(float *, float *, float *);
	void setScreenBounds(float,float,float,float);
	void setSceneBounds(float,float,float);
	void setMode(SceneMode);
	void setVisionAngle(float);
	float getVisionAngle();

private:
	SceneMode mode;
	float anglePercentage, visionAngle, eye[3],focus[3],normal[3], screenBounds[4];
	Bounds3<float> sceneBounds;

	void setFocusPosition();
};

#endif