﻿#include "mainwindow.h"
#include <QApplication>

#include"datafeed.h"
#include"fillpolicy.h"
#include"orderbook.h"
#include"orderlist.h"
#include"parameter.h"
#include"match_engine.h"
#include"snapshot.h"
#include"tactic.h"

#include"../gpp_qt/wtimer/wtimer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.set_qa(&a);
    w.show();

    datafeed * df =new datafeed;
    fillpolicy * fp =new fillpolicy;
    orderbook * ob = new orderbook;
    orderlist * ol =new orderlist;
    match_engine * me =new match_engine;
    snapshot * ss=new snapshot;
    tactic * tc =new tactic;
    wtimer * timer=new wtimer;


    //首先把指针放入相应的其他类里面 以便内部调用
    //然后设置好类型之间的信号槽关系

    df->set_timer(timer);

    fp->set_book(ob);
    fp->set_orderlist(ol);
    fp->set_timer(timer);

    me->set_snapshot(ss);
    me->set_timer(timer);

    tc->set_match_engine(me);
    tc->set_timer(timer);

    QObject::connect(df,&datafeed::send_quote,me,&match_engine::rec_quote);
    QObject::connect(fp,&fillpolicy::ack,tc,&tactic::ack);
    QObject::connect(fp,&fillpolicy::fill,tc,&tactic::fill);
    QObject::connect(fp,&fillpolicy::rej,tc,&tactic::rej);
    QObject::connect(fp,&fillpolicy::done,tc,&tactic::done);
    QObject::connect(me,&match_engine::send_quote_fp,fp,&fillpolicy::rec_quote);
    QObject::connect(me,&match_engine::send_quote_tactic,tc,&tactic::quote);

    QObject::connect(df,&datafeed::send_quote,&w,&MainWindow::show_quote);

    QObject::connect(me,&match_engine::send_new_order,fp,&fillpolicy::rec_new_order);



    tc->init();

    df->setfile("d:/tmp/quote.csv");
    df->run();

    return a.exec();
}
