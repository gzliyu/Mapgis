#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.drawLine(QPointF(0, 0), QPointF(100, 100));
//}

void MainWindow::on_openGLWidget_aboutToCompose()
{

}
