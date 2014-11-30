#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qfiledialog.h>
#include <qfileinfo.h>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QList>
#include <QLineEdit>
#include <QIntValidator>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void setColor(int, int, int); // Valores variando de 0 a 255
	void setSize(float, float, float); // Altura, Largura, Comprimento
	void setPosition(float, float, float); // X,Y,Z
    
private:
    Ui::MainWindow *ui;
	void PublicConnects();

	QString fileName;
	QString filePath;
	QString fullPath;

public slots:
	virtual void slotElementValue(int);
	virtual void slotNewFile();
	virtual void slotOpenFile();
	virtual void slotSaveFile();
	virtual void novoElemento(int);
	virtual void deletarElemento(int);
	virtual void positionElement();
	virtual void aplicar();
    virtual void slotExit();        //sair app pelo menu principal
	virtual void isomerico();
	virtual void ortogonal();
	virtual void clickedTextures();
	virtual void clickedAxis();
	virtual void updatePositionSpinBox(float,float,float);
	virtual void tabChanged(int);
	virtual void positionCamera();
};

#endif // MAINWINDOW_H
