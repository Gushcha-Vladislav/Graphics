#include "earth.h"

earth::earth()
{
    for(int x=-100;x<100;x++){
        for(int y=-100;y<100;y++){
            blur[(x+100)*(y+100)+y+100]=float(rand()%10+5)/float(10);
        }
        }
    initializeOpenGLFunctions();
}
void earth::setParamShader(QOpenGLShaderProgram* program,GLuint posAttr,GLuint colAttr){
    mProgram=program;
    mColAttr=colAttr;
    mPosAttr=posAttr;
}

void earth::draw(){
    GLfloat vect[12];
    for(int x=-100;x<100;x++){
        for(int y=-100;y<100;y++){
            mProgram->setUniformValue(mColAttr,1.0f,1.0f,1.0f,blur[(x+100)*(y+100)+y+100]);
            z=20*qSin((x+M_PI/2)/30+M_PI/2)*qCos((y-M_PI/2)/30-M_PI)-80;
            vect[0]=x; vect[1]=y; vect[2]=z;
            x++;
            z=20*qSin((x+M_PI/2)/30+M_PI/2)*qCos((y-M_PI/2)/30-M_PI)-80;
            vect[3]=x; vect[4]=y; vect[5]=z;
            y++;
            z=20*qSin((x+M_PI/2)/30+M_PI/2)*qCos((y-M_PI/2)/30-M_PI)-80;
            vect[6]=x; vect[7]=y; vect[8]=z;
            x--;
            z=20*qSin((x+M_PI/2)/30+M_PI/2)*qCos((y-M_PI/2)/30-M_PI)-80;
            vect[9]=x; vect[10]=y; vect[11]=z;
            y--;
            glVertexAttribPointer( mPosAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
            glEnableVertexAttribArray( mPosAttr );
            glDrawArrays( GL_QUADS, 0, 4);
            glDisableVertexAttribArray(  mPosAttr );

        }
    }
}
