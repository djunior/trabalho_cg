#ifndef MEUPAINELOPENGL_H
#define MEUPAINELOPENGL_H

#define DEFAULT_MESA_BLUE		255
#define DEFAULT_MESA_RED		255
#define DEFAULT_MESA_GREEN		255
#define DEFAULT_MESA_X			0.0
#define DEFAULT_MESA_Y			0.0
#define DEFAULT_MESA_Z			0.0
#define DEFAULT_MESA_HEIGHT		80
#define DEFAULT_MESA_WIDTH		50
#define DEFAULT_MESA_LENGTH		140

#define DEFAULT_CADEIRA_BLUE	255
#define DEFAULT_CADEIRA_RED		255
#define DEFAULT_CADEIRA_GREEN	255
#define DEFAULT_CADEIRA_X		0.0
#define DEFAULT_CADEIRA_Y		0.0
#define DEFAULT_CADEIRA_Z		0.0
#define DEFAULT_CADEIRA_HEIGHT	95
#define DEFAULT_CADEIRA_WIDTH	50
#define DEFAULT_CADEIRA_LENGTH	50

#define DEFAULT_CAMA_BLUE		255
#define DEFAULT_CAMA_RED		255
#define DEFAULT_CAMA_GREEN		255
#define DEFAULT_CAMA_X			0.0
#define DEFAULT_CAMA_Y			0.0
#define DEFAULT_CAMA_Z			0.0
#define DEFAULT_CAMA_HEIGHT		60
#define DEFAULT_CAMA_WIDTH		88
#define DEFAULT_CAMA_LENGTH		188

#define DEFAULT_GAVETEIRO_BLUE		255
#define DEFAULT_GAVETEIRO_RED		255
#define DEFAULT_GAVETEIRO_GREEN		255
#define DEFAULT_GAVETEIRO_X			0.0
#define DEFAULT_GAVETEIRO_Y			0.0
#define DEFAULT_GAVETEIRO_Z			0.0
#define DEFAULT_GAVETEIRO_HEIGHT		80
#define DEFAULT_GAVETEIRO_WIDTH			40
#define DEFAULT_GAVETEIRO_LENGTH		40

#define DEFAULT_ARMARIO_BLUE		255
#define DEFAULT_ARMARIO_RED			255
#define DEFAULT_ARMARIO_GREEN		255
#define DEFAULT_ARMARIO_X			0.0
#define DEFAULT_ARMARIO_Y			0.0
#define DEFAULT_ARMARIO_Z			0.0
#define DEFAULT_ARMARIO_HEIGHT		200
#define DEFAULT_ARMARIO_WIDTH		40
#define DEFAULT_ARMARIO_LENGTH		80

#ifdef _WIN32
#include "C:\freeglut\include\GL\freeglut.h"
#endif

#include <string>

using namespace std;

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <sstream>

#include <cstdio>
#include <iostream>

#include "utils.h"
#include <vector>

#include "solid.h"
#include "scene.h"
#include "editor.h"
#include "textureHandler.h"

#include <QMouseEvent>
#include <QTimer>
#include <QCoreApplication>

#define MAX_BUFFER 1000

#include <QGLWidget>

/* Caro David:
As funções do OpenGL geralmente declaradas e aplicadas a partir da main.cpp devem ser implementadas nessa classe,
seguindo o modelo da função paintGL() que pinta um poligono arbitrário na tela.
*/

class MeuPainelOpenGL : public QGLWidget
{
Q_OBJECT

private:
    int lados;
    double raio;
	
	float red, green, blue;
	float height, width, length;
	bool positioningCamera;
	float x,y,z;
	QTimer *timer, *panScreenTimer;

	SceneMode mode;

public:
    explicit MeuPainelOpenGL(QWidget *parent = 0);

	void initializeGL();
	void resizeGL(int width, int height);
    void paintGL();
	void getValues(float[11]);
	void setValues(float[11]);
	void setMode(SceneMode);
	void setTextures(bool);
	void showAxis(bool);
	void save(std::string);
	void load(std::string);
	void startTimer();
	void stopTimer();
	void newScene(int,int,int);
	void deleteSolid();
	void positionSolid(float x, float y, float z);
	void finishEditing();
	void positionCamera(float,float,float);
	void tabChanged(int);
	void positionCameraByMouse();
	void rotateSolid(int);

protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);

signals:
	
	void updateSpinBox(float, float, float);
	void updateCameraPosition(float, float, float);

public slots:

    void alterarCor();
	void setColor(int r, int g, int b);
	void setRed(int r);
	void setGreen(int g);
	void setBlue(int b);
	void update();
	void generateFakeMouseEvent();
};

#endif // MEUPAINELOPENGL_H
