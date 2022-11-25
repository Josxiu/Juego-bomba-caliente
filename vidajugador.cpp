#include "vidajugador.h"
#include <QFont>

VidaJugador::VidaJugador(QGraphicsTextItem * parent) : QGraphicsTextItem(parent)
{
    vida = 3;
    setPlainText(QString("Vida: ") + QString::number(vida));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}

void VidaJugador::disminuir()
{
    vida--;
    setPlainText(QString("Vida: ") + QString::number(vida));
}

int VidaJugador::getVida()
{
    return vida;
}