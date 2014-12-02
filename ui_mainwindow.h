/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <MeuPainelOpenGL.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionNew;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *isomerico;
    QRadioButton *ortogonal;
    QLabel *label_11;
    QFrame *line_2;
    QLabel *label_16;
    QFrame *line_3;
    QLabel *label_17;
    QCheckBox *cbAxis;
    QLabel *label_18;
    QDoubleSpinBox *spinBoxCameraX;
    QLabel *label_19;
    QDoubleSpinBox *spinBoxCameraY;
    QLabel *label_20;
    QDoubleSpinBox *spinBoxCameraZ;
    QPushButton *posicionarCamera;
    QRadioButton *topo;
    QLabel *label_22;
    QFrame *line_4;
    QWidget *tab_2;
    QPushButton *deletar;
    QDoubleSpinBox *spinBoxH;
    QDoubleSpinBox *spinBoxW;
    QDoubleSpinBox *spinBoxL;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *spinBoxBlue;
    QSpinBox *spinBoxGreen;
    QSpinBox *spinBoxRed;
    QDoubleSpinBox *spinBoxX;
    QDoubleSpinBox *spinBoxY;
    QDoubleSpinBox *spinBoxZ;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QComboBox *comboBox;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QFrame *line;
    QPushButton *posicionar;
    QPushButton *adicionar;
    QLabel *label_21;
    QSpinBox *spinBoxRotation;
    MeuPainelOpenGL *painelGL;
    QMenuBar *menubar;
    QMenu *menuOPen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 873);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(900, 10, 291, 911));
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        isomerico = new QRadioButton(tab);
        isomerico->setObjectName(QStringLiteral("isomerico"));
        isomerico->setGeometry(QRect(20, 60, 241, 17));
        isomerico->setChecked(true);
        ortogonal = new QRadioButton(tab);
        ortogonal->setObjectName(QStringLiteral("ortogonal"));
        ortogonal->setGeometry(QRect(20, 120, 221, 17));
        ortogonal->setChecked(false);
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(16, 30, 241, 21));
        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 40, 271, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 200, 241, 21));
        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 210, 271, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_17 = new QLabel(tab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 240, 241, 17));
        cbAxis = new QCheckBox(tab);
        cbAxis->setObjectName(QStringLiteral("cbAxis"));
        cbAxis->setGeometry(QRect(20, 480, 131, 31));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 260, 67, 17));
        spinBoxCameraX = new QDoubleSpinBox(tab);
        spinBoxCameraX->setObjectName(QStringLiteral("spinBoxCameraX"));
        spinBoxCameraX->setGeometry(QRect(200, 260, 69, 21));
        spinBoxCameraX->setMaximum(999.99);
        label_19 = new QLabel(tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 290, 67, 21));
        spinBoxCameraY = new QDoubleSpinBox(tab);
        spinBoxCameraY->setObjectName(QStringLiteral("spinBoxCameraY"));
        spinBoxCameraY->setGeometry(QRect(200, 290, 69, 21));
        spinBoxCameraY->setMaximum(999.99);
        label_20 = new QLabel(tab);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 320, 67, 21));
        spinBoxCameraZ = new QDoubleSpinBox(tab);
        spinBoxCameraZ->setObjectName(QStringLiteral("spinBoxCameraZ"));
        spinBoxCameraZ->setGeometry(QRect(200, 320, 69, 21));
        spinBoxCameraZ->setMaximum(999.99);
        posicionarCamera = new QPushButton(tab);
        posicionarCamera->setObjectName(QStringLiteral("posicionarCamera"));
        posicionarCamera->setGeometry(QRect(10, 360, 261, 27));
        topo = new QRadioButton(tab);
        topo->setObjectName(QStringLiteral("topo"));
        topo->setGeometry(QRect(20, 90, 117, 22));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 440, 67, 21));
        line_4 = new QFrame(tab);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 450, 271, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab, QString());
        isomerico->raise();
        ortogonal->raise();
        label_11->raise();
        line_2->raise();
        label_16->raise();
        line_3->raise();
        label_17->raise();
        cbAxis->raise();
        label_18->raise();
        spinBoxCameraX->raise();
        label_19->raise();
        spinBoxCameraY->raise();
        label_20->raise();
        posicionarCamera->raise();
        spinBoxCameraZ->raise();
        topo->raise();
        label_22->raise();
        line_4->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        deletar = new QPushButton(tab_2);
        deletar->setObjectName(QStringLiteral("deletar"));
        deletar->setGeometry(QRect(20, 590, 251, 31));
        spinBoxH = new QDoubleSpinBox(tab_2);
        spinBoxH->setObjectName(QStringLiteral("spinBoxH"));
        spinBoxH->setGeometry(QRect(210, 260, 62, 22));
        spinBoxH->setMaximum(999.99);
        spinBoxW = new QDoubleSpinBox(tab_2);
        spinBoxW->setObjectName(QStringLiteral("spinBoxW"));
        spinBoxW->setGeometry(QRect(210, 230, 62, 22));
        spinBoxW->setMaximum(999.99);
        spinBoxL = new QDoubleSpinBox(tab_2);
        spinBoxL->setObjectName(QStringLiteral("spinBoxL"));
        spinBoxL->setGeometry(QRect(210, 290, 62, 22));
        spinBoxL->setMaximum(999.99);
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 260, 46, 21));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 290, 61, 21));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 230, 101, 16));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 370, 46, 16));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 400, 46, 16));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 430, 46, 16));
        spinBoxBlue = new QSpinBox(tab_2);
        spinBoxBlue->setObjectName(QStringLiteral("spinBoxBlue"));
        spinBoxBlue->setGeometry(QRect(230, 430, 42, 22));
        spinBoxBlue->setMaximum(255);
        spinBoxGreen = new QSpinBox(tab_2);
        spinBoxGreen->setObjectName(QStringLiteral("spinBoxGreen"));
        spinBoxGreen->setGeometry(QRect(230, 400, 42, 22));
        spinBoxGreen->setMaximum(255);
        spinBoxRed = new QSpinBox(tab_2);
        spinBoxRed->setObjectName(QStringLiteral("spinBoxRed"));
        spinBoxRed->setGeometry(QRect(230, 370, 42, 22));
        spinBoxRed->setMaximum(255);
        spinBoxX = new QDoubleSpinBox(tab_2);
        spinBoxX->setObjectName(QStringLiteral("spinBoxX"));
        spinBoxX->setGeometry(QRect(210, 110, 62, 22));
        spinBoxX->setMaximum(999.99);
        spinBoxY = new QDoubleSpinBox(tab_2);
        spinBoxY->setObjectName(QStringLiteral("spinBoxY"));
        spinBoxY->setGeometry(QRect(210, 140, 62, 22));
        spinBoxY->setMaximum(999.99);
        spinBoxZ = new QDoubleSpinBox(tab_2);
        spinBoxZ->setObjectName(QStringLiteral("spinBoxZ"));
        spinBoxZ->setGeometry(QRect(210, 170, 62, 22));
        spinBoxZ->setMaximum(999.99);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 110, 16, 16));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 140, 16, 16));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 170, 16, 16));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 40, 141, 31));
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setContextMenuPolicy(Qt::NoContextMenu);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 90, 251, 17));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 200, 251, 20));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 340, 67, 17));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 40, 67, 31));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(16, 10, 251, 20));
        line = new QFrame(tab_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 20, 261, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        posicionar = new QPushButton(tab_2);
        posicionar->setObjectName(QStringLiteral("posicionar"));
        posicionar->setGeometry(QRect(20, 550, 251, 31));
        adicionar = new QPushButton(tab_2);
        adicionar->setObjectName(QStringLiteral("adicionar"));
        adicionar->setGeometry(QRect(20, 510, 251, 27));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 470, 211, 21));
        spinBoxRotation = new QSpinBox(tab_2);
        spinBoxRotation->setObjectName(QStringLiteral("spinBoxRotation"));
        spinBoxRotation->setGeometry(QRect(210, 470, 61, 21));
        spinBoxRotation->setMaximum(360);
        spinBoxRotation->setSingleStep(90);
        tabWidget->addTab(tab_2, QString());
        deletar->raise();
        spinBoxH->raise();
        spinBoxL->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        spinBoxBlue->raise();
        spinBoxGreen->raise();
        spinBoxRed->raise();
        spinBoxX->raise();
        spinBoxY->raise();
        spinBoxZ->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        comboBox->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_12->raise();
        line->raise();
        posicionar->raise();
        spinBoxW->raise();
        adicionar->raise();
        label_21->raise();
        spinBoxRotation->raise();
        painelGL = new MeuPainelOpenGL(centralwidget);
        painelGL->setObjectName(QStringLiteral("painelGL"));
        painelGL->setGeometry(QRect(10, 20, 881, 811));
        painelGL->setMinimumSize(QSize(800, 510));
        painelGL->setMaximumSize(QSize(2000, 1000));
        painelGL->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        menuOPen = new QMenu(menubar);
        menuOPen->setObjectName(QStringLiteral("menuOPen"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOPen->menuAction());
        menuOPen->addAction(actionNew);
        menuOPen->addAction(actionOpen);
        menuOPen->addAction(actionSave);
        menuOPen->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        isomerico->setText(QApplication::translate("MainWindow", "Isom\303\251rico", 0));
        ortogonal->setText(QApplication::translate("MainWindow", "Navega\303\247\303\243o", 0));
        label_11->setText(QApplication::translate("MainWindow", "Modo de Visualiza\303\247\303\243o", 0));
        label_16->setText(QApplication::translate("MainWindow", "C\303\242mera", 0));
        label_17->setText(QApplication::translate("MainWindow", "Posi\303\247\303\243o Inicial :", 0));
        cbAxis->setText(QApplication::translate("MainWindow", "Exibir Eixos", 0));
        label_18->setText(QApplication::translate("MainWindow", "X", 0));
        label_19->setText(QApplication::translate("MainWindow", "Y", 0));
        label_20->setText(QApplication::translate("MainWindow", "Z", 0));
#ifndef QT_NO_TOOLTIP
        posicionarCamera->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        posicionarCamera->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        posicionarCamera->setText(QApplication::translate("MainWindow", "Posicionar Camera", 0));
        topo->setText(QApplication::translate("MainWindow", "Topo", 0));
        label_22->setText(QApplication::translate("MainWindow", "Cena", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Visualizacao", 0));
        deletar->setText(QApplication::translate("MainWindow", "Deletar", 0));
        label->setText(QApplication::translate("MainWindow", "Altura", 0));
        label_2->setText(QApplication::translate("MainWindow", "Largura", 0));
        label_3->setText(QApplication::translate("MainWindow", "Comprimento", 0));
        label_4->setText(QApplication::translate("MainWindow", "Red", 0));
        label_5->setText(QApplication::translate("MainWindow", "Green", 0));
        label_6->setText(QApplication::translate("MainWindow", "Blue", 0));
        label_13->setText(QApplication::translate("MainWindow", "X", 0));
        label_14->setText(QApplication::translate("MainWindow", "Y", 0));
        label_15->setText(QApplication::translate("MainWindow", "Z", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Novo Elemento", 0)
         << QApplication::translate("MainWindow", "Mesa", 0)
         << QApplication::translate("MainWindow", "Cama", 0)
         << QApplication::translate("MainWindow", "Cadeira", 0)
         << QApplication::translate("MainWindow", "Gaveteiro", 0)
         << QApplication::translate("MainWindow", "Arm\303\241rio", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "Posi\303\247\303\243o :", 0));
        label_8->setText(QApplication::translate("MainWindow", "Dimens\303\243o :", 0));
        label_9->setText(QApplication::translate("MainWindow", "Cor :", 0));
        label_10->setText(QApplication::translate("MainWindow", "Tipo", 0));
        label_12->setText(QApplication::translate("MainWindow", "Adicionar Elemento", 0));
        posicionar->setText(QApplication::translate("MainWindow", "Posicionar", 0));
        adicionar->setText(QApplication::translate("MainWindow", "Adicionar", 0));
        label_21->setText(QApplication::translate("MainWindow", "Rota\303\247\303\243o :", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Elementos", 0));
        menuOPen->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
