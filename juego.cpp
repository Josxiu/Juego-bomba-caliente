#include "juego.h"

Juego::Juego()
{
    bomba = new Bomba(); // creamos una bomba
    escenario = new QGraphicsScene(); // creamos un escenario
    escenario->addItem(bomba); // agregamos la bomba al escenario

    //Se crea y se agrega el jugador a la escena
    jugador = new Personaje();
    escenario->addItem(jugador);

    this->setScene(escenario); // Visualisamos la escena
    this->setFixedSize(800,600); // Tamaño de la ventana grafica
    escenario->setSceneRect(0,0,800,600); //Tamaño de la escena
}

void Juego::keyPressEvent(QKeyEvent *event)
{
    int x, y;
    x = 0; y = 0;

    qDebug() << "Presionaste una tecla";
    // Se ajusta el movimiento del jugador para que no se salga del escenario visible
    if (event->key() == Qt::Key_A){
        x-=10;
        if(jugador->x() >0)
            jugador->moverPersonaje(x,y);
    }
    else if (event->key() == Qt::Key_D){
        x +=10;
        if(jugador->x() < this->width() - jugador->ancho)
            jugador->moverPersonaje(x,y);
    }
    else if (event->key() == Qt::Key_W){
        y -= 10;
        if(jugador->y() >0)
            jugador->moverPersonaje(x,y);
    }
    else if (event->key() == Qt::Key_S){
        y += 10;
        if(jugador->y() < this->height() - jugador->altura)
            jugador->moverPersonaje(x,y);
    }
    else if (event->key() == Qt::Key_Space){
        bomba->detonarBomba(); // se detona la bomba
        qDebug() << "Bomba activada";
    }

}

Juego::~Juego()
{
}

