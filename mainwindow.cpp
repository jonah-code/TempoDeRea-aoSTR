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
#include <sys/time.h>
#include <Windows.h>
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
    if (teste>0){
        char tecla = char(event->key());
        std::cout<<tecla<<std::endl;
        if(tecla == 'W'){
            if(corSetada==1){
                acerto+=1;
                ui->pontuacao->display(acerto);
                gettimeofday(&tempo_final, NULL);
                tempo =(float) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000)/1000;
                mediaTempoReacao += tempo;
                ui->Tempo->setText(QString::number(tempo)+"s");
                pausa();
            }
            else{
                vidas-=1;
                ui->vida->display(vidas);
                ui->Tempo->setText("errou");
            }
        }
        if(tecla == 'S'){
            if(corSetada==2){
                acerto+=1;
                ui->pontuacao->display(acerto);
                gettimeofday(&tempo_final, NULL);
                tempo = (float) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000)/1000;
                mediaTempoReacao += tempo;
                ui->Tempo->setText(QString::number(tempo)+"s");
                pausa();
            }
            else{
                vidas-=1;
                ui->vida->display(vidas);
                ui->Tempo->setText("errou");
            }
        }
        if(tecla == 'A'){
            if(corSetada==3){
                acerto+=1;
                ui->pontuacao->display(acerto);
                gettimeofday(&tempo_final, NULL);
                tempo = (float) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000)/1000;
                mediaTempoReacao += tempo;
                ui->Tempo->setText(QString::number(tempo)+"s");
                pausa();
            }
            else{
                vidas-=1;
                ui->vida->display(vidas);
                ui->Tempo->setText("errou");
            }
        }
        if(tecla == 'D'){
            if(corSetada==4){
                acerto+=1;
                ui->pontuacao->display(acerto);
                gettimeofday(&tempo_final, NULL);
                tempo = (float) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000)/1000;
                mediaTempoReacao += tempo;
                ui->Tempo->setText(QString::number(tempo)+"s");
                pausa();
            }
            else{
                vidas-=1;
                ui->vida->display(vidas);
                ui->Tempo->setText("errou");
            }
        }
        teste--;
    }

    else if(vidas==0){
        finshGame();
    }
    else {
        finshGame();
        ui->media->setText(" Tempo médio foi de "+QString::number(mediaTempoReacao/acerto)+"s");

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
        painter.drawEllipse(x,y,100,100);
    }


}

void MainWindow::pausa()
{
    if(vidas==0){
        finshGame();
    }
    int intervalo[3] = {1000,2000,3000};
    int tempoSetado = intervalo[rand()%3];
    start= false;
    repaint();
    Sleep(tempoSetado);
    start = true;
    setColor();

}

void MainWindow::setColor()
{
    gettimeofday(&tempo_inicial, NULL);
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
    ui->vida->display(vidas);
    acerto = 0;
    start=true;
    setColor();
}

void MainWindow::finshGame()
{
    vidas=0;
    ui->vida->display(vidas);
    start=false;
    repaint();
}



