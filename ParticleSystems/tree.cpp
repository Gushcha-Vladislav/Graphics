#include "tree.h"

tree::tree()
{

}
void tree::setParamShader(QOpenGLShaderProgram* program,GLuint posAttr,GLuint colAttr,GLuint Matrix,QMatrix4x4 p){
    mProgram=program;
    mColAttr=colAttr;
    mPosAttr=posAttr;
    mMatrix=Matrix;
    matrix=p;
}
void tree::draw(){
        GLfloat vect[12];
        mProgram->setUniformValue(mColAttr,0.3f,0.13f,0.0f,1.0f);
           for(double fi=0;fi<2*M_PI;fi+=0.01){
               vect[0]=0;vect[1]=r*sin(fi);vect[2]=r*cos(fi)-96;
               vect[3]=20;vect[4]=r*sin(fi);vect[5]=r*cos(fi)-96;
               vect[6]=20;vect[7]=r*sin(fi+0.01);vect[8]=r*cos(fi+0.01)-96;
               vect[9]=0;vect[10]=r*sin(fi+0.01);vect[11]=r*cos(fi+0.01)-96;
               glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
               glEnableVertexAttribArray( mPosAttr );
               glDrawArrays( GL_QUADS, 0, 4);
               glDisableVertexAttribArray(  mPosAttr );
               vect[0]=0;vect[1]=r*sin(fi);vect[2]=r*cos(fi)-96;
               vect[3]=-20;vect[4]=r*sin(fi);vect[5]=r*cos(fi)-96;
               vect[6]=-20;vect[7]=r*sin(fi+0.01);vect[8]=r*cos(fi+0.01)-96;
               vect[9]=0;vect[10]=r*sin(fi+0.01);vect[11]=r*cos(fi+0.01)-96;
               glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
               glEnableVertexAttribArray( mPosAttr );
               glDrawArrays( GL_QUADS, 0, 4);
               glDisableVertexAttribArray(  mPosAttr );
               vect[0]=r*sin(fi);vect[1]=0;vect[2]=r*cos(fi)-96;
               vect[3]=r*sin(fi);vect[4]=20;vect[5]=r*cos(fi)-96;
               vect[6]=r*sin(fi+0.01);vect[7]=20;vect[8]=r*cos(fi+0.01)-96;
               vect[9]=r*sin(fi+0.01);vect[10]=0;vect[11]=r*cos(fi+0.01)-96;
               glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
               glEnableVertexAttribArray( mPosAttr );
               glDrawArrays( GL_QUADS, 0, 4);
               glDisableVertexAttribArray(  mPosAttr );
               vect[0]=r*sin(fi);vect[1]=0;vect[2]=r*cos(fi)-96;
               vect[3]=r*sin(fi);vect[4]=-20;vect[5]=r*cos(fi)-96;
               vect[6]=r*sin(fi+0.01);vect[7]=-20;vect[8]=r*cos(fi+0.01)-96;
               vect[9]=r*sin(fi+0.01);vect[10]=0;vect[11]=r*cos(fi+0.01)-96;
               glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
               glEnableVertexAttribArray( mPosAttr );
               glDrawArrays( GL_QUADS, 0, 4);
               glDisableVertexAttribArray(  mPosAttr );
        }
}
