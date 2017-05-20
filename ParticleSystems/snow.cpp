#include "snow.h"

snow::snow(QOpenGLShaderProgram *program){

    mProgram=program;
    init();

}
void snow::init(){

    color[0]=1.0f;
    color[1]=1.0f;
    color[2]=1.0f;
    x=rand()%(2*right)+left;
    y=rand()%(2*right)+left;
    z=top;
    speed=rand()%5;
    gravity=rand()%10+5;
    blur=(rand()%5+2.0f)/10.0f;
}
