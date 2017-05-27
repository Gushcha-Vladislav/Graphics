#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),ui->widget, SLOT(setZ(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
