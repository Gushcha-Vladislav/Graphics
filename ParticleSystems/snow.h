#ifndef SNOW_H
#define SNOW_H
#include "particle.h"

class snow: public particle
{
private:
    float color[3];
public:
    snow(QOpenGLShaderProgram*);
    void init();
};

#endif // SNOW_H
