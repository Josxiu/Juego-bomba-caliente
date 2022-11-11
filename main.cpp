#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
//    QGraphicsScene * escena = new QGraphicsScene;
//    QGraphicsView *view = new QGraphicsView(escena);
//    view->show();
    return a.exec();
}
