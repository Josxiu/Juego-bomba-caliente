#include "bomba.h"
#include <QGraphicsScene>
Bomba::Bomba()
{
    x = 0, y = 0, radio = 15;

    //Se crea un puntero a un objeto qtimer y se conecta con el slot estadoBomba();
    //QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(actualizarEstado()));
    timer->start(1000); // Cada segundo se actualizara el estado de la bomba
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

void Bomba::detonarBomba()
{
    detonada = true; // Activamos la cuenta regresiva
}

void Bomba::cuentaRegresiva()
{
    if(detonada){
        if(tiempo > 0){
            tiempo--;
            parpadear();
        }else{
            explotarBomba();
        }
    }
}

// Cambiar el color de la bomba
void Bomba::parpadear(){
}

void Bomba::setX(int x)
{
    this->x = x;
}

void Bomba::setY(int y)
{
    this->y = y;
}

void Bomba::moverBomba(int x, int y)
{
    this->x = x;
    this->y = y;
    setPos(x,y);
}

void Bomba::explotarBomba()
{
    // Se elimina la bomba del escenario y se libera la memoria
    scene()->removeItem(this);
    delete timer;
    delete this;

}

int Bomba::getX()
{
    return x;
}

int Bomba::getY()
{
    return y;
}

void Bomba::actualizarEstado()
{
    cuentaRegresiva(); // Se llama a la funcion cuentaRegresiva
}
