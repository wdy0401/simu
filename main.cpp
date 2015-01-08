#include "mainwindow.h"
#include <QApplication>

#include"datafeed.h"
#include"fillpolicy.h"
#include"orderbook.h"
#include"orderlist.h"
#include"parameter.h"
#include"match_engine.h"
#include"snapshot.h"
#include"tactic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    datafeed * df =new datafeed;
    fillpolicy * fp =new fillpolicy;
    orderbook * ob = new orderbook;
    orderlist * ol =new orderlist;
    match_engine * me =new match_engine;
    snapshot * ss=new snapshot;
    tactic * tc =new tactic;


    //首先把指针放入相应的其他类里面 以便内部调用
    //然后设置好类型之间的信号槽关系

    fp->set_book(ob);
    fp->set_orderlist(ol);

    me->set_book(ob);
    me->set_snapshot(ss);

    tc->set_match_engine(me);

    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);

    QObject::connect(fp,&fillpolicy::ack,tc,&tactic::ack);
    QObject::connect(fp,&fillpolicy::fill,tc,&tactic::fill);
    QObject::connect(fp,&fillpolicy::rej,tc,&tactic::rej);
    QObject::connect(fp,&fillpolicy::done,tc,&tactic::done);

    return a.exec();
}
