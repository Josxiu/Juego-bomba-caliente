#ifndef BOMBAJEFE_H
#define BOMBAJEFE_H

#include "bomba.h"

class BombaJefe : public Bomba
{
    Q_OBJECT
public:
    explicit BombaJefe(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void moverBomba();

public slots:
    void actualizarEstado();
};
#endif // BOMBAJEFE_H
