#ifndef PARTICLE_H
#define PARTICLE_H
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <qmath.h>

class particle:public QOpenGLFunctions
{
public:
    //переменные
    float x=0.0f,y=0.0f,z=0.0f; // точки опорв для частицы
    float speed=0.0f; //скорость частицы
    float blur=1.0f; //прозрачность
    float gravity=0.0f; //сила гравитации
    float top=100.0f,down=-100.0f,right=100.0f,left=-100.0f; //постоянные константы поля
    QOpenGLShaderProgram *mProgram;
    GLuint mPosAttr;
    GLuint mColAttr;
    //функции
    particle();   //сделать класс абстрактным и виртуальным
};

#endif // PARTICLE_H
