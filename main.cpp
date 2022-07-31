#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //设置中文编码
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("GBK");
#else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#endif

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
