/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *messageLabel;
    QTabWidget *tabWidget;
    QWidget *mazes;
    QPushButton *mazeOpenFile;
    QPushButton *generateMazeButton;
    QSpinBox *mazeWidth;
    QSpinBox *mazeHeight;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QPushButton *buildRouteButton;
    QSpinBox *fromX;
    QSpinBox *fromY;
    QSpinBox *toX;
    QSpinBox *toY;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *tab_2;
    QPushButton *caveOpenFile;
    QSpinBox *caveWidth;
    QSpinBox *caveHight;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *generateCaveButton;
    QSpinBox *probability;
    QLabel *label_11;
    QPushButton *getNextGenButton;
    QSpinBox *caveLifeLimit;
    QSpinBox *caveDeathLimit;
    QLabel *label_12;
    QLabel *label_13;
    QSpinBox *autoNextGenSpeed;
    QPushButton *autoGetNextGenButton;
    QLabel *label_14;
    QPushButton *stopAutoGenButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(850, 600);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 39, 500, 500));
        widget->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));
        messageLabel = new QLabel(centralwidget);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setGeometry(QRect(10, 10, 501, 17));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(520, 10, 321, 531));
        mazes = new QWidget();
        mazes->setObjectName("mazes");
        mazeOpenFile = new QPushButton(mazes);
        mazeOpenFile->setObjectName("mazeOpenFile");
        mazeOpenFile->setGeometry(QRect(30, 30, 261, 25));
        generateMazeButton = new QPushButton(mazes);
        generateMazeButton->setObjectName("generateMazeButton");
        generateMazeButton->setGeometry(QRect(30, 140, 261, 25));
        mazeWidth = new QSpinBox(mazes);
        mazeWidth->setObjectName("mazeWidth");
        mazeWidth->setGeometry(QRect(30, 110, 121, 26));
        mazeWidth->setMinimum(4);
        mazeWidth->setMaximum(50);
        mazeWidth->setValue(10);
        mazeHeight = new QSpinBox(mazes);
        mazeHeight->setObjectName("mazeHeight");
        mazeHeight->setGeometry(QRect(170, 110, 121, 26));
        mazeHeight->setMinimum(4);
        mazeHeight->setMaximum(50);
        mazeHeight->setValue(10);
        label = new QLabel(mazes);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 90, 131, 17));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(mazes);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 90, 131, 17));
        label_2->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(mazes);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(30, 250, 261, 131));
        buildRouteButton = new QPushButton(widget_2);
        buildRouteButton->setObjectName("buildRouteButton");
        buildRouteButton->setGeometry(QRect(0, 100, 261, 25));
        fromX = new QSpinBox(widget_2);
        fromX->setObjectName("fromX");
        fromX->setGeometry(QRect(10, 70, 44, 26));
        fromX->setMaximum(9);
        fromY = new QSpinBox(widget_2);
        fromY->setObjectName("fromY");
        fromY->setGeometry(QRect(60, 70, 44, 26));
        fromY->setMaximum(9);
        toX = new QSpinBox(widget_2);
        toX->setObjectName("toX");
        toX->setGeometry(QRect(160, 70, 44, 26));
        toX->setMaximum(9);
        toY = new QSpinBox(widget_2);
        toY->setObjectName("toY");
        toY->setGeometry(QRect(210, 70, 44, 26));
        toY->setMaximum(9);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 67, 17));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, 30, 101, 20));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 50, 31, 20));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(160, 50, 31, 20));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 50, 31, 20));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(210, 50, 31, 20));
        label_8->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(mazes, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        caveOpenFile = new QPushButton(tab_2);
        caveOpenFile->setObjectName("caveOpenFile");
        caveOpenFile->setGeometry(QRect(30, 30, 261, 25));
        caveWidth = new QSpinBox(tab_2);
        caveWidth->setObjectName("caveWidth");
        caveWidth->setGeometry(QRect(30, 110, 81, 26));
        caveWidth->setMinimum(4);
        caveWidth->setMaximum(50);
        caveWidth->setValue(10);
        caveHight = new QSpinBox(tab_2);
        caveHight->setObjectName("caveHight");
        caveHight->setGeometry(QRect(120, 110, 81, 26));
        caveHight->setMinimum(4);
        caveHight->setMaximum(50);
        caveHight->setValue(10);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 90, 61, 17));
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(tab_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(130, 90, 61, 17));
        label_10->setAlignment(Qt::AlignCenter);
        generateCaveButton = new QPushButton(tab_2);
        generateCaveButton->setObjectName("generateCaveButton");
        generateCaveButton->setGeometry(QRect(30, 140, 261, 25));
        probability = new QSpinBox(tab_2);
        probability->setObjectName("probability");
        probability->setGeometry(QRect(210, 110, 81, 26));
        probability->setMinimum(1);
        probability->setMaximum(100);
        probability->setValue(50);
        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(210, 90, 81, 20));
        label_11->setAlignment(Qt::AlignCenter);
        getNextGenButton = new QPushButton(tab_2);
        getNextGenButton->setObjectName("getNextGenButton");
        getNextGenButton->setGeometry(QRect(30, 270, 261, 25));
        caveLifeLimit = new QSpinBox(tab_2);
        caveLifeLimit->setObjectName("caveLifeLimit");
        caveLifeLimit->setGeometry(QRect(30, 240, 121, 26));
        caveLifeLimit->setMinimum(0);
        caveLifeLimit->setMaximum(7);
        caveLifeLimit->setValue(7);
        caveDeathLimit = new QSpinBox(tab_2);
        caveDeathLimit->setObjectName("caveDeathLimit");
        caveDeathLimit->setGeometry(QRect(170, 240, 121, 26));
        caveDeathLimit->setMinimum(0);
        caveDeathLimit->setMaximum(7);
        caveDeathLimit->setValue(7);
        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 220, 131, 17));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(160, 220, 131, 17));
        label_13->setAlignment(Qt::AlignCenter);
        autoNextGenSpeed = new QSpinBox(tab_2);
        autoNextGenSpeed->setObjectName("autoNextGenSpeed");
        autoNextGenSpeed->setGeometry(QRect(30, 350, 261, 26));
        autoNextGenSpeed->setMinimum(0);
        autoNextGenSpeed->setMaximum(2000);
        autoNextGenSpeed->setSingleStep(10);
        autoNextGenSpeed->setValue(1000);
        autoGetNextGenButton = new QPushButton(tab_2);
        autoGetNextGenButton->setObjectName("autoGetNextGenButton");
        autoGetNextGenButton->setGeometry(QRect(30, 380, 261, 25));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 330, 261, 20));
        label_14->setAlignment(Qt::AlignCenter);
        stopAutoGenButton = new QPushButton(tab_2);
        stopAutoGenButton->setObjectName("stopAutoGenButton");
        stopAutoGenButton->setGeometry(QRect(30, 410, 261, 25));
        tabWidget->addTab(tab_2, QString());
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 850, 22));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName("statusbar");
        View->setStatusBar(statusbar);

        retranslateUi(View);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        messageLabel->setText(QString());
        mazeOpenFile->setText(QCoreApplication::translate("View", "Open File", nullptr));
        generateMazeButton->setText(QCoreApplication::translate("View", "Generate Maze", nullptr));
        label->setText(QCoreApplication::translate("View", "width", nullptr));
        label_2->setText(QCoreApplication::translate("View", "height", nullptr));
        buildRouteButton->setText(QCoreApplication::translate("View", "Build Route", nullptr));
        label_3->setText(QCoreApplication::translate("View", "from", nullptr));
        label_4->setText(QCoreApplication::translate("View", "to", nullptr));
        label_5->setText(QCoreApplication::translate("View", "x", nullptr));
        label_6->setText(QCoreApplication::translate("View", "x", nullptr));
        label_7->setText(QCoreApplication::translate("View", "y", nullptr));
        label_8->setText(QCoreApplication::translate("View", "y", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mazes), QCoreApplication::translate("View", "Mazes", nullptr));
        caveOpenFile->setText(QCoreApplication::translate("View", "Open File", nullptr));
        label_9->setText(QCoreApplication::translate("View", "width", nullptr));
        label_10->setText(QCoreApplication::translate("View", "height", nullptr));
        generateCaveButton->setText(QCoreApplication::translate("View", "Generate Cave", nullptr));
        label_11->setText(QCoreApplication::translate("View", "probability", nullptr));
        getNextGenButton->setText(QCoreApplication::translate("View", "Get Next Generation", nullptr));
        label_12->setText(QCoreApplication::translate("View", "life limit", nullptr));
        label_13->setText(QCoreApplication::translate("View", "death limit", nullptr));
        autoGetNextGenButton->setText(QCoreApplication::translate("View", "Auto Update", nullptr));
        label_14->setText(QCoreApplication::translate("View", "time delay (miliseconds)", nullptr));
        stopAutoGenButton->setText(QCoreApplication::translate("View", "Stop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("View", "Caves", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
