#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    int ancho = 25, altura = 50;
    Personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void moverPersonaje(int x, int y);
};

#endif // PERSONAJE_H
