#include "fire.h"

fire::fire(QOpenGLShaderProgram *program){

    mProgram=program;
    init();
}

void fire::init(){
    color[0]=1.0f;
    color[1]=1.0f;
    color[2]=0.0f;
    int dummyR=rand()%20; //придумать как сюда передавать R
    int dummyT=rand()%360;
    x=dummyR*qCos(dummyT);
    y=dummyR*qSin(dummyT);
    z=down+10;
    speed=rand()%5;
    gravity=-(rand()%5+2);
    blur=0.9f;
    height=r-qSqrt(x*x+y*y);
}
