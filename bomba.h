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

class Bomba : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //Tiempo de la cuenta regresiva, se multiplica por 10 ya que cada 100 milisegundos actualizamos el estado de la bomba
    int tiempo = 3*10; // Son 3 segundos para la explosion
    bool detonada = false;
    bool explota = false;
    int dirX = 1; // Por defecto la bomba se mueve hacia la derecha
    QTimer * timer = new QTimer(this);
    QMediaPlayer * media;
    QAudioOutput * explocion;

public:
    int radio; // Atributo publico de la bomba
    int velocidad; // Velocidad de movimiento

    Bomba(QObject * parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void detonarBomba();
    void cuentaRegresiva(); // Este metodo cuenta hacia atras para estallar la bomba
    void parpadear(); // Este metodo hace que la bomba parpadee cuando esta a punto de estallar

    void colision(); // Metodo que revisa con que choca la bomba
    void moverBomba();
    void setDirX(int dir); // Si se mueve al lado contrario dir x se cambia a -1
    void explotarBomba();

public slots:
    void actualizarEstado();
};

#endif // BOMBA_H
