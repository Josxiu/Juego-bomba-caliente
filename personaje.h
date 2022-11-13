#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <bomba.h>

class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    int ancho = 25, altura = 50;
    Personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void moverPersonaje(int x, int y);
    void tirarBomba();
};

#endif // PERSONAJE_H
