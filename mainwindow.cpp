#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "qdebug.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <math.h>
#include <QKeyEvent>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    char tecla = char(event->key());
    std::cout<<tecla<<std::endl;
    if(tecla == 'W'){
        if(corSetada==1){
            acerto+=1;
            setColor();
        }
        else{
            vidas-=1;
        }
    }
    if(tecla == 'S'){
        if(corSetada==2){
            acerto+=1;
            setColor();
        }
        else{
            vidas-=1;
        }
    }
    if(tecla == 'A'){
        if(corSetada==3){
            acerto+=1;
            setColor();
        }
        else{
            vidas-=1;
        }
    }
    if(tecla == 'D'){
        if(corSetada==4){
            acerto+=1;
            setColor();
        }
        else{
            vidas-=1;
        }
    }

    cout<<endl;
    cout<<"Potuacao"<<acerto<<endl;
    cout<<"tenho"<<vidas<<"vidas"<<endl;
    if(vidas<0){
        finshGame();
    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{

    int x, y;
    x = (1+rand()%width());
    y = (1+rand()%height());

    QPainter painter(this);
    QBrush brush;

    brush.setColor(QColor(r,g,b));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    if(start){
        painter.drawEllipse(x,y,50,50);
    }


}

void MainWindow::setColor()
{
    int vetor[4]={1,2,3,4};
    corSetada = vetor[rand()%4];
    if (corSetada == 1){
        r=255;
        g=255;
        b=0;
    }
    if (corSetada == 2){
        r=255;
        g=0;
        b=0;
    }
    if (corSetada == 3){
        r=0;
        g=255;
        b=0;
    }
    if (corSetada == 4){
        r=0;
        g=0;
        b=255;
    }

    repaint();
}

void MainWindow::startGame()
{
    vidas = 9;
    acerto = 0;
    start=true;
    setColor();
}

void MainWindow::finshGame()
{
    start=false;
    repaint();
}



