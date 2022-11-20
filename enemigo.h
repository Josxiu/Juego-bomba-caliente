#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <personaje.h>
#include <QVector>
#include <QRandomGenerator>
#include <QTimer>
// Enemigo hereda de la clase personaje
class Enemigo : public Personaje
{
    Q_OBJECT
private:
    QVector <int> sentido = {1,-1}; // Vector para elegir al azar el lado en el que aparece el enemigo
    QTimer * tiempo = new QTimer(this);

    // Como el estado se actualiza cada 400 ms se calcula por cuanto se tiene que multiplicar
    // la variable tiempo para poder que pasen 2 segundos
    float tiempoAtaque = 3 * (1000/400); // Tiempo que tarda en tirar bombas 2 segundos
public:
    // Con estos 2 metodos se dibuja el personaje
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int velocidadBomba = 8; // Velocidad de la bomba que lanza

    Enemigo(QObject *parent = nullptr);
    Bomba* tirarBomba();
    void moverEnemigo();
    void setTiempoAtaque(float tiempoAtaque);
    void actualizarTiempoAtaque();
    void vidaEnemigo();
    void colision();



public slots:
    // Este metodo se encarga de hacer que el enemigo se mueva y lance bombas
    void accionEnemigo();
};

#endif // ENEMIGO_H
