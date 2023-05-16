#include "comida.h"

comida::comida()
{

}

comida::~comida()
{

}

QRectF comida::boundingRect() const
{
    return QRectF(-3,-3,6,6);
}

void comida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
}
