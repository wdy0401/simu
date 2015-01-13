#include "fillpolicy.h"

using namespace std;

fillpolicy::fillpolicy(QObject *parent) :
    QObject(parent)
{
}
void fillpolicy::init()
{
    ol=new list<order>;
}
void fillpolicy::rec_quote(const std::string & symbol,const std::string & bidask,long level,double price,long size)
{

}

void fillpolicy::rec_new_order(const std::string ordername,const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size)
{
}
