#include "match_engine.h"

match_engine::match_engine(QObject *parent) :
    QObject(parent)
{
}


std::string match_engine::new_order(const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size)
{
    return "";
}

void match_engine::rec_quote()
{

}

