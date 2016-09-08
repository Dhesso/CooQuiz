#include <iostream>
#include <QApplication>
#include "loguin.h"

using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    loguin w;

    w.show();

    return a.exec();
}
