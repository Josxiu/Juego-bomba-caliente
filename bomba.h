#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer> // Libreria para reproducir sonidos
#include <QAudioOutput>

class Bomba : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int radio;
    int tiempo = 3*10; //Tiempo de la cuenta regresiva
    bool detonada = false;
    bool explota = false;
    QTimer * timer = new QTimer(this);
    QMediaPlayer * media;
    QAudioOutput * explocion;

public:
    Bomba();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void detonarBomba();
    void cuentaRegresiva();
    void parpadear();

    void moverBomba();
    void explotarBomba();

public slots:
    void actualizarEstado();
};

#endif // BOMBA_H
