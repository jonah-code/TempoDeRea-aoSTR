#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool start = false;
    float r,g,b;
    int corSetada;
    int acerto = 0, vidas = 9;

public:
    MainWindow(QWidget *parent = nullptr);
     void keyPressEvent(QKeyEvent *event);
     void paintEvent(QPaintEvent *event);
     ~MainWindow();


public slots:
     void setColor();
     void startGame();
     void finshGame();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
