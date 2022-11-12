#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QTimer>

class Bomba : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int x, y;
    int radio;
    int tiempo = 5; //Tiempo de la cuenta regresiva
    bool detonada = false;
    bool explota = false;
    QTimer * timer = new QTimer();

public:
    Bomba();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void detonarBomba();
    void cuentaRegresiva();
    void parpadear();

    void setX(int x);
    void setY(int y);
    void moverBomba(int x, int y);
    void explotarBomba();

    int getX();
    int getY();
public slots:
    void actualizarEstado();
};

#endif // BOMBA_H
