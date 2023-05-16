#include "pacman.h"

pacman::pacman(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0;
    columnas = 0;
    direccion = 1;

    pixmap = new QPixmap(":/imagenes/PacMan.png");

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&pacman::animacion);

}

pacman::~pacman()
{

}

void pacman::animacion()
{
    if(direccion == 1){
        filas = 0;
        columnas += 26;
        if(columnas >= 50 && filas == 0){
            columnas = 0;
            filas = 105;
        }
        else if(filas == 105){
            columnas = 0;
            filas = 0;
        }
    }
    if(direccion == 2){
        filas = 26;
        columnas += 26;
        if(columnas >= 50 && filas == 26){
            columnas = 0;
            filas = 105;
        }
        else if(filas == 105){
            columnas = 0;
            filas = 26;
        }
    }
    if(direccion == 3){
        filas = 52;
        columnas += 26;
        if(columnas >= 50 && filas == 52){
            columnas = 0;
            filas = 105;
        }
        else if(filas == 105){
            columnas = 0;
            filas = 52;
        }
    }
    if(direccion == 4){
        filas = 78;
        columnas += 26;
        if(columnas >= 50 && filas == 78){
            columnas = 0;
            filas = 105;
        }
        else if(filas == 105){
            columnas = 0;
            filas = 78;
        }
    }
    if(direccion == 5){
        filas = 105;
        columnas = 0;
    }

    this->update(-12.5,-12.5,25,25);
}

QRectF pacman::boundingRect() const
{
    return QRectF(-12.5,-12.5,25,25);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-12.5,-12.5,*pixmap,columnas,filas,25,25);
}

void pacman::obtDireccion(int _direccion)
{
    direccion = _direccion;
}
