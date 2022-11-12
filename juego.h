#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <bomba.h>
#include "personaje.h"

class Juego : public QGraphicsView
{
    Q_OBJECT
private:
    Bomba *bomba; // objeto bomba
    Personaje *jugador;
    QGraphicsScene * escenario; // escenario del juego

public:
    Juego();
    void keyPressEvent(QKeyEvent *event);
    ~Juego();
};
#endif // JUEGO_H
