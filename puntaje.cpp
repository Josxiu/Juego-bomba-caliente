#include "puntaje.h"
#include <QFont>
Puntaje::Puntaje(QGraphicsTextItem * parent) : QGraphicsTextItem(parent)
{
    puntaje = 0;
    setPlainText(QString("Puntaje: ") + QString::number(puntaje));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}

void Puntaje::incrementar()
{
    puntaje++;
    setPlainText(QString("Puntaje: ") + QString::number(puntaje));
    if (puntaje == 10){

    }
}

int Puntaje::getPuntaje()
{
    return puntaje;
}
