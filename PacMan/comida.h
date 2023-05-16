#ifndef COMIDA_H
#define COMIDA_H

#include <QGraphicsItem>
#include <QPainter>

class comida : public QGraphicsItem
{
public:
    comida();
    ~comida();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
        const QStyleOptionGraphicsItem *option, QWidget *widget);
    void choque();
};

#endif // COMIDA_H
