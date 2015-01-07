#ifndef TACTIC_H
#define TACTIC_H
#include<QObject>
#include<string>
#include "parameter.h"

//############################################################
//simu模式
#ifdef SIMU
#include"snapshot.h"
#include"match_engine.h"
#define ctp_order_manager match_engine
#define CThostFtdcDepthMarketDataField snapshot

#else

#include"../libs/ctp/ThostFtdcMdApi.h"
#include"ctp_order_manager.h"
#endif
//############################################################

const int PRICESTEP=5;
const int LIMITSTEP=5;
const int ORDERSZ=1;
class ctp_order_manager;
class tactic: public QObject
{
    Q_OBJECT
public:
    void set_ctp_order_manager(ctp_order_manager * p);
    void init();

public slots:
    virtual void book(const CThostFtdcDepthMarketDataField *p);
    virtual void quote(const std::string & symbol, const std::string & ba, long level, double price, long quotesize);
    virtual void ack(const std::string & ordername,const std::string & type,const std::string & info);
    virtual void done(const std::string & ordername,const std::string & type,const std::string & info);
    virtual void rej(const std::string & ordername,const std::string & type,const std::string & info);
    virtual void fill(const std::string & ordername,const std::string symbol,double price, long size);
private:
    int ordersize;
    int ordersize_1;
    double lasttradeprice;
    double lasttradeprice_1;
    ctp_order_manager * om;
};

#endif // TACTIC_H
