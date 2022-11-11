#include "bomba.h"

Bomba::Bomba()
{
    x = 100, y = 100, radio = 25;
    setPos(x,y);
}

Bomba::Bomba(int x, int y, int radio)
{
    this->x=x;
    this->y=y;
    this->radio=radio;
    setPos(x,y);
}

QRectF Bomba::boundingRect() const
{
    return QRectF(x,y,2*radio,2*radio);
}

void Bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

bool Bomba::explocion()
{
    explota = true;
}

void Bomba::detonarBomba()
{
    detonada = true;
}

void Bomba::cuentaRegresiva()
{
    if(detonada){
        if(tiempo > 0){
            tiempo--;
            parpadear();
        }else{
            explocion();
        }
    }
}

// Cambiar el color de la bomba
void Bomba::parpadear(){
}

int Bomba::setX(int x)
{
    this->x = x;
}

int Bomba::setY(int y)
{
    this->y = y;
}

int Bomba::moverBomba(int x, int y)
{
    this->x = x;
    this->y = y;
    setPos(x,y);
}

int Bomba::getX()
{
    return x;
}

int Bomba::getY()
{
    return y;
}
