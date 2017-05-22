#ifndef SMOKE_H
#define SMOKE_H
#include "particle.h"

class smoke: public particle
{
private:
    float color[3];
    float dz;
    float r=20.0f;
    float height;
    float senterX=0,senterY=0;
    GLuint mPointAttr;
public:
    smoke();
    void setParamShader(QOpenGLShaderProgram*,GLuint,GLuint,GLuint);
    void init();
    void draw();
    void animation();
};

#endif // SMOKE_H
