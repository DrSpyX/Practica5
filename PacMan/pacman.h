#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit pacman(QObject *parent = nullptr);
    ~pacman();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
        const QStyleOptionGraphicsItem *option, QWidget *widget);
    void choque();
    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;
    int direccion;

    void obtDireccion(int direccion);

public slots:
    void animacion();
};

#endif // PACMAN_H
