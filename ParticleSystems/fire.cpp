#include "fire.h"

fire::fire(){

    init();
}

void fire::init(){

    color[0]=1.0f;
    color[1]=1.0f;
    color[2]=0.0f;
    double dummyR=rand()%20; //придумать как сюда передавать R
    double dummyT=rand()%360;
    x=dummyR*qCos(dummyT);
    y=dummyR*qSin(dummyT);
    z=down+20;
    dz=z;
    gravity=-(rand()%5+1);
    blur=0.9f;
    height=r-qSqrt(x*x+y*y)+10;
}
void fire::setParamShader(QOpenGLShaderProgram* program,GLuint posAttr,GLuint colAttr,GLuint pointAttr){
    mProgram=program;
    mColAttr=colAttr;
    mPosAttr=posAttr;
    mPointAttr=pointAttr;
}
void fire::animation(){
    dz-=gravity;
    if(dz>=(height+z)){
       dz=down+20;
   }
   color[1]=1-qAbs(float(z-dz)/float(height));
}

void fire::draw(){
    mProgram->setUniformValue( mPointAttr, 3.0f);

    mProgram->setUniformValue(mColAttr,color[0],color[1] , color[2],blur);
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
