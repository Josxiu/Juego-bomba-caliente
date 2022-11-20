#include "personaje.h"

Personaje::Personaje(QObject *parent) : QObject(parent)
{
    vida = 3;
}

void Personaje::moverPersonaje(int x, int y)
{
    // Se cambia la posicion del personaje
    setPos(this->x() + x, this->y() + y);
}

// Ubica la bomba hacia al frente de donde este mirando el personaje
void Personaje::posicionBomba(Bomba *bomba)
{
    if(direccion == 1){
        bomba->setPos(this->x() + ancho, this->y() + altura/4);
    }else{
        bomba->setPos(this->x() - (bomba->radio*2), this->y() + altura/4);
    }

    // bomba->setPos(x(),y()); // Posicionamos la bomba donde se encuentre el personaje

}

Bomba *Personaje::tirarBomba()
{
    Bomba *bomba = new Bomba(this); // Se crea una nueva bomba
    posicionBomba(bomba); // Se ubica al frente del personaje
    bomba->setDirX(direccion); // Se tira la bomba en la direccion a la que se dirige el personaje
    scene()->addItem(bomba);
    bomba->detonarBomba(); // En el momento en que se lanza se detona la bomba
    return bomba;
}
