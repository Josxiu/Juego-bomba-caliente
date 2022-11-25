#ifndef VIDAJUGADOR_H
#define VIDAJUGADOR_H
#include <QGraphicsTextItem>


class VidaJugador : public QGraphicsTextItem
{
public:
    VidaJugador(QGraphicsTextItem * parent = 0);
    void disminuir();
    int getVida();
private:
    int vida;
};

#endif // VIDAJUGADOR_H
