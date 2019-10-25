#include "myglwidgets.h"
#include<QGLWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
void MyGLwidgets::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);

}
void MyGLwidgets::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.5, 0);
    glEnd();

    QPainter p(this);
    p.setPen(Qt::red);
    p.drawLine(rect().topLeft(), rect().bottomRight());
}
