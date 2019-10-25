#ifndef MYGLWIDGETS_H
#define MYGLWIDGETS_H
#include<QGLWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
class MyGLwidgets: public QGLWidget
{
public:
    MyGLwidgets(QWidget* parent):QGLWidget(parent){}
protected:
    void initializeGL();
    void paintGL();
};

#endif // MYGLWIDGETS_H
