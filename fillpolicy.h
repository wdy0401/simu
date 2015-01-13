#ifndef FILLPOLICY_H
#define FILLPOLICY_H

#include <QObject>

#include"../gpp_qt/wtimer/wtimer.h"

class orderbook;
class orderlist;
class fillpolicy : public QObject
{
    Q_OBJECT
public:
    explicit fillpolicy(QObject *parent = 0);

    void set_book(orderbook * p){ob=p;}
    void set_orderlist(orderlist * p){ol=p;}
    void set_timer(wtimer * p){timer=p;}

signals:
    void ack(const std::string & ordername,const std::string & type,const std::string & info);
    void done(const std::string & ordername,const std::string & type,const std::string & info);
    void rej(const std::string & ordername,const std::string & type,const std::string & info);
    void fill(const std::string & ordername,const std::string symbol,double price, long size);
public slots:
    void rec_quote(const std::string & symbol,const std::string & bidask,long level,double price,long size);
    void rec_new_order(const std::string ordername,const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size);

private:
    orderbook * ob;
    orderlist * ol;
    wtimer * timer;
};

#endif // FILLPOLICY_H
