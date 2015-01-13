#include "match_engine.h"
#include"orderbook.h"
#include"fillpolicy.h"
#include"tactic.h"

using namespace std;
match_engine::match_engine(QObject *parent) :
    QObject(parent)
{
}


std::string match_engine::new_order(const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size)
{
    string ordername="";
    emit send_new_order(ordername,symbol,buysell,openclose,price,size);
    return "";
}

void match_engine::rec_quote(const std::string & symbol,const std::string & bidask,long level,double price,long size)
{
    emit send_quote_fp(symbol,bidask,level,price,size);
    emit send_quote_tactic(symbol,bidask,level,price,size);
}

