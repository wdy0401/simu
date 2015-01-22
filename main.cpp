#include "mainwindow.h"
#include <QApplication>

#include"datafeed.h"
#include"fillpolicy.h"
#include"parameter.h"
#include"match_engine.h"
#include"snapshot.h"
#include"tactic.h"

#include"../gpp_qt/wtimer/wtimer.h"
#include"../gpp_qt/cmd_line/cmd_line.h"
#include"../gpp_qt/log_info/logs.h"

int main(int argc, char *argv[])
{
    cmd_line * cl=new cmd_line(argc,argv);

    datafeed * df =new datafeed;
    fillpolicy * fp =new fillpolicy;
    logs * ls = new logs;
    match_engine * me =new match_engine;
    snapshot * ss=new snapshot;
    tactic * tc =new tactic;
    wtimer * timer=new wtimer;


    //首先把指针放入相应的其他类里面 以便内部调用
    //然后设置好类型之间的信号槽关系

    df->set_timer(timer);

    fp->set_timer(timer);

    ls->set_timer(timer);
    ls->set_dir(cl->get_para("dir"));

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
    QObject::connect(me,&match_engine::send_new_order,fp,&fillpolicy::rec_new_order);

    if(cl->has_para("gui"))
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.set_qa(&a);
        w.show();
        QObject::connect(df,&datafeed::send_quote,&w,&MainWindow::show_quote);
        QObject::connect(me,&match_engine::send_new_order,&w,&MainWindow::show_order);
        QObject::connect(fp,&fillpolicy::fill,&w,&MainWindow::show_fill);

        fp->init();
        //ls->init();//尚待connect
        tc->init();

        df->setfile(cl->get_para("quote_file"));
        df->run();
        return a.exec();
    }
    else
    {
        fp->init();
        //ls->init();//尚待connect
        tc->init();

        df->setfile(cl->get_para("quote_file"));
        df->run();
        return 0;
    }
}

//mkdir
//set recordfile
//signal slot on log_info
//写个logs？ QOBJECT 包含几个log_info 接收所有log 转换成string 然后放到各个log_info中
