#ifndef PAINTS_H
#define PAINTS_H

#include <QGLWidget>
#include "particle.h"

class paints : public QGLWidget, public QOpenGLFunctions{
     Q_OBJECT
private:
    QOpenGLShaderProgram *m_program;

public:
    explicit paints(QWidget *parent=0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private slots:

};

#endif // PAINTS_H
