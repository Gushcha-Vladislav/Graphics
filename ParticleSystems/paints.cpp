#include "paints.h"

paints::paints(QWidget *parent):QGLWidget(parent)
{



    timer = new QTimer;
    connect( timer,SIGNAL( timeout() ),SLOT( start() ) );
    timer->start(100);


}
void paints::start(){
    this->updateGL();
    if(step<50)
        step++;
}

void paints::initializeGL()
{
      initializeOpenGLFunctions();
      glClearColor(0.0f, 0.0f, 0.2f,1.0f);
      m_program = new QOpenGLShaderProgram( this );
      m_program->addShaderFromSourceFile( QOpenGLShader::Vertex, ":/Shaders/vShader.glsl" );
      m_program->addShaderFromSourceFile( QOpenGLShader::Fragment, ":/Shaders/fShader.glsl" );
      if ( !m_program->link() ){
        qWarning( "Error: unable to link a shader program" );
        return;
      }
      m_matrix = m_program->uniformLocation( "matrix" );
      matrix.ortho(-100.0f,100.0f,-100.0f,100.0f,-100.0f,100.0f);
      matrix.rotate(pred[1],0,1,1);
      m_posAttr = m_program->attributeLocation( "posAttr" );
      m_colAttr = m_program->uniformLocation( "colAttr" );
      m_pointAttr=m_program->uniformLocation( "pointAttr" );
      initElementCard();
      glEnable(GL_PROGRAM_POINT_SIZE);
      glEnable(GL_POINT_SMOOTH);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void paints::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if ( !m_program->bind() )
        return;
//    glLoadIdentity();
//    gluLookAt(10,10,10,
//              0.0,0.0,0.0,
//              0.0,10,1);
    draw();
}


void paints::resizeGL(int width, int height)
{
    glViewport( 0, 0, width, height );
}
void paints::initElementCard(){
//    Tree=new tree [sumTree];
    Snow=new snow[sumSnow];
    Fire=new fire [sumFire];
    Smoke=new smoke [sumSmoke];
//    for(int i=0;i<sumTree;i++){
//        Tree[i].setParamShader(m_program,m_posAttr,m_colAttr);
//    }
    for(int i=0;i<sumSnow;i++){
        Snow[i].setParamShader(m_program,m_posAttr,m_colAttr, m_pointAttr);
    }
    for(int i=0;i<sumSmoke;i++){
        Smoke[i].setParamShader(m_program,m_posAttr,m_colAttr, m_pointAttr);
    }
    for(int i=0;i<sumFire;i++){
        Fire[i].setParamShader(m_program,m_posAttr,m_colAttr, m_pointAttr);
    }
}


void paints::draw(){

    m_program->setUniformValue( m_matrix, matrix );
    m_program->setUniformValue( m_pointAttr, 1.0f );

                                            {
                                                m_program->setUniformValue(m_colAttr,1.0f, 1.0f, 1.0f,1.0f);
                                                GLfloat vect[]={
                                                        -100.0f,0.0f,0.0f,
                                                         100.0f,0.0f,0.0f,
                                                         0.0f,-100.0f,0.0f,
                                                         0.0f,100.0f,0.0f,
                                                         0.0f,0.0f,-100.0f,
                                                         0.0f,0.0f,100.0f

                                                    };
                                                glVertexAttribPointer( m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vect );
                                                glEnableVertexAttribArray( m_posAttr );
                                                glDrawArrays( GL_LINES, 0, 6);
                                                glDisableVertexAttribArray(  m_posAttr );
                                            }
//    for(int i=0;i<sumTree;i++){
//        Tree[i].draw();
//    }
    for(int i=0;i<step*sumStepSnow;i++){
        Snow[i].draw();
    }
    for(int i=0;i<step*sumStepFire;i++){
       Fire[i].draw();
     }
    for(int i=0;i<step*sumStepSmoke;i++){
       Smoke[i].draw();
     }
    m_program->release();
}

void paints::setX(int j){
    matrix.rotate(j-pred[0],1.0f,0.0f,0.0f);
    pred[0]=j;
}

void paints::setY(int j){
    matrix.rotate(j-pred[1],0.0f,1.0f,0.0f);
    pred[1]=j;
}

void paints::setZ(int j){
    matrix.rotate(j-pred[2],0.0f,0.0f,1.0f);
    pred[2]=j;
}
