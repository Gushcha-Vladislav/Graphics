#ifndef SMOKE_H
#define SMOKE_H
#include "particle.h"

class smoke: public particle
{
private:
    float color[3];
    float r=20.0f;
    float height;
    int senterX=0,senterY=0;
public:
    smoke(QOpenGLShaderProgram *);
    void init();
};

#endif // SMOKE_H
