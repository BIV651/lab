#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&generation, SIGNAL(clicked()), SLOT(on_generation_clicked()));
    connect(&sort, SIGNAL(clicked()), SLOT(on_sort_clicked()));
    connect(&bubble, SIGNAL(clicked()), SLOT(on_bubble_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generation_clicked()
{
    ui->before->clear();
    srand(time(NULL));
    for(int i=0; i<vec.size(); i++)
        vec[i]=rand()%100;
    for(int i=0; i<vec.size(); i++)
    {
        str += QString::number(vec[i]);
        str += " ";
    }
    ui->before->append(str);
    str.clear();
}

void MainWindow::on_bubble_clicked()
{
    ui->tme->clear();
   unsigned int tme_st = clock();
    ui->after->clear();
    for (int i = 0; i <vec.size(); i++) {
        for (int j = 0; j < vec.size()-1; j++) {
            if (vec[j] > vec[j + 1]) {
                int tmp;
                tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
    unsigned int tme_end = clock();
    unsigned int our_time = (tme_end - tme_st)/1000;
    for(int i=0; i<vec.size(); i++)
    {
        str += QString::number(vec[i]);
        str += " ";
    }
    ui->after->append(str);
    timesec+=QString::number(our_time);
    ui->tme->append(timesec + "ms.");
    our_time=0;
    str.clear();
    timesec.clear();
}

void MainWindow::on_sort_clicked()
{
    unsigned int tme_st =  clock();
    ui->after->clear();
    ui->tme->clear();
    std::sort(vec.begin(), vec.end());
    unsigned int tme_end = clock();
    unsigned int our_time = tme_end - tme_st;
       for(int i=0; i<vec.size(); i++)
       {
           str += QString::number(vec[i]);
           str +=" ";
       }
       timesec+=QString::number(our_time);
       ui->after->append(str);
       ui->tme->append(timesec + "ms.");
       our_time=0;
        str.clear();
        timesec.clear();
}


