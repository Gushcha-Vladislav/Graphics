#include "smoke.h"

smoke::smoke(){

    init();
}

void smoke::init(){
    color[0]=0.22f;
    color[1]=0.22f;
    color[2]=0.22f;
    double dummyR=rand()%20; //придумать как передавать R
    double dummyT=rand()%360;
    x=dummyR*qCos(dummyT);
    y=dummyR*qSin(dummyT);
    z=down+20+r-qSqrt(x*x+y*y)+15;
    dz=z;
    gravity=-(rand()%5+1);
    blur=0.4f;
    height=(r-qSqrt(x*x+y*y)+10)*2+10;
}
void smoke::setParamShader(QOpenGLShaderProgram* program,GLuint posAttr,GLuint colAttr,GLuint pointAttr){
    mProgram=program;
    mColAttr=colAttr;
    mPosAttr=posAttr;
    mPointAttr=pointAttr;
}
void smoke::animation(){
    dz-=gravity;
    if(dz>=(height+z)){
       dz=z;
   }
}

void smoke::draw(){
    mProgram->setUniformValue( mPointAttr, 3.0f);
    float k=((z-dz)/height);
    mProgram->setUniformValue(mColAttr,color[0]*k+0.1,color[1]*k+0.1 , color[2]*k+0.1,0.7-blur*k);
    GLfloat vect[3];
    vect[0]=x;
    vect[1]=y;
    vect[2]=dz;
    glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
    glEnableVertexAttribArray( mPosAttr );
    glDrawArrays( GL_POINTS, 0, 1);
    glDisableVertexAttribArray(  mPosAttr );
    animation();

}
