#include "MeuPainelOpenGL.h"
#include <cmath>

int roomW = 284, roomL = 308, roomH = 250;
int screenWidth = SCREEN_WIDTH, screenHeight = SCREEN_HEIGHT;

Scene scene;
TextureHandler textureHandler;
Editor editor;
QPoint mousePoint;

bool isEditing = false;

TextureHandler* getTextureHandler(){
    return &textureHandler;
}

bool checkCollision(float x, float y, float z){
    return scene.checkCollision(x,y,z);
}

void setupLight(){

    GLfloat light_ambient[] = {0.8,0.8,0.8,1.0};
    GLfloat light_diffuse[] = {1.5,1.5,1.5,1.0};
    GLfloat light_specular[] = {1.5,1.5,1.5,1.0};
    GLfloat light_model_ambient[] = {0.2,0.2,0.2,1.0};
    GLfloat light_position[] = { 0.5, 1.0, 0.5, 00 };

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
    // editor.load("arquivoDeTeste.txt");

    scene.setBounds(300,300,300);
    // editor.startEditing();
    // editor.createSolid(SOLID_TYPE_GENERIC,0,0,0,100,70,50); 
    // editor.finalize();]
}

MeuPainelOpenGL::MeuPainelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
	setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
    lados = 3;
    raio = 1.0;
	green = 0.0;
	red = 0.0;
	blue = 0.0;

    setUpdatesEnabled(true);
    setMouseTracking(true); 
    setFocusPolicy(Qt::ClickFocus);

    positioningCamera = false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    panScreenTimer = new QTimer(this);
    panScreenTimer->setSingleShot(true);
    connect(panScreenTimer, SIGNAL(timeout()), this, SLOT(generateFakeMouseEvent()));

}

void MeuPainelOpenGL::tabChanged(int index){
    if (index == 0){

        editor.stopEditing();

        scene.setMode(mode);
    } else {
        scene.setMode(SCENE_MODE_ISOMERIC);
    }
}

void MeuPainelOpenGL::positionCamera(float x, float y, float z){
    scene.setCameraPosition(x,y,z);
}

void MeuPainelOpenGL::positionCameraByMouse(){
    std::cout << "MeuPainelOpenGL::positionCameraByMouse()" << std::endl;
    positioningCamera = true;
}

void MeuPainelOpenGL::startTimer(){
    timer->start();
}

void MeuPainelOpenGL::stopTimer(){
    timer->stop();
}

void MeuPainelOpenGL::setColor(int r, int g, int b)
{
	setRed(r);
	setGreen(g);
	setBlue(b);
}

void MeuPainelOpenGL::setRed(int r)
{
	red = float(1.0*r);
	red = red/255.0;
	//red = r;
	update();
}

void MeuPainelOpenGL::setGreen(int g)
{
	green = float(1.0*g);
	green = green/255.0;
	//green = g;
	update();
}
void MeuPainelOpenGL::setBlue(int b)
{
	blue = float(1.0*b);
	blue = blue/255.0;
	//blue = b;
	update();
}

void MeuPainelOpenGL::alterarCor()
{
    glColor3f(red,green,blue);
}

void MeuPainelOpenGL::update()
{
	updateGL();
}


void MeuPainelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);

    setupLight();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-SCREEN_WIDTH,SCREEN_WIDTH,-SCREEN_HEIGHT,SCREEN_HEIGHT,-SCREEN_WIDTH,SCREEN_WIDTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    scene.setViewport(screenWidth, screenHeight);
    scene.setScreenPosition(0,0);
    scene.setScale(1.0);

    editor.setMainScene(&scene);
    editor.init();

    // scene.setBounds(400,400,400);
    // editor.createSolid(SOLID_TYPE_GENERIC, 0,0,0,100,100,100);


    initDefaultScene();

    scene.init();

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void MeuPainelOpenGL::resizeGL(int width, int height)
{
    double menorX = 0, maiorX = 10, menorY = 0, maiorY = 10;
    glViewport( 0, 0, (GLint)width, (GLint)height );

    screenWidth = width;
    screenHeight = height;

    scene.setViewport(screenWidth, screenHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluOrtho2D(-1,1,-1,1);
    if (width > height)
    {
        height = height?height:1;
        double novaLargura = (maiorX - menorX) * width / height;
        double difLargura = novaLargura - (maiorX - menorX);
        menorX = 0.0 - difLargura / 2.0;
        maiorX = 10 + difLargura / 2.0;
    }
    else
    {
        width = width?width:1;
        double novaAltura = (maiorY - menorY) * height / width;
        double difAltura = novaAltura - (maiorY - menorY);
        menorY = 0.0 - difAltura / 2.0;
        maiorY = 10 + difAltura / 2.0;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MeuPainelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene.draw();
}

void MeuPainelOpenGL::getValues(float values[11])
{
	values[0] = red;
	values[1] = green;
	values[2] = blue;
	values[3] = height;
	values[4] = width;
	values[5] = length;
	values[6] = x;
	values[7] = y;
	values[8] = z;

    Solid* s = editor.getActiveSolid();
    if (s != 0){
        values[9] = s->getType();
        values[10] = s->rotation;
    }
}

void MeuPainelOpenGL::rotateSolid(int r){
    std::cout << "MeuPainelOpenGL::rotateSolid(int r = " << r << ")" << std::endl;
    Solid *s = editor.getActiveSolid();
    if (s == 0)
        return;

    s->rotation = (float) r;
}

void MeuPainelOpenGL::addSolid(int t, float x, float y, float z, float w, float h, float l, int r){
    editor.finalize();
    editor.createSolid((SolidType) t,x,y,z,w,h,l,r);
    editor.startEditing();    

    this->x = x;
    this->y = y;
    this->z = z;
    width = w;
    height = h;
    length = l;
}

void MeuPainelOpenGL::setValues(float values[11])
{
	// red = values[0];
	// green = values[1];
	// blue = values[2];
	// height = values[3];
	// width = values[4];
	// length = values[5];
	// x = values[6];
	// y = values[7];
	// z = values[8];
 //    float rotation = values[10];

 //    editor.finalize();
 //    editor.createSolid((SolidType) values[9],x,y,z,width,height,length,rotation);
 //    editor.startEditing();
}

void MeuPainelOpenGL::positionSolid(float x,float y,float z){
    editor.startEditing();
}

void MeuPainelOpenGL::deleteSolid(){
    std::cout << "MeuPainelOpenGL::deleteSolid()" << std::endl;
    editor.removeSolid();
}

void MeuPainelOpenGL::finishEditing(){
    editor.finalize();
}

void MeuPainelOpenGL::generateFakeMouseEvent(){
    QMouseEvent event_move(QEvent::MouseMove, mousePoint, Qt::NoButton, Qt::LeftButton, Qt::NoModifier);   
    QCoreApplication::sendEvent(this, &event_move);
}

void MeuPainelOpenGL::mouseMoveEvent ( QMouseEvent * event ){
    // std::cout << "Mouse move event spontaneous?" << event->spontaneous() << std::endl;
    if(panScreenTimer->timerId() > -1)
        panScreenTimer->stop();

    int x = event->x();
    int y = event->y();

    if (positioningCamera){
        float cx,cy,cz;
        scene.convertScreenToWorldCoord(x,y,&cx,&cy,&cz);
        scene.setCameraPosition(cx,cy,cz);

        emit updateCameraPosition(cx,cy,cz);

    }
    else if (editor.isEditing()) {
        float wx,wy,wz;

        scene.convertScreenToWorldCoord(x,y,&wx,&wy,&wz);

        Solid *solid = editor.getActiveSolid();

        float rw,rh,rl;
        solid->getRotatedBounds(&rw,&rh,&rl);
        if (scene.isInsideScene(wx,solid->y,wz,rw,rh,rl)){
            solid->setPosition(wx,solid->y,wz);
            emit updateSpinBox(solid->x,solid->y,solid->z);
        }
    }

    if (scene.getMode() == SCENE_MODE_ISOMERIC)
        scene.getCamera()->notifyMouseDrag(x,y); 
    else{
        bool atEdge = scene.getCamera()->notifyMouseMotion(x,y); 

        // if (atEdge)
        //     panScreenTimer->start(10);

        mousePoint = QCursor::pos();
    }

    // editor.setSolidPosition(wx,50.0,wz);

}

void MeuPainelOpenGL::mousePressEvent(QMouseEvent *event){
    if (positioningCamera)
        positioningCamera = false;
    else if (editor.isEditing())
        editor.stopEditing();

    int x = event->x();
    int y = event->y();
    scene.getCamera()->notifyMousePressed(x,y);
}

void MeuPainelOpenGL::mouseReleaseEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    scene.getCamera()->notifyMouseReleased(x,y);
}

void MeuPainelOpenGL::keyPressEvent(QKeyEvent *event){
    if (scene.getMode() != SCENE_MODE_NAVIGATION)
        return;

    Camera* c = scene.getCamera();

    int key = event->key();
    if (key == Qt::Key_W){
        c->moveForward(checkCollision);
    } else if (key == Qt::Key_S){
        c->moveBackward(checkCollision);
    } else if (key == Qt::Key_A){
        c->moveLeft(checkCollision);
    } else if (key == Qt::Key_D){
        c->moveRight(checkCollision);
    }
}

void MeuPainelOpenGL::setMode(SceneMode m){
    mode = m;
    scene.setMode(m);
}

void MeuPainelOpenGL::setTextures(bool b){
    if (b)
        textureHandler.enable();
    else
        textureHandler.disable();
}

void MeuPainelOpenGL::showAxis(bool b){
    scene.showAxis(b);
}

void MeuPainelOpenGL::save(std::string filename){
    editor.save(filename);
}

void MeuPainelOpenGL::load(std::string filename){
    editor.clear();
    editor.load(filename);
}

void MeuPainelOpenGL::newScene(int w, int h, int l){
    editor.clear();
    scene.setBounds(w,h,l);
    scene.init();
}