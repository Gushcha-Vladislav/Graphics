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
      //matrix.rotate(pred[1],0,1,1);
      a.setX(0.0);
      a.setY(0.0f);
      a.setZ(0.0f);
      b.setX(0.0f);
      b.setY(0.0f);
      b.setZ(0.0f);
      c.setX(0.0f);
      c.setY(0.0f);
      c.setZ(0.0f);
      matrix.lookAt(a,b,c);
      //matrix.frustum(-0.01,0.01,-0.01,0.01,1,100);
      m_posAttr = m_program->attributeLocation( "posAttr" );
      m_colAttr = m_program->uniformLocation( "colAttr" );
      m_pointAttr=m_program->uniformLocation( "pointAttr" );
      initElementCard();
      glEnable(GL_PROGRAM_POINT_SIZE);
      glEnable(GL_BLEND);     
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable( GL_ALPHA_TEST );
      glEnable(GL_POINT_SMOOTH);
}

void paints::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if ( !m_program->bind() )
        return;
    draw();
}


void paints::resizeGL(int width, int height)
{
    glViewport( 0, 0, width, height );
}
void paints::initElementCard(){
    Tree=new tree [sumTree];
    Snow=new snow[sumSnow];
    Fire=new fire [sumFire];
    Smoke=new smoke [sumSmoke];
    Earth= new earth;
    for(int i=0;i<sumTree;i++){
        Tree[i].setParamShader(m_program,m_posAttr,m_colAttr,m_matrix,matrix);
    }
    Earth->setParamShader(m_program,m_posAttr,m_colAttr);
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

    Earth->draw();
    for(int i=0;i<sumTree;i++){
        Tree[i].draw();
    }
    m_program->setUniformValue( m_matrix, matrix );
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
