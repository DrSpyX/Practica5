#ifndef MURO_H
#define MURO_H

#include <QGraphicsItem>
#include <QPainter>

class muro : public QGraphicsItem
{
public:
    muro(double _tamX, double _tamY);
    ~muro();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
        const QStyleOptionGraphicsItem *option, QWidget *widget);
    void choque();

private:
    double tamX, tamY;
};

#endif // MURO_H
