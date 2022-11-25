#include "jefe.h"
#include <juego.h>
extern Juego * juego; // Se accede a la variable global en la que se encuentra el juego

Jefe::Jefe(QObject *parent)
    : Enemigo{parent}
{

    vida = 4;
    direccion = -1; // Inicialmente mira hacia la izquierda y arroja en esa direccion
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(accionEnemigo()));
    timer->start(100);

    rotacion = new QTimer(this);
    connect(rotacion,SIGNAL(timeout()),this,SLOT(rotarBombas()));
    rotacion->start(100);

    // se crean las bombas que rodean al jefe
    crearBombas();

    this->tiempoAtaque = 25;

}
// El jefe tiene las mismas dimensiones que el jugador
QRectF Jefe::boundingRect() const
{
    return QRectF(0, 0, ancho, altura);
}

void Jefe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap * pxmap = new QPixmap(":/imagenes/imagenes/jefe.png");
    painter->drawPixmap(boundingRect(),*pxmap,pxmap->rect());
}

// El jefe se mueve de arriba a abajo y de abaio a arriba
void Jefe::moverJefe()
{
    int velocidad = 10;
    // Aqui cambiamos el sentido de abajo a arriba y viceversa
    if(y() < 0){
        direccionY = 1;
    }
    else if(y() > 600 - altura){
        direccionY = 0;
    }

    // En esta parte se mueve el personaje
    if (direccionY == 1){
        moverPersonaje(0,velocidad); // Mueve al jefe hacia abajo
    }
    else if(direccionY == 0){
        moverPersonaje(0,-velocidad); // Mueve al jefe hacia arriba
    }
}


void Jefe::crearBombas()
{
    // Se crean las bombas que rodean al jefe
    
    // Bomba 1 (izquierda)

}

void Jefe::tirarBombaJefe(){

    // se crea la bomba del jefe que sigue al jugador
    BombaJefe * bomba = new BombaJefe();
    // se ubica al lado izquierdo del jefe
    bomba->setPos(x()-ancho,y()+altura/2);
    // se agrega a la escena
    scene()->addItem(bomba);
    // se detona la bomba
    bomba->detonarBomba();


}

void Jefe::accionEnemigo()
{
    moverJefe();
    //crearBombas();
    //Personaje::tirarBomba(); // Lanza la bomba en la direccion en la que esta mirando

    // El jefe tira una bomba especial que sigue al jugador cada 2 segundos y medio
    if(tiempoAtaque == 0){
        Bomba * bomba = tirarBomba();
        bomba->setTipo(2);
        tiempoAtaque = 25;
    }
    actualizarTiempoAtaque();
    colision();
}

void Jefe::rotarBombas()
{


    // Se mueven las bombas en circulo
    for(int i = 0; i < bombas.size(); i++){
        bombas.at(i)->setPos(pos().x() + 20 * cos(2 * 3.1416 * i / bombas.size()),pos().y() + 20 * sin(2 * 3.1416 * i / bombas.size()));
    }
}
