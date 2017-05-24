#ifndef EARTH_H
#define EARTH_H
#include "qmath.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

class earth:public QOpenGLFunctions
{
public:
    double z;
    QOpenGLShaderProgram * mProgram;
    GLuint mPosAttr;
    GLuint mColAttr;
    GLfloat blur[40000];
    void setParamShader(QOpenGLShaderProgram*,GLuint,GLuint);
    void draw();
    earth();
};

#endif // EARTH_H
