#ifndef BOMBA_H
#define BOMBA_H
#include <QPainter>
#include <QGraphicsItem>

class Bomba : public QGraphicsItem
{
private:
    int x, y;
    int radio;
    int tiempo = 5; //Tiempo de la cuenta regresiva
    bool detonada = false;
    bool explota = false;
public:
    Bomba();
    Bomba(int x, int y, int radio);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool explocion();
    void detonarBomba();
    void cuentaRegresiva();
};

#endif // BOMBA_H
