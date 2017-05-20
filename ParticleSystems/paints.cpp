#include "paints.h"

paints::paints(QWidget *parent):QGLWidget(parent)
{

}
void paints::initializeGL()
{
      initializeOpenGLFunctions();
//    m_program = new QOpenGLShaderProgram( this );
//    m_program->addShaderFromSourceFile( QOpenGLShader::Vertex, ":/Shaders/vShader.glsl" );
//    m_program->addShaderFromSourceFile( QOpenGLShader::Fragment, ":/Shaders/fShader.glsl" );
//    if ( !m_program->link() )
//    {
//        qWarning( "Error: unable to link a shader program" );
//        return;
//    }
//    m_posAttr = m_program->attributeLocation( "posAttr" );
//    m_colAttr = m_program->uniformLocation( "colAttr" );
//    m_matrixUniform = m_program->uniformLocation( "matrix" );

//    matrix.ortho(-10.0f,10.0f,-10.0f,10.0f,-10.0f,10.0f);


}

void paints::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
//    if ( !m_program->bind() )
//        return;
//    glLoadIdentity();
//    gluLookAt(10,10,10,
//              0.0,0.0,0.0,
//              0.0,10,1);
}


void paints::resizeGL(int width, int height)
{
    glViewport( 0, 0, width, height );
}
