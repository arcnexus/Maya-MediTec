#include "inicio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(linuxCodec);
   // QTextCodec::setCodecForCStrings(linuxCodec);
    Inicio w;
    w.showMaximized();
    
    return a.exec();
}
