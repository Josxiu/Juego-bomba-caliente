#include "enemigo.h"
#include <QList>
#include <juego.h>
extern Juego * juego; // Se crea una variable externa para poder acceder a los atributos de la clase juego


Enemigo::Enemigo(QObject *parent)
    : Personaje(parent)
{
    vida = 1; // El enemigo se inicia con 1 de vida

    connect(tiempo,SIGNAL(timeout()),this,SLOT(accionEnemigo()));
    tiempo->start(400); // cada 400 milisegundos se actualizara la posicion del enemigo

    // Este sera el sentido en el que el enemigo se movera por el mapa
    // el lado en el que aparezca el enemigo dependera de esto
    direccion = sentido.at(QRandomGenerator::global()->bounded(0,2)); // Con esto generamos un número aleatorio entre 0 y 1

    // El escenario tiene una altura de 600 px y 800 px de largo
    int altoEscenario = 600 - altura;
    int anchoEscenario = 800;
    int posicionX = 0;

    // Se establece el lado del escenario en el que aparecera el enemigo
    if(direccion == -1){
        posicionX = anchoEscenario - ancho;
    }
    int posicionY = QRandomGenerator::global()->bounded(0,altoEscenario); // Con esto generamos un número aleatorio entre 0 y 600
    setPos(posicionX,posicionY); // El enemigo aparece en una posición aleatoria en alguno de los bordes del escenario

}

QRectF Enemigo::boundingRect() const
{
    return QRectF(0,0,ancho,altura);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //    painter->setBrush(Qt::red);
    //    painter->drawRect(boundingRect());


    //painter->drawPixmap(boundingRect(),*pxmap,pxmap->rect());

    // Si mira a la derecha
    if(direccion == 1){
            pxmap = new QPixmap(":/imagenes/imagenes/enemigoDerecha.png");

        painter->drawPixmap(boundingRect(),*pxmap,pxmap->rect());
    }

    // Si mira a la izquierda
    if(direccion == -1){
            pxmap = new QPixmap(":/imagenes/imagenes/Enemigo.png");

        painter->drawPixmap(boundingRect(),*pxmap,pxmap->rect());
    }


}

Bomba *Enemigo::tirarBomba()
{
    Bomba * bomba;
    bomba = Personaje::tirarBomba(); // se invoca la funcion tirar bomba de la clase heredada
    bomba->velocidad = velocidadBomba; // velocidad con la que se mueve la bomba
    return bomba;
}

void Enemigo::moverEnemigo()
{
    int velocidad = 10 * direccion;
    moverPersonaje(velocidad,0); // Movemos al enemigo segun el lado que aparezca

    //tirarBomba(); // Lanza la bomba


}

void Enemigo::setTiempoAtaque(float tiempoAtaque)
{
    this->tiempoAtaque = tiempoAtaque * (1000/400);
}

void Enemigo::actualizarTiempoAtaque()
{
    tiempoAtaque--;
}
// Si el enemigo no tiene vida se elimina
void Enemigo::vidaEnemigo()
{
    vida--;
    if (vida == 0){
        scene()->removeItem(this);
        delete this;
    }
}
// Si una bomba choca con el enemigo se le resta 1 de vida
void Enemigo::colision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bomba)){
            // Se hace estallar la bomba
            Bomba * bomba = dynamic_cast<Bomba *>(colliding_items[i]); // Se accede al puntero de la bomba que colisiona
            bomba->explotarBomba(); // Se hace estallar la bomba
            vidaEnemigo(); // Se le resta 1 de vida al enemigo despues de que la bomba lo toque

            // si la bomba con la que se impacta es una bomba del jugador se le suma 1 de puntaje
            if (bomba->getTipo() == 1){
                // Si una bomba del jugador impacta con el enemigo se aumenta el puntaje
                juego->puntaje->incrementar();

            }

        }
    }
}

void Enemigo::accionEnemigo()
{
    moverEnemigo(); // Se mueve el enemigo
    //Si el enemigo se sale del escenario se elimina
   if(pos().x() < 0 || pos().x() > 800){
       scene()->removeItem(this);
       delete this;
       return; // Se pone return para que no hallan errores por el uso de la memoria despues de eliminarlo
   }

    // Cada vez que el tiempo llegue a 0 se lanza una bomba
    if(tiempoAtaque == 0){
        tirarBomba();
        tiempoAtaque = 3 * (1000/400);
    }
    actualizarTiempoAtaque();
    colision(); // Se verifica si el enemigo colisiona con una bomba

}
