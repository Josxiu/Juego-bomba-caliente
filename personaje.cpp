#include "personaje.h"

Personaje::Personaje()
{

}

QRectF Personaje::boundingRect() const
{
    return QRectF(0,0,25,50);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}

void Personaje::moverPersonaje(int x, int y)
{
    // Se cambia la posicion del personaje
    setPos(this->x() + x, this->y() + y);
}

void Personaje::tirarBomba()
{
    Bomba *bomba = new Bomba();
    bomba->setPos(x(),y()); // Posicionamos la bomba donde se encuentre el jugador
    scene()->addItem(bomba);
    bomba->detonarBomba();
}
