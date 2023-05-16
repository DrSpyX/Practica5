#include "muro.h"

muro::muro(double _tamX, double _tamY)
{
    tamX = _tamX;
    tamY = _tamY;
}

muro::~muro()
{

}

QRectF muro::boundingRect() const
{
    return QRectF(-(tamX/2),-(tamY/2),tamX,tamY);
}

void muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(boundingRect());
}
