#include "match_engine.h"

match_engine::match_engine(QObject *parent) :
    QObject(parent)
{
}


std::string match_engine::new_order(const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size)
{
    if(symbol.size()>0 && buysell.size()>0 && openclose.size()>0 && price>0 && size>0){;}
    return "";
}

void match_engine::rec_quote()
{

}

