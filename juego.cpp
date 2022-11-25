#include "juego.h"
#include <QString>
#include <QBrush>
#include <QImage>

Juego::Juego(QWidget * parent) : QGraphicsView(parent)
{
    escenario = new QGraphicsScene(); // creamos un escenario
//    bomba = new Bomba(); // creamos una bomba
//    escenario->addItem(bomba); // agregamos la bomba al escenario

    this->setScene(escenario); // Visualisamos la escena
    this->setFixedSize(800,600); // Tamaño de la ventana grafica
    escenario->setSceneRect(0,0,800,600); //Tamaño de la escena

    //Se crea y se agrega el jugador a la escena
    jugador = new Jugador();
    jugador->setPos(width()/2,height()/2); // Se posiciona el jugador en la mitad del escenario
    escenario->addItem(jugador);

    // Se agrega el puntaje y la vida al escenario
    puntaje = new Puntaje();
    puntaje->setPos(puntaje->x(),puntaje->y()+25);
    escenario->addItem(puntaje);

    vida = new VidaJugador();
    vida->setPos(vida->x(),vida->y());
    escenario->addItem(vida);

    // Se pinta el fondo del escenario
    setBackgroundBrush(QBrush(QImage( ":/imagenes/imagenes/arena.jpg")));
    // Se fija la pantalla para que no se haga mas grande si un objeto sale del escenario
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Musica de fondo / creamos los objetos para el reproductor y la salida de audio
    QMediaPlayer * reproductor = new QMediaPlayer;
    QAudioOutput * soundtrack = new QAudioOutput;
    reproductor->setAudioOutput(soundtrack);
    reproductor->setSource(QUrl::fromLocalFile("qrc:/sonidos/Vitality_-_Electro_Shock_Sport_Dance.mp3"));
    soundtrack->setVolume(50); // Ajustamos el volumen
    reproductor->play(); // Reproducimos el soundtrack
    reproductor->setLoops(QMediaPlayer::Infinite); // Hacemos que se repita cuando se acabe

    //crearJefe();
    // se inicializa el timer y se conecta con el slot generarEnemigo()
    tiempo = new QTimer(this);
    connect(tiempo,SIGNAL(timeout()),this,SLOT(generarEnemigo()));
    tiempo->start(3000); // cada 3 segundos se genera un nuevo enemigo
}
// Con este metodo se recibe la señal de la tecla presionada y se mueve al personaje principal
void Juego::keyPressEvent(QKeyEvent *event)
{
    int x, y;
    x = 0; y = 0;

    qDebug() << "Presionaste una tecla";
    // Se ajusta el movimiento del jugador para que no se salga del escenario visible
    // y se cambia la direccion hacia la que mira el personaje

    if (event->key() == Qt::Key_A){ // Se mueve a la izquierda
        x-=10;
        jugador->direccion = -1;

        // Si se sale del lado izquierdo del escenario se bloque el movimiento a la izquierda
        if(jugador->x() >0)
            jugador->moverPersonaje(x,y);

    }
    else if (event->key() == Qt::Key_D){ // Se mueve a la derecha
        x +=10;
        jugador->direccion = 1;

        // Si se sale del lado derecho del escenario se bloque el movimiento a la derecha
        if(jugador->x() < this->width() - jugador->ancho)
            jugador->moverPersonaje(x,y);
    }

    else if (event->key() == Qt::Key_W){ // Se mueve hacia arriba
        y -= 10;
        // Si se sale de la parte superior del escenario se bloque el movimiento hacia arriba
        if(jugador->y() >0)
            jugador->moverPersonaje(x,y);
    }

    else if (event->key() == Qt::Key_S){ // Se mueve hacia abajo
        y += 10;
        // Si se sale de la parte inferior del escenario se bloque el movimiento hacia abajo
        if(jugador->y() < this->height() - jugador->altura)
            jugador->moverPersonaje(x,y);
    }
    else if (event->key() == Qt::Key_Space){ // Lanza la bomba
        jugador->tirarBomba();
        qDebug() << "Bomba lanzada";
    }

}

void Juego::gameOver(){
    msgBox.setWindowTitle("Fin del juego");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setEscapeButton(QMessageBox::No);

    msgBox.setText("Has perdido, quieres volver a jugar?");
    int respuesta = msgBox.exec();
    if (respuesta == QMessageBox::Yes){
        qDebug() << "Si";
        // Se reinicia el juego y se inicializa todo otra vez
        escenario->clear();
        delete escenario;
        escenario = new QGraphicsScene();
        this->setScene(escenario);
        escenario->setSceneRect(0,0,800,600);
        setBackgroundBrush(QBrush(QImage( ":/imagenes/imagenes/arena.jpg")));
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        jugador = new Jugador();
        jugador->setPos(width()/2,height()/2);
        escenario->addItem(jugador);
        puntaje = new Puntaje();
        puntaje->setPos(puntaje->x(),puntaje->y()+25);
        escenario->addItem(puntaje);
        vida = new VidaJugador();
        vida->setPos(vida->x(),vida->y());
        escenario->addItem(vida);
        tiempo->start(3000);
        //crearJefe();
        
    }
    else if (respuesta == QMessageBox::No){
        qDebug() << "No";
        // Se cierra el juego
        QApplication::quit();
    }
}

void Juego::crearJefe(){
    jefe = new Jefe();
    // El jefe aparece en la mitad derecha del escenario
    jefe->setPos(this->width() - jefe->ancho - 15, this->height()/2);
    escenario->addItem(jefe);
}

Juego::~Juego()
{
}

void Juego::generarEnemigo()
{
    if (puntaje->getPuntaje() <10){
        Enemigo * enemigo = new Enemigo();
        escenario->addItem(enemigo);
    }
    else{
        if(faseFinal == 0){
            crearJefe();
            faseFinal = 1;
        }
    }


}

