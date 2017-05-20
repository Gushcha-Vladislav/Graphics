#ifndef FIRE_H
#define FIRE_H
#include "particle.h"

class fire: public particle
{
private:
    float color[3];
    float r=20.0f;
    float height;
    int senterX=0,senterY=0;
public:
    fire(QOpenGLShaderProgram*);
    void init();
};

#endif // FIRE_H
