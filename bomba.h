#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer> // Libreria para reproducir sonidos
#include <QAudioOutput> // Libreria para guardar recibir los sonidos
#include <QList>
#include <QPixmap>

class Bomba : public QObject, public QGraphicsItem
{
    Q_OBJECT
protected:
    //Tiempo de la cuenta regresiva, se multiplica por 10 ya que cada 100 milisegundos actualizamos el estado de la bomba
    int tiempo = 3*10; // Son 3 segundos para la explosion
    bool detonada = false;
    bool explota = false;
    int dirX = 1; // Por defecto la bomba se mueve hacia la derecha
    int tipo = 0; // El tipo nos indica si es una bomba del jugador o del enemigo o del jefe
    QTimer * timer = new QTimer(this);
    QMediaPlayer * media;
    QAudioOutput * explocion;
    // Color de la bomba
    QColor color;
    // Sprite de la bomba
    QPixmap * pxmap;
    bool seguirJugador = 0;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    int radio; // Atributo publico de la bomba
    int velocidad; // Velocidad de movimiento

    Bomba(QObject * parent = 0);

    void detonarBomba();
    void cuentaRegresiva(); // Este metodo cuenta hacia atras para estallar la bomba
    void parpadear(); // Este metodo hace que la bomba parpadee cuando esta a punto de estallar

    void colision(); // Metodo que revisa con que choca la bomba
    virtual void moverBomba();
    void seguir();
    void setDirX(int dir); // Si se mueve al lado contrario dir x se cambia a -1
    void explotarBomba();
    void setTipo(int tipo); // Establece el tipo de bomba
    int getTipo(); // Obtiene el tipo de bomba

public slots:
    virtual void actualizarEstado();
};

#endif // BOMBA_H
