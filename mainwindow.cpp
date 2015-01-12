#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"../gpp_qt/wfunction/wfunction.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_quote(const std::string & symbol,const std::string & bidask,long level,double price,long size)
{
    //QString tmpstr="";
    std::string tmpstr="";
    tmpstr=tmpstr+symbol+"\t"+bidask+"\t"+wfunction::itos(level)+"\t"+wfunction::ftos(price)+"\t"+wfunction::itos(size)+"\t";
            //"+tmpstr;
    this->ui->textBrowser->append(QString::fromStdString(tmpstr));
    qa->processEvents();
}
