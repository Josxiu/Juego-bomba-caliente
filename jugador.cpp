#include "jugador.h"
#include <juego.h>
#include <QList>
#include <QPixmap>
extern Juego * juego; // Se accede a la variable global en la que se encuentra el juego


Jugador::Jugador(QObject *parent)
    : Personaje{parent}
{
    direccion = 1; // Inicialmente mira hacia la derecha
    vida = 3; // El jugador inicia con 3 puntos de vida
    pxmap = new QPixmap(":/imagenes/imagenes/jugador.png");
}

QRectF Jugador::boundingRect() const
{
    return QRectF(0,0,ancho,altura);
}

void Jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::blue);
//    painter->drawRect(boundingRect());
    painter->drawPixmap(boundingRect(),*pxmap,pxmap->rect());
}


// Se modifica la funcion tirar bomba para que se lance en la direccion que mira nuestro personaje
Bomba *Jugador::tirarBomba()
{
    Bomba * bomba;
    bomba = Personaje::tirarBomba(); // se invoca la funcion tirar bomba de la clase heredada
    bomba->setTipo(1); // El tipo indica si es arrojada por el enemigo o por el jugador
    return bomba;
}

void Jugador::vidaJugador()
{
    vida--;
    int puntaje = juego->puntaje->getPuntaje();
    juego->vida->disminuir();
    if(vida == 0 && puntaje  <10){
        // Se elimina el jugador del escenario
        scene()->removeItem(this);
        delete this;

        // Se muestra el mensaje de game over
        juego->gameOver();
    }
    else if(vida == 0 && puntaje >= 10){
        // Se muestra el mensaje de game over
        juego->gameOver();
    }
    // Se actualiza la vida del jugador en la interfaz

}
