#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <sys/time.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
struct timeval tempo_inicial, tempo_final;

private:
    bool start = false;
    float r,g,b;
    int corSetada;
    int acerto = 0, vidas = 9;
    float tempo = 0, mediaTempoReacao = 0, teste = 10;


public:
    MainWindow(QWidget *parent = nullptr);
     void keyPressEvent(QKeyEvent *event);
     void paintEvent(QPaintEvent *event);
     void pausa();
     void acertou();
     ~MainWindow();


public slots:
     void setColor();
     void startGame();
     void finshGame();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
