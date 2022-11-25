#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsTextItem>

class Puntaje : public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsTextItem * parent = 0);
    void incrementar();
    int getPuntaje();
private:
    int puntaje;
};


#endif // PUNTAJE_H
