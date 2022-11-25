#include "bombajefe.h"
#include <juego.h>
extern Juego * juego; // Se crea una variable externa para poder acceder a los atributos de la clase juego
#include <QPointF>
#include <QLine>
BombaJefe::BombaJefe(QObject *parent)
    : Bomba{parent}
{
    // Se agrega la imagen de la bomba
    pxmap = new QPixmap(":/imagenes/bombajefe.png");
    // Se crea el timer para actualizar el estado de la bomba
    QTimer * timer = new QTimer();
    // se conecta al slot actualizarEstado
    connect(timer, SIGNAL(timeout()),this,SLOT(actualizarEstado()));
    // Se inicia el timer
    timer->start(100);

    // se configura el sonido de la explosion
    media = new QMediaPlayer();
    explocion = new QAudioOutput(media);
    media->setAudioOutput(explocion);
    media->setSource(QUrl::fromLocalFile("qrc:/sonidos/mi_explosion_03_hpx.mp3"));
    explocion->setVolume(100);

    // Se configura el radio de la bomba
    radio = 25;

}
QRectF BombaJefe::boundingRect() const
{
    return QRectF(0,0,2*radio,2*radio);
}

void BombaJefe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // painter->setBrush(color);
    // painter->drawEllipse(boundingRect());
    //painter->drawPixmap(boundingRect(),*pxmap, boundingRect()); // Dibujamos el sprite de la bomba
    painter->drawPixmap(boundingRect(),*pxmap,pxmap->rect());
}

void BombaJefe::moverBomba()
{
    // Se obtiene la posicion del jugador
    QPointF jugadorPos = juego->jugador->pos();
    // Se obtiene la posicion de la bomba
    QPointF bombaPos = this->pos();
    // Se calcula la distancia entre el jugador y la bomba
    QLineF linea(bombaPos, jugadorPos);
    // Se obtiene el angulo entre la bomba y el jugador
    int angulo = -1 * linea.angle();

    // Se obtiene la posicion en x y en y de la bomba
    int posX = this->x();
    int posY = this->y();

    // Se calcula la nueva posicion de la bomba
    posX += 5 * qCos(qDegreesToRadians(angulo));
    posY += 5 * qSin(qDegreesToRadians(angulo));

    // Se mueve la bomba
    this->setPos(posX, posY);
}

void BombaJefe::actualizarEstado()
{
    // Se actualiza el estado de la bomba
    moverBomba(); // Se mueve la bomba usando el metodo moverBomba de la clase BombaJefe
    cuentaRegresiva();
    colision();
}
