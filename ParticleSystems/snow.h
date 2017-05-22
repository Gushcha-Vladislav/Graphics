#ifndef SNOW_H
#define SNOW_H
#include "particle.h"

class snow: public particle
{
private:
    float color[3];
    int step=0;
    float R;
    float fi;
    float dx,dy;
    GLuint mPointAttr;
    int size;
public:
    snow();
    void setParamShader(QOpenGLShaderProgram*,GLuint,GLuint,GLuint);
    void init();
    void draw();
    void animation();
};

#endif // SNOW_H
