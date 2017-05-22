#include "snow.h"


snow::snow(){

    init();
}

void snow::init(){

    color[0]=1.0f;
    color[1]=1.0f;
    color[2]=1.0f;
    fi=rand()%360;
    z=top;
    speed=rand()%20;
    gravity=rand()%10+5;
    blur=(rand()%5+2.0f)/10.0f;
    R=rand()%190+10;
    dx=R*qCos(qDegreesToRadians(double(fi)))+x;
    dy=R*qSin(qDegreesToRadians(double(fi)))+y;
    size=rand()%7;
}

void snow::setParamShader(QOpenGLShaderProgram* program,GLuint posAttr,GLuint colAttr,GLuint pointAttr){
    mProgram=program;
    mColAttr=colAttr;
    mPosAttr=posAttr;
    mPointAttr=pointAttr;
}
void snow::animation(){
    step++;
    z-=gravity;
    if(z<=down){
        z=top;
    }
    dx=R*qCos(qDegreesToRadians(double(speed*step+fi)))+x;
    dy=R*qSin(qDegreesToRadians(double(speed*step+fi)))+y;
}

void snow::draw(){
    mProgram->setUniformValue( mPointAttr, float(size));
    mProgram->setUniformValue(mColAttr,color[0], color[1], color[2],blur);
    GLfloat vect[3];
    vect[0]=dx;
    vect[1]=dy;
    vect[2]=z;
    glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
    glEnableVertexAttribArray( mPosAttr );
    glDrawArrays( GL_POINTS, 0, 1);
    glDisableVertexAttribArray(  mPosAttr );
    animation();

}
