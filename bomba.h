#ifndef BOMBA_H
#define BOMBA_H
#include <QGraphicsItem>
#include <QPainter>

class Bomba : public QGraphicsItem
{
    double posx;
    double posy;
    int r;

public:
    Bomba(double x, double y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOMBA_H
