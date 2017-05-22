#include "tree.h"

tree::tree()
{

}
void tree::setXY(double X,double Y){

    x=X;
    y=Y;
}
void tree::setParamShader(QOpenGLShaderProgram* program,GLuint posAttr,GLuint colAttr){
    mProgram=program;
    mColAttr=colAttr;
    mPosAttr=posAttr;
}
void tree::draw(){
    mProgram->setUniformValue(mColAttr, 1.0f, 1.0f,  1.0f,blur);

}
