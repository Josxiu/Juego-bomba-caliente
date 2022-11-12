#include "juego.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego juego;
    juego.show();
    juego.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    juego.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    return a.exec();
}
