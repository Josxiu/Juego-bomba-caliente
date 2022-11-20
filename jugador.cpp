#include "jugador.h"
#include <juego.h>
#include <QList>
extern Juego * juego;


Jugador::Jugador(QObject *parent)
    : Personaje{parent}
{
    direccion = 1; // Inicialmente mira hacia la derecha
    vida = 3; // El jugador inicia con 3 puntos de vida
}

QRectF Jugador::boundingRect() const
{
    return QRectF(0,0,ancho,altura);
}

void Jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}


// Se modifica la funcion tirar bomba para que se lance en la direccion que mira nuestro personaje
Bomba *Jugador::tirarBomba()
{
    Bomba * bomba;
    bomba = Personaje::tirarBomba(); // se invoca la funcion tirar bomba de la clase heredada
    return bomba;
}

void Jugador::vidaJugador()
{
    vida--;
    if(vida == 0){
        // Se elimina el jugador del escenario
        scene()->removeItem(this);
        delete this;

        // Se muestra el mensaje de game over

        juego->gameOver();
    }
    // Se actualiza la vida del jugador en la interfaz

}
