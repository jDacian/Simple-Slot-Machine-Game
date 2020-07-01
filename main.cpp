#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0) );
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
