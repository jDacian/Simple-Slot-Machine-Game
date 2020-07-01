#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <time.h>
#include <QThread>
#include <QMessageBox>

using namespace std;

int random1 = 0,
    random2 = 0,
    random3 = 0,
    random4 = 0,
    random5 = 0,
    random6 = 0,
    random7 = 0,
    random8 = 0,
    random9 = 0,
    random10 = 0,
    random11 = 0,
    random12 = 0,
    random13 = 0,
    random14 = 0,
    random15 = 0,
    freedr = 0,
    free_spin = 0,
    rsv_bet = 0;


int score = 0;

int credit = 0;
int bet = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand((unsigned)time(NULL));
    ui->setupUi(this);
    ui->score_label->setText(QString::number(score));
    ui->credit_label->setText(QString::number(credit));
    ui->bet_label->setText(QString::number(bet));
    ui->freespin_label->setText(QString::number(free_spin));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: Spin()
{
    QThread::msleep(500);

    srand((unsigned)time(NULL));        // Generate Random Numbers

    for(int i =0; i<rand(); i++)
    {
        freedr = rand()%9;
//        cout<<freedr<<endl;
    }
    cout<<freedr<<endl;

    srand((unsigned)time(NULL));
    for(int i = 0; i< rand(); i++)
    {
       random1 = rand()%3;
       random2 = rand()%3;
       random3 = rand()%3;
       random4 = rand()%3;
       random5 = rand()%3;
       random6 = rand()%3;
       random7 = rand()%3;
       random8 = rand()%3;
       random9 = rand()%3;
       random10 = rand()%3;
       random11 = rand()%3;
       random12 = rand()%3;
       random13 = rand()%3;
       random14 = rand()%3;
       random15 = rand()%3;
//       freedr = rand()%99;
//       cout<<freedr<<endl;
    }


    // Sets The Boxes' Outputs with the Generated Number
    ui->box1->setText(QString::number(random1));
    ui->box2->setText(QString::number(random2));
    ui->box3->setText(QString::number(random3));
    ui->box4->setText(QString::number(random4));
    ui->box5->setText(QString::number(random5));
    ui->box6->setText(QString::number(random6));
    ui->box7->setText(QString::number(random7));
    ui->box8->setText(QString::number(random8));
    ui->box9->setText(QString::number(random9));
    ui->box10->setText(QString::number(random10));
    ui->box11->setText(QString::number(random11));
    ui->box12->setText(QString::number(random12));
    ui->box13->setText(QString::number(random13));
    ui->box14->setText(QString::number(random14));
    ui->box15->setText(QString::number(random15));

    // Payline 1
    if(random6 == random7 && random7== random8 && random8 == random9 && random9== random10)
    {
        score = score + (bet*15);
        QMessageBox::information(this,"Payline 1","Congratulations! You Won!");
    }

    // Payline 2
    if(random11 == random12 && random12 == random13 && random13 == random14 && random14 == random15)
    {
        score = score + (bet*15);
        QMessageBox::information(this,"Payline 2","Congratulations! You Won!");
    }

    // Payline 3
    if(random1 == random2 && random2 == random3 && random3 == random4 && random4 == random5)
    {
        score = score + (bet*15);
        QMessageBox::information(this,"Payline 3","Congratulations! You Won!");
    }

    // Payline 4
    if(random11 == random7 && random7 == random3 && random3 == random9 && random9 == random15)
    {
        score = score + (bet*15);
        QMessageBox::information(this,"Payline 4","Congratulations! You Won!");
    }

    //Payline 5
    if(random1 == random7 && random7 == random13 && random13 == random9 && random9 == random5)
    {
        score = score + (bet*15);
        QMessageBox::information(this,"Payline 5","Congratulations! You Won!");
    }

    rsv_bet = bet;
    bet = 0;
    cout<<rsv_bet<<endl;


}


void MainWindow::on_pushButton_clicked()
{
    if(free_spin > 0)
    {
        QMessageBox::warning(this,"Information","You Used Your Free Spin");
        free_spin = free_spin - 1;
        bet = rsv_bet;
        ui->bet_label->setText(QString::number(bet));
        Spin();
    }

    else if(bet == 0)
    {
        QMessageBox::warning(this,"Information","You didn't Place Your Bet, Please Place a Bet");
    }

    else if(bet > 0)
    {
      Spin();

    }

    if(freedr == 5)
    {
        QMessageBox::information(this,"Free Spin","Congratulations! You Earned a Free Spin!");
        free_spin = free_spin + 1;
    }

    ui->score_label->setText(QString::number(score));
    ui->credit_label->setText(QString::number(credit));
    ui->bet_label->setText(QString::number(bet));
    ui->freespin_label->setText(QString::number(free_spin));
}

// BET
void MainWindow::on_pushButton_3_clicked()
{
    if(free_spin > 0)
    {
        QMessageBox::warning(this,"Informaton","Use Your Free Spin First");
    }

    else if(credit <= 0 || credit < 50)
    {
        QMessageBox::warning(this,"Informaton","You Don't Have Enough Credits, Please Reload");
    }

    else if(credit >= 50)
    {
        credit = credit - 50;
        bet = bet + 50;
    }

//    cout << credit << endl << endl;

    ui->score_label->setText(QString::number(score));
    ui->credit_label->setText(QString::number(credit));
    ui->bet_label->setText(QString::number(bet));
    ui->freespin_label->setText(QString::number(free_spin));
}

// ADD CREDIT
void MainWindow::on_pushButton_2_clicked()
{
    credit = credit + 200;

//    cout << credit << endl << endl;

    ui->score_label->setText(QString::number(score));
    ui->credit_label->setText(QString::number(credit));
    ui->bet_label->setText(QString::number(bet));
    ui->freespin_label->setText(QString::number(free_spin));
}

// CLAIM WINNINGS
void MainWindow::on_pushButton_4_clicked()
{
    if(score == 0)
    {
        QMessageBox::warning(this,"Information","You have no Winnings to Claim");
    }

    else
    {
        credit = credit + score;
        score = 0;

        ui->score_label->setText(QString::number(score));
        ui->credit_label->setText(QString::number(credit));
        ui->bet_label->setText(QString::number(bet));
        ui->freespin_label->setText(QString::number(free_spin));
    }

}

// Help Button
void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::about(this,"Basic Controls","Numpad '0' - Add Credits \nNumpad '+' - Add Bets \nNumpad '/' - Claim all Winnings \n'Spacebar' - Spin");
}
