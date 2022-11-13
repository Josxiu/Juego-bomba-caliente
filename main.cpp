#include "juego.h"

#include <QApplication>
Juego *juego; // Se crea una variable global para acceder desde las otras clases

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    juego = new Juego();
    juego->show();

    return a.exec();
}
