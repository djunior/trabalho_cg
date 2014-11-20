#include "camera.h"

Camera::Camera(){
	eye[0] = 1.0;
	eye[1] = 1.0;
	eye[2] = 1.0;
	anglePercentage = 0.5;

	normal[0] = 0.0;
	normal[1] = 1.0;
	normal[2] = 1.0;

	visionAngle = 120;
}

Camera::~Camera(){

}

Camera::Camera(SceneMode m){
	mode = m;
}

void Camera::setMode(SceneMode m){
	mode = m;
}

void Camera::setupCamera(){
	float angle = anglePercentage*M_PI/2;
	gluLookAt(
		eye[0],eye[1],eye[2],  // eye
		eye[0] - cos(angle),eye[1],eye[2] - sin(angle),  // focus
		0.0,1.0,0.0); // normal
}

void Camera::moveForward(){
	float angle = anglePercentage*M_PI/2;
	eye[0] -= 2*cos(angle);
	eye[2] -= 2*sin(angle);
}

void Camera::moveBackward(){
	float angle = anglePercentage*M_PI/2;
	eye[0] += 2*cos(angle);
	eye[2] += 2*sin(angle);
}

void Camera::moveLeft(){
	float angle = anglePercentage*M_PI/2;
	eye[0] -= 2*cos(M_PI/2 - angle);
	eye[2] += 2*sin(M_PI/2 - angle);
}

void Camera::moveRight(){
	float angle = anglePercentage*M_PI/2;
	eye[0] += 2*cos(M_PI/2 - angle);
	eye[2] -= 2*sin(M_PI/2 - angle);
}

void Camera::setFocus(int x,int y){
	float aux = ((float) x - screenBounds[0])/screenBounds[2];
	std::cout << "Camera::setFocus(x = " << x << ",y = " << y << ") aux = " << aux << ", anglePercentage = " << anglePercentage << std::endl;
	// if (aux > 0.9){
	// 	anglePercentage += 0.01;
	// } else if (aux < 0.1) {
	// 	anglePercentage -= 0.01;
	// } else {	
	// 	if (anglePercentage > 1)
	// 		anglePercentage -= (1 - aux)/100;
	// 	else if (anglePercentage < 0)
	// 		anglePercentage += (aux)/100;
	// 	else
	// 		anglePercentage = aux;
	// }

	anglePercentage = 4*aux - 1.5;

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
	eye[0] = x;
	eye[1] = y;
	eye[2] = z;
}
