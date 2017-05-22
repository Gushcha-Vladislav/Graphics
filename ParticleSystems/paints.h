#ifndef PAINTS_H
#define PAINTS_H

#include <QGLWidget>
#include "snow.h"
#include "fire.h"
#include "QTimer"

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
    int sumSnow=500;
    int sumFire=300;
    int step=0;
    int sumStep=10;
    int sumStepFire=6;
    int pred[3]={0,190,0};
    QTimer *timer;


public:
    explicit paints(QWidget *parent=0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void draw();
    void initElementCard();


private slots:
    void setX (int);
    void setY(int);
    void setZ(int);
    void start();

};

#endif // PAINTS_H
