#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <vector>
#include "comida.h"
#include "muro.h"
#include "pacman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void collidemuro();
    void collidecomida();

public slots:
    void animar();
    void aumentarPunt();
    void sistemaPunt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* gameScene;
    QGraphicsScene* winScene;
    QGraphicsSimpleTextItem* texto;
    QTimer *timer;
    pacman* PM;
    QList<comida*> listaComida;
    comida* small;
    QList<muro*> listaMuros;
    muro* wall1;
    muro* wall2;
    muro* wall3;
    muro* wall4;
    muro* wall5;
    muro* wall6;
    muro* wall7;
    muro* wall8;
    muro* wall9;
    muro* wall10;
    muro* wall11;
    muro* wall12;

    std::vector<int> xComida, yComida;

    int puntuacion;

    bool moverLx;
    bool moverRx;
    bool moverUy;
    bool moverDy;
    bool pared;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H
