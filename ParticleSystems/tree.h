#ifndef TREE_H
#define TREE_H
#include "particle.h"

class tree: public particle
{
public:
    tree();
    int r=3;
    GLuint mMatrix;
    QMatrix4x4 matrix;
    void setParamShader(QOpenGLShaderProgram*,GLuint,GLuint,GLuint,QMatrix4x4);
    void setXY(double,double);
    void draw();
};

#endif // TREE_H
