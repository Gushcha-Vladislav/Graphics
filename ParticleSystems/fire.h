#ifndef FIRE_H
#define FIRE_H
#include "particle.h"

class fire: public particle
{
private:
    float color[3];
    float dz;
    float r=20.0f;
    float height;
    float senterX=0,senterY=0;
    GLuint mPointAttr;
public:
    fire();

    void setParamShader(QOpenGLShaderProgram*,GLuint,GLuint,GLuint);
    void init();
    void draw();
    void animation();
};

#endif // FIRE_H
