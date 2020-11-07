#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    wiringPiSetup();

    return a.exec();
}
