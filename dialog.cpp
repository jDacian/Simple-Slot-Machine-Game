#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include<string>
#include <stdio.h>
#include <stdlib.h>
//#include <QThread>
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    srand(time(0));
 int random;
        for(int i = 0; i<10; i++)
        {
           random = rand()%99999;
        }

    cout << random << endl;
//    QThread::sleep(500);
}
