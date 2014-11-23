#include "camera.h"

Camera::Camera(){
	visionAngle = 120;
	setMode(SCENE_MODE_NAVIGATION);
}

Camera::~Camera(){

}

Camera::Camera(SceneMode m){
	setMode(m);
}

void Camera::setMode(SceneMode m){
	mode = m;
	switch(mode) {
		case SCENE_MODE_NAVIGATION:
			eye[0] = 1.0;
			eye[1] = 1.0;
			eye[2] = 1.0;
			
			anglePercentage = 0.5;
			setFocusPosition();
			
			normal[0] = 0.0;
			normal[1] = 1.0;
			normal[2] = 0.0;
			break;
		case SCENE_MODE_ISOMERIC:
			eye[0] = 1.0;
			eye[1] = 1.0;
			eye[2] = 1.0;

			focus[0] = 0.0;
			focus[1] = 0.0;
			focus[2] = 0.0;

			normal[0] = 0.0;
			normal[1] = 1.0;
			normal[2] = 0.0;
			break;
		case SCENE_MODE_TOP:
			eye[0] = 0.5;
			eye[1] = 1.0;
			eye[2] = 0.5;

			focus[0] = 0.5;
			focus[1] = 0.0;
			focus[2] = 0.5;

			normal[0] = 0.0;
			normal[1] = 0.0;
			normal[2] = -1.0;
			break;
		case SCENE_MODE_RIGHT:
			eye[0] = 1.0;
			eye[1] = 0.5;
			eye[2] = 0.5;

			focus[0] = 0.0;
			focus[1] = 0.5;
			focus[2] = 0.5;

			normal[0] = 0.0;
			normal[1] = 1.0;
			normal[2] = 0.0;
			break;
		case SCENE_MODE_LEFT:
			eye[0] = 0.0;
			eye[1] = 0.5;
			eye[2] = 0.5;

			focus[0] = 1.0;
			focus[1] = 0.5;
			focus[2] = 0.5;

			normal[0] = 0.0;
			normal[1] = 1.0;
			normal[2] = 0.0;
			break;
		default:
			std::cout << "Camera::setupCamera() mode invalido" << std::endl;
			break;
	}

}

void Camera::setSceneBounds(float w, float h, float l){
	sceneBounds.width = w;
	sceneBounds.height = h;
	sceneBounds.length = l;
}

void Camera::setupCamera(){
	gluLookAt(
		eye[0],eye[1],eye[2],  // eye
		focus[0],focus[1],focus[2],  // focus
		normal[0],normal[1],normal[2]); // normal
}

void Camera::moveForward( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage*M_PI/2;
	float eyeX = eye[0] - 2*cos(angle);
	float eyeZ = eye[2] - 2*sin(angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye[0] = eyeX;
		eye[2] = eyeZ;

		setFocusPosition();
	} 

}

void Camera::moveBackward( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage*M_PI/2;
	float eyeX = eye[0] + 2*cos(angle);
	float eyeZ = eye[2] + 2*sin(angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye[0] = eyeX;
		eye[2] = eyeZ;

		setFocusPosition();
	} 
}

void Camera::moveLeft( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage*M_PI/2;
	float eyeX = eye[0] - 2*cos(M_PI/2 - angle);
	float eyeZ= eye[2] + 2*sin(M_PI/2 - angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye[0] = eyeX;
		eye[2] = eyeZ;

		setFocusPosition();
	}
}

void Camera::moveRight( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage*M_PI/2;
	float eyeX = eye[0] + 2*cos(M_PI/2 - angle);
	float eyeZ = eye[2] - 2*sin(M_PI/2 - angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye[0] = eyeX;
		eye[2] = eyeZ;

		setFocusPosition();
	}
}

void Camera::setFocusPosition(){
	if (mode != SCENE_MODE_NAVIGATION)
		return;

	float angle = anglePercentage*M_PI/2;

	focus[0] = eye[0] - cos(angle);
	focus[1] = eye[1];
	focus[2] = eye[2] - sin(angle);
}

void Camera::setFocusPosition(int x,int y){
	if (mode != SCENE_MODE_NAVIGATION)
		return;

	anglePercentage = 4*((float) x - screenBounds[0])/screenBounds[2] - 1.5;
	setFocusPosition();
}

void Camera::getEyePosition(float *x, float *y, float *z){
	*x = eye[0];
	*y = eye[1];
	*z = eye[2];
}

void Camera::getFocusPosition(float *x, float *y, float *z){
	*x = focus[0];
	*y = focus[1];
	*z = focus[2];
}

void Camera::setScreenBounds(float x, float y, float width, float height){
	screenBounds[0] = x;
	screenBounds[1] = y;
	screenBounds[2] = width;
	screenBounds[3] = height;
}

void Camera::setVisionAngle(float ang){
	visionAngle = ang;
}

float Camera::getVisionAngle(){
	return visionAngle;
}

void Camera::setPosition(float x, float y, float z){
	if (mode != SCENE_MODE_NAVIGATION)
		return;

	eye[0] = x;
	eye[1] = y;
	eye[2] = z;

	setFocusPosition();
}
