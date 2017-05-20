#include "smoke.h"

smoke::smoke(QOpenGLShaderProgram *program){

    mProgram=program;
    init();
}

void smoke::init(){
    color[0]=0.36f;
    color[1]=0.36f;
    color[2]=0.36f;
    int dummyR=rand()%20; //придумать как передавать R
    int dummyT=rand()%360;
    x=dummyR*qCos(dummyT);
    y=dummyR*qSin(dummyT);
    z=down+10+r-qSqrt(x*x+y*y);
    speed=rand()%5;
    gravity=-(rand()%5+2);
    blur=0.4f;
    height=(r-qSqrt(x*x+y*y))*2;
}
