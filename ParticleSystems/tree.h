#ifndef TREE_H
#define TREE_H
#include "particle.h"

class tree: public particle
{
public:
    tree();
    void setParamShader(QOpenGLShaderProgram*,GLuint,GLuint);
    void setXY(double,double);
    void draw();
};

#endif // TREE_H
