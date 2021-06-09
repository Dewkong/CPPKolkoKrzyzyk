#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //uruchomienie aplikacji
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
