#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    //ui->escena->setScene(scene);

    bomba = new Bomba(); //Se crea un objeto de tipo bomba
    scene->addItem(bomba); //Agrega la bomba a la escena

    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEstado())); //Cada segundo actualiza el estado del juego
    iniciarJuego();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEstado(){
    bomba->cuentaRegresiva();
//    moverBomba();
    //eliminarBomba();
}

void MainWindow::detonarBomba(){
    bomba->detonarBomba();
}

void MainWindow::eliminarBomba(){
    bool explocion = bomba->explocion();
    if(explocion){
        scene->removeItem(bomba);
        delete bomba;
    }
}

void MainWindow::iniciarJuego(){
    detonarBomba();
    timer->start(1000);
    view->show();
}

void MainWindow::moverBomba(){
    int x = bomba->getX() + 1;
    int y = bomba->getY() + 1;
    bomba->moverBomba(x,y);
}
