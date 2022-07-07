#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString qss;
    QFile qssFile(":/image/qss/default.qss");
    qssFile.open(QFile::ReadOnly);
    //setMouseTracking(true);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        w.setStyleSheet(qss);
        qssFile.close();
    }
    return a.exec();
}
