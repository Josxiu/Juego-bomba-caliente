#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <bomba.h>

// Clase base personaje de la que heredan la clase enemigo y jugador
class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
protected:
    int vida; // vida del personaje

public:
    // Atributos publicos de la clase
    int direccion; // direccion en la que se mueve el personaje
    int ancho = 80, altura = 120;
    Personaje(QObject *parent = nullptr);

    // Metodos principales del personaje
    void moverPersonaje(int x, int y);
    void posicionBomba(Bomba *bomba); // esta funcion lanza la bomba en la direccion que se encuentre mirando el personaje
    virtual Bomba* tirarBomba(); // Se hace virtual para cambiar el comportamiento en otras clases
};

#endif // PERSONAJE_H
