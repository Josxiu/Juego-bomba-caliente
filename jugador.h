#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"

class Jugador : public Personaje
{
    Q_OBJECT

private:
    QPixmap * pxmap;

public:
    explicit Jugador(QObject *parent = nullptr);

    Bomba* tirarBomba();
    void vidaJugador();

    // Con estos 2 metodos se dibuja el personaje
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // JUGADOR_H
