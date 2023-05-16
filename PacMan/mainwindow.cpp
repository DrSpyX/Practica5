#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameScene=new QGraphicsScene(0,0,500,320);
    gameScene->setBackgroundBrush(QBrush(Qt::black));
    ui->graphicsView->setScene(gameScene);

    puntuacion = 0;
    moverLx=false;
    moverRx=false;
    moverUy=false;
    moverDy=false;
    pared=false;

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(timer,SIGNAL(timeout()),this,SLOT(sistemaPunt()));
    connect(this,SIGNAL(collidecomida()),this,SLOT(aumentarPunt()));

    timer->start(16);

    PM = new pacman;
    gameScene->addItem(PM);
    PM->setPos(250,155);

    xComida = {25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,225,275,475,
               25,225,275,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,225,275,475,
               25,225,275,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475,
               25,225,275,475,
               25,225,275,475,
               25,45,65,85,105,125,145,165,185,205,225,275,295,315,335,355,375,395,415,435,455,475};
    yComida = {25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,
               45,45,45,45,
               65,65,65,65,
               85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
               105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,
               125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,125,
               145,145,145,145,
               165,165,165,165,
               185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,185,
               205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
               225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,225,
               245,245,245,245,
               265,265,265,265,
               285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285,285};

    for (int i = 0; i < 200; i++) {
        comida* small = new comida();
        listaComida.append(small);
        gameScene->addItem(small);
        small->setPos(xComida[i],yComida[i]);
    }

    wall1 = new muro(500, 10);
    wall2 = new muro(500, 10);
    wall3 = new muro(10, 310);
    wall4 = new muro(10, 310);
    wall5 = new muro(170, 35);
    wall6 = new muro(170, 35);
    wall7 = new muro(10, 130);
    wall8 = new muro(10, 132);
    wall9 = new muro(170, 35);
    wall10 = new muro(170, 35);
    wall11 = new muro(170, 35);
    wall12 = new muro(170, 35);
    gameScene->addItem(wall1);
    gameScene->addItem(wall2);
    gameScene->addItem(wall3);
    gameScene->addItem(wall4);
    gameScene->addItem(wall5);
    gameScene->addItem(wall6);
    gameScene->addItem(wall7);
    gameScene->addItem(wall8);
    gameScene->addItem(wall9);
    gameScene->addItem(wall10);
    gameScene->addItem(wall11);
    gameScene->addItem(wall12);
    listaMuros.append(wall1);
    listaMuros.append(wall2);
    listaMuros.append(wall3);
    listaMuros.append(wall4);
    listaMuros.append(wall5);
    listaMuros.append(wall6);
    listaMuros.append(wall7);
    listaMuros.append(wall8);
    listaMuros.append(wall9);
    listaMuros.append(wall10);
    listaMuros.append(wall11);
    listaMuros.append(wall12);
    wall1->setPos(250,5);
    wall2->setPos(250,305);
    wall3->setPos(5,155);
    wall4->setPos(495,155);
    wall5->setPos(375,55);
    wall6->setPos(125,55);
    wall7->setPos(250,65);
    wall8->setPos(250,244);
    wall9->setPos(375,155);
    wall10->setPos(125,155);
    wall11->setPos(375,255);
    wall12->setPos(125,255);
}

MainWindow::~MainWindow()
{
    delete gameScene;
    delete winScene;
    delete ui;
}

void MainWindow::animar()
{
    if(moverLx)
    {
        PM->setPos(PM->x()-2,PM->y());
        PM->obtDireccion(1);
    }
    if(moverRx)
    {
        PM->setPos(PM->x()+2,PM->y());
        PM->obtDireccion(2);
    }
    if(moverUy)
    {
        PM->setPos(PM->x(),PM->y()-2);
        PM->obtDireccion(3);
    }
    if(moverDy)
    {
        PM->setPos(PM->x(),PM->y()+2);
        PM->obtDireccion(4);
    }
    foreach (muro* wall, listaMuros)
    {
        if(PM->collidesWithItem(wall))
        {
            if(moverLx)
            {
                PM->setPos(PM->x()+2,PM->y());
            }
            if(moverRx)
            {
                PM->setPos(PM->x()-2,PM->y());
            }
            if(moverUy)
            {
                PM->setPos(PM->x(),PM->y()+2);
            }
            if(moverDy)
            {
                PM->setPos(PM->x(),PM->y()-2);
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverLx=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverRx=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverLx=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverRx=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverUy=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy=false;
    }
}

void MainWindow::sistemaPunt()
{
    foreach (comida* small, listaComida)
    {
        if(PM->collidesWithItem(small))
        {
            listaComida.removeOne(small);
            delete small;
            emit collidecomida();
        }
    }
    if(listaComida.size()==0){
        winScene=new QGraphicsScene(0,0,500,300);
        winScene->setBackgroundBrush(QBrush(Qt::black));
        ui->graphicsView->setScene(winScene);
        texto = new QGraphicsSimpleTextItem("Ganaste");
        texto->setBrush(QBrush(Qt::yellow));
        texto->setFont(QFont("Arial", 32));
        texto->setPos(180,130);
        winScene->addItem(texto);
    }
}

void MainWindow::aumentarPunt()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
}
