#include "utils.h"

#include <vector>
#include <array>

#include "solid.h"
#include "scene.h"

#include "editor.h"

int roomW = 284, roomL = 308, roomH = 250;
int screenWidth = SCREEN_WIDTH, screenHeight = SCREEN_HEIGHT;
Scene scene, scene2;
Editor editor;
GLuint textureId;

bool isEditing = false;

float getScreenWidth(){
	return screenWidth;
}

float getScreenHeight(){
	return screenHeight;
}

GLuint getTextureId(){
	return textureId;
}

GLuint LoadTexture( const char * filename )
{

	GLuint texture;

	int width, height;

	unsigned char * data;

	FILE * file;

	file = fopen( filename, "rb" );

	if ( file == NULL ) return 0;
	width = 1024;
	height = 512;
	data = (unsigned char *)malloc( width * height * 3 );
	//int size = fseek(file,);
	fread( data, width * height * 3, 1, file );
	fclose( file );

	for(int i = 0; i < width * height ; ++i)
	{
		int index = i*3;
		unsigned char B,R;
		B = data[index];
		R = data[index+2];

		data[index] = R;
		data[index+2] = B;

	}

	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
	free( data );

	return texture;
}

void Reshape(int width,int height){
	screenWidth = width;
	screenHeight = height;
	glViewport(0,0,width,height);
	glMatrixMode(GL_MODELVIEW);

	// scene.setScreenPosition((screenWidth - roomW*2)/2,screenHeight - roomH*2);

	scene.setViewport(screenWidth,screenHeight);
	scene.setScreenPosition(0,0);

	glutPostRedisplay();
}

void SceneDraw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (isEditing)
		editor.draw();
	else{
		scene.draw();
		// scene2.draw();
	}
	
	// glColor3f(1.0,1.0,1.0);
	// glBegin(GL_QUADS);
	// 	glNormal3f(0.0,0.0,1.0);
	// 	glTexCoord2f(0.0,0.0);
	// 	glVertex3f(0.0,0.0,0.0);

	// 	glNormal3f(0.0,0.0,1.0);
	// 	glTexCoord2f(1.0,0.0);
	// 	glVertex3f(300.0,0.0,0.0);

	// 	glNormal3f(0.0,0.0,1.0);
	// 	glTexCoord2f(1.0,1.0);
	// 	glVertex3f(300.0,300.0,0.0);

	// 	glNormal3f(0.0,0.0,1.0);
	// 	glTexCoord2f(0.0,1.0);
	// 	glVertex3f(0.0,300.0,0.0);		
	// glEnd();

	glutSwapBuffers();

}

bool checkCollision(float x, float y, float z){
	return scene.checkCollision(x,y,z);
}

void KeyHandler(unsigned char key,int x, int y){

	if (key == 'e'){
		isEditing = ! isEditing;
		glutPostRedisplay();
		return;
	}

	if (isEditing){

		if (key == 'i')
			editor.createSolid(100,100,100);
		else if(key == 't')
			editor.setSceneMode(SCENE_MODE_TOP);
		else if(key == 'r')
			editor.setSceneMode(SCENE_MODE_RIGHT);
		else if (key == 'p')
			editor.setSceneMode(SCENE_MODE_ISOMERIC);
		else if (key == 'd')
			editor.finalize();

		glutPostRedisplay();

		return;
	}

	Camera* c = scene.getCamera();

	if (key == 'w'){
		c->moveForward(checkCollision);
	} else if ( key == 's') {
		c->moveBackward(checkCollision);
	} else if ( key == 'a') {
		c->moveLeft(checkCollision);
	} else if ( key == 'd') {
		c->moveRight(checkCollision);
	}

	glutPostRedisplay();
}

void PassiveMotionHandler(int x, int y){
	std::cout << "MotionHandler(int x, int y) x = " << x << ", y = " << y << std::endl;
	if (isEditing){
		editor.setMousePosition(x,y);
		glutPostRedisplay();
		return;
	}

	Camera* c = scene.getCamera();

	c->notifyMouseMotion(x,y);

	glutPostRedisplay();
}

void MotionHandler(int x, int y){
	Camera *c = scene.getCamera();
	c->notifyMouseDrag(x,y);
	glutPostRedisplay();
}

void MouseHandler(int button, int state, int x, int y){
	std::cout << "MouseHandler(int x, int y) x = " << x << ", y = " << y << std::endl;
	if (button != GLUT_LEFT_BUTTON)
		return;

	if (state == GLUT_DOWN)
		scene.getCamera()->notifyMousePressed(x,y);
	else
		scene.getCamera()->notifyMouseReleased(x,y);

	glutPostRedisplay();
}

void setupLight(){

	GLfloat light_ambient[] = {0.8,0.8,0.8,1.0};
	GLfloat light_diffuse[] = {1.5,1.5,1.5,1.0};
	GLfloat light_specular[] = {1.5,1.5,1.5,1.0};
	GLfloat light_model_ambient[] = {0.2,0.2,0.2,1.0};
	GLfloat light_position[] = { 0.5, 1.0, 0.5, 0.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_model_ambient);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,0.1);
	glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,0.1);
	glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,0.1);

	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

}

void initDefaultScene(){
	//Armario
	Solid armario(
		0.0,0.0,0.0,
		(float) 57.5, roomH,60
	);
	scene.addSolid(&armario);

	//Divisoria
	Solid divisoria(
		0.0,0.0,(float) 60,
		(float) 168.8, (float) 120, (float) 10
	);
	scene.addSolid(&divisoria);

	Solid divisoria_virada(
		148.1,0.0,70,
		20.0,120.0,40.0
	);
	scene.addSolid(&divisoria_virada);

	//Cama
	Solid cama(
		0.0,0.0, (float) 70,
		(float) 148,(float) 75,(float) 188
	);
	scene.addSolid(&cama);

	//Prateleira
	Solid prateleira(
		0.0,roomH-84,(float) 60,
		(float) 30, (float) 84, (float) 200 
	);
	scene.addSolid(&prateleira);

	//Mesa
	Solid mesa(
		(float) roomW - 50, 0.0, (float) roomL - 140,
		50, (float) 50, 140
	); 
	scene.addSolid(&mesa);
}

int main(int argc, char** argv){
	std::cout << "Iniciando Hello World..." << std::endl;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// glutInitWindowSize(roomW*2,roomL*2);
	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);

	glutInitWindowPosition(200,200);
	glutCreateWindow("Hello World!");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	//glBlendFunc(GL_CONSTANT_COLOR,GL_ZERO);
	//glEnable(GL_RASTERIZER_DISCARD);
	//glEnable(GL_CULL_FACE);
	std::cout << "LOADING TEXTURE" << std::endl;
	textureId = LoadTexture("carpet.bmp");
	std::cout << "LOADED TEXTURE" << std::endl;


	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(-roomW,roomW,-roomH,roomH,-roomL,roomL);
	glOrtho(-SCREEN_WIDTH,SCREEN_WIDTH,-SCREEN_HEIGHT,SCREEN_HEIGHT,-SCREEN_WIDTH,SCREEN_WIDTH);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//setupLight();

	//Armario
	Solid armario(
		0.0,0.0,0.0,
		(float) 57.5, roomH,60
	);

	//Divisoria
	Solid divisoria(
		0.0,0.0,(float) 60,
		(float) 168.8, (float) 120, (float) 10
	);

	Solid divisoria_virada(
		148.1,0.0,70,
		20.0,120.0,40.0
	);

	//Cama
	Solid cama(
		0.0,0.0, (float) 70,
		(float) 148,(float) 75,(float) 188
	);

	//Prateleira
	Solid prateleira(
		0.0,roomH-84,(float) 60,
		(float) 30, (float) 84, (float) 200 
	);

	//Mesa
	Solid mesa(
		(float) roomW - 50, 0.0, (float) roomL - 140,
		50, (float) 50, 140
	); 

	scene.addSolid(&armario);
	scene.addSolid(&divisoria);
	scene.addSolid(&divisoria_virada);
	scene.addSolid(&cama);
	scene.addSolid(&prateleira);
	scene.addSolid(&mesa);

	// scene2.addSolid(&armario);
	// scene2.addSolid(&divisoria);
	// scene2.addSolid(&divisoria_virada);
	// scene2.addSolid(&cama);
	// scene2.addSolid(&prateleira);
	// scene2.addSolid(&mesa);

	scene.setViewport(screenWidth, screenHeight);
	// scene.setViewport(roomW*2,roomL*2);
	scene.setScreenPosition(0,0);
	scene.setScale(1);
	scene.setBounds(roomW,roomH,roomL);
	scene.setMode(SCENE_MODE_ISOMERIC);
	// scene.setMode(SCENE_MODE_NAVIGATION);
	scene.init();

	// scene2.setScreenPosition((int) SCREEN_WIDTH/2,0);
	// scene2.setViewport(roomW,roomH);
	// scene2.setScale(1);
	// scene2.setBounds(roomW,roomH,roomL);
	// scene2.setMode(SCENE_MODE_TOP);
	// scene2.init();	

	editor.setMainScene(&scene);
	editor.init();

	glutDisplayFunc(SceneDraw);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyHandler);
	glutPassiveMotionFunc(PassiveMotionHandler);
	glutMotionFunc(MotionHandler);
	glutMouseFunc(MouseHandler);

	// std::cout << "Colision? " << scene.checkCollision(0.0,0.0,0.0) << std::endl;
	// Solid s(0.0,0.0,0.0,1.0,1.0,1.0);
	// std::cout << "Solid collision? " << s.hit(0.5,0.5,1.5) << std::endl;

	glutMainLoop();
	return 0;
}
