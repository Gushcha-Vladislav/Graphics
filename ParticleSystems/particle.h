#ifndef PARTICLE_H
#define PARTICLE_H
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <qmath.h>

class particle:public QOpenGLFunctions
{
public:
    //переменные
    int x=0,y=0,z=0; // координаты частицы
    int speed=0; //скорость частицы
    float blur=1.0f; //прозрачность
    int gravity=0.0f; //сила гравитации
    int top=100,down=-100,right=100,left=-100; //постоянные константы поля
    QOpenGLShaderProgram *mProgram;
    QMatrix4x4 matrix;
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrix;
    //функции
    particle();
};

#endif // PARTICLE_H
