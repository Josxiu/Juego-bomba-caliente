#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <bomba.h>
#include <QMediaPlayer> // Libreria para reproducir sonidos
#include <QAudioOutput>
#include "personaje.h"

class Juego : public QGraphicsView
{
    Q_OBJECT
public:
    Bomba *bomba; // objeto bomba
    Personaje *jugador; // Personaje que controla el jugador
    QGraphicsScene * escenario; // escenario del juego
public:
    Juego(QWidget * parent=0);
    void keyPressEvent(QKeyEvent *event); // Metodo para detectar las teclas presionadas
    ~Juego();
};
#endif // JUEGO_H
