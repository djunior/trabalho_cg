#include "camera.h"

Camera::Camera(){
	visionAngle = 90;

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
			eye.x = 0.0;
			eye.y = 1.0;
			eye.z = 0.0;
			
			dragBegin.x = 0;
			dragBegin.y = 0;

			anglePercentage.x = 0.5;
			anglePercentage.y = 0;

			angleOffset = 0;
			setFocusPosition();
			
			normal.x = 0.0;
			normal.y = 1.0;
			normal.z = 0.0;
			break;
		case SCENE_MODE_ISOMERIC:
			eye.x = 1.0;
			eye.y = 1.0;
			eye.z = 1.0;

			dragBegin.x = 0;
			dragBegin.y = 0;
			
			// anglePercentage.x = 0.0;
			// angleOffset = 0;
			// setFocusPosition();

			focus.x = 0.0;
			focus.y = 0.0;
			focus.z = 0.0;

			normal.x = 0.0;
			normal.y = 1.0;
			normal.z = 0.0;
			break;
		case SCENE_MODE_TOP:
			eye.x = 0.5;
			eye.y = 1.0;
			eye.z = 0.5;

			focus.x = 0.5;
			focus.y = 0.0;
			focus.z = 0.5;

			normal.x = 0.0;
			normal.y = 0.0;
			normal.z = -1.0;
			break;
		case SCENE_MODE_RIGHT:
			eye.x = 1.0;
			eye.y = 0.5;
			eye.z = 0.5;

			focus.x = 0.0;
			focus.y = 0.5;
			focus.z = 0.5;

			normal.x = 0.0;
			normal.y = 1.0;
			normal.z = 0.0;
			break;
		case SCENE_MODE_LEFT:
			eye.x = 0.0;
			eye.y = 0.5;
			eye.z = 0.5;

			focus.x = 1.0;
			focus.y = 0.5;
			focus.z = 0.5;

			normal.x = 0.0;
			normal.y = 1.0;
			normal.z = 0.0;
			break;
		default:
			std::cout << "Camera::setupCamera() mode invalido" << std::endl;
			break;
	}

}

float Camera::getVerticalAngle(){
	return anglePercentage.y*M_PI/2;
}

float Camera::getHorizontalAngle(){
	return anglePercentage.x*M_PI/2;
}

void Camera::setSceneBounds(float w, float h, float l){
	sceneBounds.width = w;
	sceneBounds.height = h;
	sceneBounds.length = l;
}

void Camera::setupCamera(){
/*

	// Tentativa de resolver um bug que ocorre no Mac OSX quando o mouse está acima de 50% da tela
	Coord3<GLdouble> F,Up,S,SNorm,U;
	F.x = (GLdouble) focus.x - (GLdouble) eye.x;
	F.y = (GLdouble) focus.y - (GLdouble) eye.y;
	F.z = (GLdouble) focus.z - (GLdouble) eye.z;

	GLdouble F_norm = sqrt( (F.x*F.x) + (F.y*F.y) + (F.z*F.z) );

	F.x = F.x/F_norm;
	F.y = F.y/F_norm;
	F.z = F.z/F_norm;

	GLdouble Up_norm = sqrt( (normal.x*normal.x) + (normal.y*normal.y) + (normal.z*normal.z) );

	Up.x = ((GLdouble) normal.x)/Up_norm;
	Up.y = ((GLdouble) normal.y)/Up_norm;
	Up.z = ((GLdouble) normal.z)/Up_norm;

	S.x = (F.y*Up.z - F.z*Up.y);
	S.y = (F.z*Up.x - F.x*Up.z);
	S.z = (F.x*Up.y - F.y*Up.z);

	GLdouble S_norm = sqrt( (S.x*S.x) + (S.y*S.y) + (S.z*S.z));

	SNorm.x = S.x/S_norm;
	SNorm.y = S.y/S_norm;
	SNorm.z = S.z/S_norm;

	U.x = (SNorm.y*F.z - SNorm.z*F.y);
	U.y = (SNorm.z*F.x - SNorm.x*F.z);
	U.z = (SNorm.x*F.y - SNorm.y*F.x);

	GLdouble m[16] = {
		S.x,U.x,-F.x,0.0,
		S.y,U.y,-F.y,0.0,
		S.z,U.z,-F.z,0.0,
		0.0,0.0, 0.0,1.0};

	glMultMatrixd(m);
	glTranslated(-eye.x,-eye.y,-eye.z);
*/

	gluLookAt(
		eye.x,eye.y,eye.z,  // eye
		focus.x,focus.y,focus.z,  // focus
		normal.x,normal.y,normal.z); // normal

}

void Camera::moveForward( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage.x*M_PI/2;
	float eyeX = eye.x - 2*cos(angle);
	float eyeZ = eye.z - 2*sin(angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye.x = eyeX;
		eye.z = eyeZ;

		setFocusPosition();
	} 

}

void Camera::moveBackward( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage.x*M_PI/2;
	float eyeX = eye.x + 2*cos(angle);
	float eyeZ = eye.z + 2*sin(angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye.x = eyeX;
		eye.z = eyeZ;

		setFocusPosition();
	} 
}

void Camera::moveLeft( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage.x*M_PI/2;
	float eyeX = eye.x - 2*cos(M_PI/2 - angle);
	float eyeZ= eye.z + 2*sin(M_PI/2 - angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye.x = eyeX;
		eye.z = eyeZ;

		setFocusPosition();
	}
}

void Camera::moveRight( bool (*callback)(float,float,float) ){
	if (mode != SCENE_MODE_NAVIGATION)
		return; 
	float angle = anglePercentage.x*M_PI/2;
	float eyeX = eye.x + 2*cos(M_PI/2 - angle);
	float eyeZ = eye.z - 2*sin(M_PI/2 - angle);

	if (!callback(eyeX + sceneBounds.width/2, 0.0, eyeZ + sceneBounds.length/2)){
		eye.x = eyeX;
		eye.z = eyeZ;

		setFocusPosition();
	}
}

void Camera::setFocusPosition(){
	if (mode != SCENE_MODE_NAVIGATION && mode != SCENE_MODE_ISOMERIC)
		return;

	float angleX = anglePercentage.x*M_PI/2;
	float angleY = anglePercentage.y*M_PI/2;

	focus.x = eye.x - cos(angleX);
	if (mode == SCENE_MODE_NAVIGATION)
		focus.y = eye.y - sin(angleY);
	else
		focus.y = eye.y + sin(angleY);
	focus.z = eye.z - sin(angleX);
}

bool Camera::notifyMouseMotion(int x,int y){
	bool atEdge = true;
	if (mode != SCENE_MODE_NAVIGATION)
		return false;

	float px = ((float) x - 0)/screenBounds.width;
	float py = ((float) y - 0)/screenBounds.height;

	if (px <= 0.1){
		anglePercentage.x = 0.1;
		angleOffset -= 0.015;
	}
	else if (px >= 0.9){
		anglePercentage.x = 0.9;
		angleOffset += 0.015;
	} else {
		atEdge = false;
	}

	anglePercentage.x = 2*px -0.5 + angleOffset;
	#ifdef __APPLE__
		anglePercentage.y = 0.01;
	#else
		anglePercentage.y = py - 0.5;
	#endif

	setFocusPosition();

	return atEdge;
}

void Camera::notifyMousePressed(int x, int y){
	if (mode != SCENE_MODE_ISOMERIC)
		return;

	isDragging = true;

	dragBegin.x = x;
	dragBegin.y = y;
}

void Camera::notifyMouseDrag(int x,int y){

	if (mode != SCENE_MODE_ISOMERIC || isDragging == false)
		return;

	float px = ((float)x - dragBegin.x)/(screenBounds.width);
	float py = -((float)y - dragBegin.y)/(screenBounds.height);

	dragBegin.x = x;
	dragBegin.y = y;

	anglePercentage.x += px;
	anglePercentage.y += py;

	//std::cout << "cos = " << cos(M_PI*anglePercentage.x/2) << "," << sin(anglePercentage.x*M_PI/2) <<std::endl;


	setFocusPosition();
}

void Camera::notifyMouseReleased(int x,int y){
	isDragging = false;

	dragBegin.x = 0;
	dragBegin.y = 0;
}


void Camera::getEyePosition(float *x, float *y, float *z){
	*x = eye.x;
	*y = eye.y;
	*z = eye.z;
}

void Camera::getFocusPosition(float *x, float *y, float *z){
	*x = focus.x;
	*y = focus.y;
	*z = focus.z;
}

void Camera::getNormal(float *x, float*y, float *z){
	*x = normal.x;
	*y = normal.y;
	*z = normal.z;
}

void Camera::setScreenBounds(float x, float y, float width, float height){
	screenBounds.position.x = x;
	screenBounds.position.y = y;
	screenBounds.width = width;
	screenBounds.height = height;
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

	eye.x = x - sceneBounds.width/2;
	eye.y = y/sceneBounds.height;
	eye.z = z - sceneBounds.length/2;

	setFocusPosition();
}
