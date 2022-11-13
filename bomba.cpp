#include "bomba.h"
#include <juego.h>
extern Juego * juego;
Bomba::Bomba()
{
    radio = 15;

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

void Bomba::moverBomba()
{

    setPos(x()+5,y());
}

void Bomba::explotarBomba()
{
    //Reproducimos el sonido de la bomba explotando
    media->play();

    // Se elimina la bomba del escenario y se libera la memoria
    scene()->removeItem(this);
    delete this;

}


void Bomba::actualizarEstado()
{
    moverBomba();
    cuentaRegresiva(); // Se llama a la funcion cuentaRegresiva
}
