#include "mainwindow.h"
#include <QApplication>

#include"datafeed.h"
#include"match_engine.h"
#include"tactic.h"
#include"snapshot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    datafeed * df =new datafeed;
    match_engine * me =new match_engine;
    tactic * tc =new tactic;
    snapshot * ss = new snapshot;

    //首先把指针放入相应的其他类里面 以便内部调用
    //然后设置好类型之间的信号槽关系

    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);
    QObject::connect(me,&match_engine::send_quote,tc,&tactic::quote);
    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);
    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);
    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);
    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);

    return a.exec();
}
