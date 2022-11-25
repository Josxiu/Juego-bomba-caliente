#ifndef JEFE_H
#define JEFE_H

#include "enemigo.h"
#include <bombajefe.h>
#include <QTimer>

// El jefe final tiene 3 vidas
// Alrededor de el hay 3 bombas que se mueven en circulos
// El jefe final hereda los metodos de la clase enemigo
class Jefe : public Enemigo
{
    Q_OBJECT
private:
    bool direccionY = true; // Variable para saber si el jefe se mueve hacia arriba o hacia abajo
    QTimer *timer;
    QTimer *rotacion; // Este timer se encarga de rotar las bombas
    // Este vector almacena las bombas que rodean al jefe
    QList <Bomba*> bombas;
public:
    explicit Jefe(QObject *parent = nullptr);
        // Con estos 2 metodos se dibuja el personaje
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    // Este metodo se encarga de hacer que el enemigo se mueva y lance bombas
    void moverJefe();
    void crearBombas();

    // El jefe tira una bomba especial que sigue al jugador
    void tirarBombaJefe();

public slots:
    // Se sobreescribe el metodo accionEnemigo para que el jefe lance bombas
    void accionEnemigo();
    // Con este metodo se hacen rotar las bombas que rodean al jefe
    void rotarBombas();
};

#endif // JEFE_H
