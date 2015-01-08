#ifndef FILLPOLICY_H
#define FILLPOLICY_H

#include <QObject>
class orderbook;
class orderlist;
class fillpolicy : public QObject
{
    Q_OBJECT
public:
    explicit fillpolicy(QObject *parent = 0);

    void set_book(orderbook * p){ob=p;}
    void set_orderlist(orderlist * p){ol=p;}

signals:
    void ack(const std::string & ordername,const std::string & type,const std::string & info);
    void done(const std::string & ordername,const std::string & type,const std::string & info);
    void rej(const std::string & ordername,const std::string & type,const std::string & info);
    void fill(const std::string & ordername,const std::string symbol,double price, long size);
public slots:
    void rec_quote();

private:
    orderbook * ob;
    orderlist * ol;
};

#endif // FILLPOLICY_H
