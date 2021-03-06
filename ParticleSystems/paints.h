#ifndef PAINTS_H
#define PAINTS_H

#include <QGLWidget>
#include "snow.h"
#include "fire.h"
#include "smoke.h"
#include "tree.h"
#include "earth.h"
#include "QTimer"
#include "QVector3D"

class paints : public QGLWidget, public QOpenGLFunctions{
     Q_OBJECT
private:
    QOpenGLShaderProgram *m_program; 
    QMatrix4x4 matrix;
    GLuint m_matrix;
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_pointAttr;
    snow * Snow;
    fire * Fire;
    tree * Tree;
    smoke *Smoke;
    earth * Earth;
    int sumSnow=2000;
    int sumTree=1;
    int sumSmoke=3000;
    int sumFire=2000;
    int step=0;
    int sumStepSnow=40;
    int sumStepSmoke=60;
    int sumStepFire=40;
    int pred=0;
    QVector3D a;
    QVector3D b;
    QVector3D c;
    QTimer *timer;


public:
    explicit paints(QWidget *parent=0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void draw();
    void initElementCard();


private slots:
    void setZ(int);
    void start();

};

#endif // PAINTS_H
