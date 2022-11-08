#include "bomba.h"

Bomba::Bomba( double x, double y, int r)
{
    posx = x;
    posy = y;
    this->r = r;
}

QRectF Bomba::boundingRect() const
{
    return QRectF(posx,posy, 2*r, 2*r);
}
// Dibujamos la bomba
void Bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

