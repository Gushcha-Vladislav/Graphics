#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->widget, SLOT(setX(int)));
    QObject::connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),ui->widget, SLOT(setY(int)));
    QObject::connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),ui->widget, SLOT(setZ(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
