#ifndef JUEGO_H
#define JUEGO_H
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer> // Libreria para reproducir sonidos
#include <QAudioOutput> // Libreria para guardar recibir los sonidos
// Personajes del juego
#include <jugador.h>
#include <enemigo.h>
#include <bomba.h>
#include <bombajefe.h>
#include <puntaje.h>
#include <vidajugador.h>
#include <jefe.h>
#include <QMessageBox> // Con esto mostramos la ventana de game over

// Esta es la clase principal del juego que se encarga de crear el escenario
class Juego : public QGraphicsView
{
    Q_OBJECT
public:
    Bomba *bomba; // objeto bomba
    Jugador *jugador; // Personaje que controla el jugador
    Jefe *jefe;
    QGraphicsScene * escenario; // escenario del juego
    QTimer * tiempo;
    Puntaje * puntaje;
    VidaJugador * vida;
    QMessageBox msgBox; // Objeto para mostrar un mensaje al usuario
    bool faseFinal = 0;

public:
    Juego(QWidget * parent=0);
    void keyPressEvent(QKeyEvent *event); // Metodo para detectar las teclas presionadas
    void gameOver(); // Metodo para mostrar el mensaje de game over
    void crearJefe(); // Metodo para crear el jefe final
    ~Juego();

public slots:
    void generarEnemigo();
};
#endif // JUEGO_H
