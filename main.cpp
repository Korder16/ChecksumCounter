#include "mainwindow.h"
#include <QApplication>

#include "checksum_counter.h"
#include <QDebug>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    QString filename = "C:\\Users\\Islam\\Desktop\\Учеба\\2 сем\\ML\\Assignments-master\\notebooks\\A1_UI23_Tramov_2_2_4.ipynb";
    ChecksumCounter counter;
    qDebug() << counter(filename);

    return 0;
}
