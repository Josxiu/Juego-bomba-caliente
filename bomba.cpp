#include "bomba.h"
#include <juego.h>
//extern Juego * juego;
Bomba::Bomba(QObject * parent) : QObject(parent)
{
    radio = 25;
    velocidad = 5;

    //Se crea un puntero a un objeto qtimer y se conecta con el slot estadoBomba();
    //QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(actualizarEstado()));
    timer->start(100); // Cada segundo se actualizara el estado de la bomba

    // Configuramos el sonido de la explocion
    media = new QMediaPlayer();
    explocion = new QAudioOutput(media);
    media->setAudioOutput(explocion);
    media->setSource(QUrl::fromLocalFile("qrc:/sonidos/mi_explosion_03_hpx.mp3"));
    explocion->setVolume(100);
}

QRectF Bomba::boundingRect() const
{
    return QRectF(0,0,2*radio,2*radio);
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
    if(detonada){ // Si la bomba se detono entonces se inicia una cuenta regresiva
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

void Bomba::colision()
{
    // Si la bomba choca con un enemigo se destruyen ambos
    // En una lista se guardan todos los objetos con los que esta colisionando la bomba
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // Si la bomba choca con el jugador se le resta una vida
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Jugador))
        {
            // Se hace estallar la bomba
            explotarBomba();
            // Se le resta una vida al jugador
            Jugador *jugador = dynamic_cast<Jugador *>(colliding_items[i]);
            jugador->vidaJugador();
        }
    }
}

void Bomba::moverBomba()
{

    int mover = velocidad * dirX;
    setPos(x()+mover,y()); // Se mueve en la direccion que se lanza
    //colision();
}

// Recibe -1 o 1 para fijar la direccion en x
void Bomba::setDirX(int dir)
{
    dirX = dir; // Se invierte la direccion
}

void Bomba::explotarBomba()
{
    //Reproducimos el sonido de la bomba explotando
    media->play();

    // Se elimina la bomba del escenario y se libera la memoria
    scene()->removeItem(this);
    delete this;

}

// Se actualiza el estado de la bomba
void Bomba::actualizarEstado()
{
    moverBomba(); // Cada 100 milisegundos se actualiza la posicion
    cuentaRegresiva(); // Se llama a la funcion cuentaRegresiva
    colision(); // Se verifica si la bomba colisiona con algun objeto
}
