#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic_includes.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Chamada dos connects
    PublicConnects();
	
}

MainWindow::~MainWindow()
{
    delete ui;
}

//########################### public declarations ##################################
// void updatePositionSpinBoxCallback(float x,float y,float z){

// }

void MainWindow::PublicConnects()
{

    /*################################################################################*/
    /*############### CRIANDO OS CONECTS PARA ACESSAR FUNCIONALIDADES ################*/
    /*################################################################################*/

    //Menu principal:

	//New
	connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(slotNewFile()));

    //Open
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(slotOpenFile()));

	//Save
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(slotSaveFile()));

    //Exit
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));

    //Botoes da Interface
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotElementValue(int)));


	connect(ui->tabWidget, SIGNAL(currentChanged(int)),this,SLOT(tabChanged(int)));

    //Add Element //botar osignal correto, value changed n�o permite usar a mesma op��o 2x seguidas
	connect(ui->comboBox , SIGNAL(currentIndexChanged(int)), this, SLOT(novoElemento(int)));
	connect(ui->adicionar , SIGNAL(clicked()), this, SLOT(aplicar()));
	connect(ui->posicionar,SIGNAL(clicked()),this,SLOT(positionElement()));
	//Delet element
	connect(ui->deletar , SIGNAL(clicked()), this, SLOT(deletarElemento()));

	// Camera
	connect(ui->isomerico, SIGNAL(clicked()), this, SLOT(isomerico()));
	connect(ui->ortogonal, SIGNAL(clicked()), this, SLOT(ortogonal()));
	connect(ui->topo,SIGNAL(clicked()),this,SLOT(topo()));

	connect(ui->cbAxis, SIGNAL(clicked()),this,SLOT(clickedAxis()));

	connect(ui->painelGL,SIGNAL(updateSpinBox(float,float,float)),this,SLOT(updatePositionSpinBox(float,float,float)));
	connect(ui->painelGL,SIGNAL(updateCameraPosition(float,float,float)),this,SLOT(updateCameraSpinBox(float,float,float)));

	connect(ui->posicionarCamera,SIGNAL(clicked()),this,SLOT(positionCameraByMouse()));

	connect(ui->spinBoxCameraX,SIGNAL(valueChanged(double)),this,SLOT(positionCamera()));
	connect(ui->spinBoxCameraY,SIGNAL(valueChanged(double)),this,SLOT(positionCamera()));
	connect(ui->spinBoxCameraZ,SIGNAL(valueChanged(double)),this,SLOT(positionCamera()));

	connect(ui->spinBoxRotation,SIGNAL(valueChanged(int)),this,SLOT(rotateElement()));

	if (ui->isomerico->isChecked())
		ui->painelGL->setMode(SCENE_MODE_ISOMERIC);
	else if(ui->ortogonal->isChecked())
		ui->painelGL->setMode(SCENE_MODE_NAVIGATION);
	else
		ui->painelGL->setMode(SCENE_MODE_TOP);

	// ui->painelGL->setTextures(ui->cbTexturas->isChecked());

	// ui->painelGL->showAxis(ui->cbAxis->isChecked());
	// ui->painelGL->setUpdateUICallback( &updatePositionSpinBox );
	clickedAxis();

}

void MainWindow::rotateElement(){
	ui->painelGL->rotateSolid(ui->spinBoxRotation->value());
}

void MainWindow::updateRotationSpinBox(float r){
	ui->spinBoxRotation->setValue((int) r);
}

void MainWindow::positionCameraByMouse(){
	ui->painelGL->positionCameraByMouse();
}

void MainWindow::positionCamera(){
	float x = ui->spinBoxCameraX->value();
	float y = ui->spinBoxCameraY->value();
	float z = ui->spinBoxCameraZ->value();
	ui->painelGL->positionCamera(x,y,z);
}

void MainWindow::tabChanged(int index){
	ui->painelGL->tabChanged(index);
}

//preenche a tabela de acordo com os dados lidos do arquivo

//########################## public functions ######################################

void MainWindow::setColor(int r, int g , int b)
{
	// ui->painelGL->setRed(r);
	// ui->painelGL->setGreen(g);
	// ui->painelGL->setBlue(b);

	// ui->spinBoxRed->setValue(r);
	// ui->spinBoxGreen->setValue(g);
	// ui->spinBoxBlue->setValue(b);
}

void MainWindow::setSize(float h, float w, float l)
{
	ui->spinBoxH->setValue(h);
	ui->spinBoxW->setValue(w);
	ui->spinBoxL->setValue(l);
}

void MainWindow::setPosition(float x, float y, float z)
{
	ui->spinBoxX->setValue(x);
	ui->spinBoxY->setValue(y);
	ui->spinBoxZ->setValue(z);
}


//########################## public slots ##########################################

void MainWindow::slotElementValue(int index)
{
	std::cout << "MainWindow::slotElementValue(int index = " << index << ")" << std::endl;
}

//criacao de novo arquivo
void MainWindow::slotNewFile()
{
	ui->painelGL->stopTimer();

	QDialog dialog(this);
	QFormLayout form(&dialog);

	form.addRow(new QLabel("Dimensões da cena:"));

	QList<QLineEdit *> fields;
	QString labels[3] = {"Comprimento :","Altura :","Largura :"};
	for(int i = 0; i < 3; ++i) {
	    QLineEdit *lineEdit = new QLineEdit(&dialog);
		QIntValidator *intValidator = new QIntValidator(1,999,lineEdit);
		lineEdit->setValidator(intValidator);
	    form.addRow(labels[i], lineEdit);
	    fields << lineEdit;
	}

	QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
	                           Qt::Horizontal, &dialog);
	form.addRow(&buttonBox);
	QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
	QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

	if (dialog.exec() == QDialog::Accepted) {
		QString widthString = fields[0]->text();
		QString heightString = fields[1]->text();
		QString lengthString = fields[2]->text();
		if (widthString != "" && heightString != "" && lengthString != "")
			ui->painelGL->newScene(widthString.toInt(),heightString.toInt(),lengthString.toInt());
	}

	ui->painelGL->startTimer();

}

//leitura de um arquivo
void MainWindow::slotOpenFile()
{
	ui->painelGL->stopTimer();

	// ui->painelGL->initializeGL();
	//chamando uma caixa de Dialogo para escolher o arquivo de dados
    fullPath = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Text files (*.txt)"));

	ui->painelGL->startTimer();

	QFileInfo f(fullPath);
	filePath = f.filePath();
	fileName = f.baseName();
	// � necess�rio implementar a forma como vai ser feita a leitura do arquivo

	ui->painelGL->load(fullPath.toStdString());
}

//escrita do arquivo
void MainWindow::slotSaveFile()
{
	ui->painelGL->stopTimer();

	fullPath = QFileDialog::getSaveFileName(this, tr("Save File"),"", tr("Text files (*.txt)"));

	ui->painelGL->startTimer();

	QFileInfo f(fullPath);
	filePath = f.filePath();
	fileName = f.baseName();	

	ui->painelGL->save(fullPath.toStdString());
}

void MainWindow::novoElemento(int index)
{
	//fun��o de adicionar elemento
	if(index == 0)
	{
		// ui->spinBoxBlue->setValue(0);
		// ui->spinBoxGreen->setValue(0);
		ui->spinBoxH->setValue(0);
		ui->spinBoxL->setValue(0);
		// ui->spinBoxRed->setValue(0);
		ui->spinBoxW->setValue(0);
		ui->spinBoxX->setValue(0);
		ui->spinBoxY->setValue(0);
		ui->spinBoxZ->setValue(0);
	}
	else if(index == 1)
	{
		// ui->spinBoxBlue->setValue(DEFAULT_MESA_BLUE);
		// ui->spinBoxGreen->setValue(DEFAULT_MESA_GREEN);
		ui->spinBoxH->setValue(DEFAULT_MESA_HEIGHT);
		ui->spinBoxL->setValue(DEFAULT_MESA_LENGTH);
		// ui->spinBoxRed->setValue(DEFAULT_MESA_RED);
		ui->spinBoxW->setValue(DEFAULT_MESA_WIDTH);
		ui->spinBoxX->setValue(DEFAULT_MESA_X);
		ui->spinBoxY->setValue(DEFAULT_MESA_Y);
		ui->spinBoxZ->setValue(DEFAULT_MESA_Z);
	}
	else if(index == 2)
	{
		// ui->spinBoxBlue->setValue(DEFAULT_CAMA_BLUE);
		// ui->spinBoxGreen->setValue(DEFAULT_CAMA_GREEN);
		ui->spinBoxH->setValue(DEFAULT_CAMA_HEIGHT);
		ui->spinBoxL->setValue(DEFAULT_CAMA_LENGTH);
		// ui->spinBoxRed->setValue(DEFAULT_CAMA_RED);
		ui->spinBoxW->setValue(DEFAULT_CAMA_WIDTH);
		ui->spinBoxX->setValue(DEFAULT_CAMA_X);
		ui->spinBoxY->setValue(DEFAULT_CAMA_Y);
		ui->spinBoxZ->setValue(DEFAULT_CAMA_Z);
	}
	else if(index == 3)
	{
		// ui->spinBoxBlue->setValue(DEFAULT_CADEIRA_BLUE);
		// ui->spinBoxGreen->setValue(DEFAULT_CADEIRA_GREEN);
		ui->spinBoxH->setValue(DEFAULT_CADEIRA_HEIGHT);
		ui->spinBoxL->setValue(DEFAULT_CADEIRA_LENGTH);
		// ui->spinBoxRed->setValue(DEFAULT_CADEIRA_RED);
		ui->spinBoxW->setValue(DEFAULT_CADEIRA_WIDTH);
		ui->spinBoxX->setValue(DEFAULT_CADEIRA_X);
		ui->spinBoxY->setValue(DEFAULT_CADEIRA_Y);
		ui->spinBoxZ->setValue(DEFAULT_CADEIRA_Z);
	}
	else if(index == 4)
	{
		// ui->spinBoxBlue->setValue(DEFAULT_GAVETEIRO_BLUE);
		// ui->spinBoxGreen->setValue(DEFAULT_GAVETEIRO_GREEN);
		ui->spinBoxH->setValue(DEFAULT_GAVETEIRO_HEIGHT);
		ui->spinBoxL->setValue(DEFAULT_GAVETEIRO_LENGTH);
		// ui->spinBoxRed->setValue(DEFAULT_GAVETEIRO_RED);
		ui->spinBoxW->setValue(DEFAULT_GAVETEIRO_WIDTH);
		ui->spinBoxX->setValue(DEFAULT_GAVETEIRO_X);
		ui->spinBoxY->setValue(DEFAULT_GAVETEIRO_Y);
		ui->spinBoxZ->setValue(DEFAULT_GAVETEIRO_Z);	
	}
	else if(index == 5)
	{
		// ui->spinBoxBlue->setValue(DEFAULT_ARMARIO_BLUE);
		// ui->spinBoxGreen->setValue(DEFAULT_ARMARIO_GREEN);
		ui->spinBoxH->setValue(DEFAULT_ARMARIO_HEIGHT);
		ui->spinBoxL->setValue(DEFAULT_ARMARIO_LENGTH);
		// ui->spinBoxRed->setValue(DEFAULT_ARMARIO_RED);
		ui->spinBoxW->setValue(DEFAULT_ARMARIO_WIDTH);
		ui->spinBoxX->setValue(DEFAULT_ARMARIO_X);
		ui->spinBoxY->setValue(DEFAULT_ARMARIO_Y);
		ui->spinBoxZ->setValue(DEFAULT_ARMARIO_Z);
	}

}

void MainWindow::updatePositionSpinBox(float x, float y, float z){
	ui->spinBoxX->setValue(x);
	ui->spinBoxY->setValue(y);
	ui->spinBoxZ->setValue(z);
}

void MainWindow::updateCameraSpinBox(float x, float y, float z){
	ui->spinBoxCameraX->setValue(x);
	ui->spinBoxCameraY->setValue(y);
	ui->spinBoxCameraZ->setValue(z);
}

void MainWindow::deletarElemento()
{
	ui->painelGL->deleteSolid();
}

void MainWindow::positionElement(){
	ui->painelGL->positionSolid(ui->spinBoxX->value(),ui->spinBoxY->value(),ui->spinBoxZ->value());
}

//saida da aplicacao
void MainWindow::slotExit()
{
	qApp->exit(0);
}

void MainWindow::aplicar()
{
	// float values[10];
	// values[0] = ui->spinBoxRed->value();
	// values[1] = ui->spinBoxGreen->value();
	// values[2] = ui->spinBoxBlue->value();
	// values[3] = ui->spinBoxH->value();
	// values[4] = ui->spinBoxW->value();
	// values[5] = ui->spinBoxL->value();
	// values[6] = ui->spinBoxX->value();
	// values[7] = ui->spinBoxY->value();
	// values[8] = ui->spinBoxZ->value();
	// values[9] = ui->comboBox->currentIndex();
	// values[10] = (float) ui->spinBoxRotation->value();

	//ui->painelGL->getValues(values);
	ui->painelGL->addSolid(
		ui->comboBox->currentIndex(),
		ui->spinBoxX->value(),ui->spinBoxY->value(),ui->spinBoxZ->value(),
		ui->spinBoxW->value(),ui->spinBoxH->value(),ui->spinBoxL->value(),ui->spinBoxRotation->value());
}

void MainWindow::isomerico()
{
	ui->painelGL->setMode(SCENE_MODE_ISOMERIC);
}

void MainWindow::topo()
{
	ui->painelGL->setMode(SCENE_MODE_TOP);
}

void MainWindow::ortogonal()
{	
	ui->painelGL->setMode(SCENE_MODE_NAVIGATION);	
}

void MainWindow::clickedTextures(){

}

void MainWindow::clickedAxis(){
	ui->painelGL->showAxis(ui->cbAxis->isChecked());
}