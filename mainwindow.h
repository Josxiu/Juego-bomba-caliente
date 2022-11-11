#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <bomba.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void detonarBomba();
    ~MainWindow();

private slots:
    void actualizarEstado();
    void eliminarBomba();
    void iniciarJuego();
    void moverBomba();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Bomba *bomba;
    QTimer *timer = new QTimer(); //objeto tipo qtimer

};
#endif // MAINWINDOW_H
