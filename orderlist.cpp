#include"orderlist.h"
#include<QMessageBox>

#include<iostream>

#include"../gpp_qt/wfunction/wfunction.h"

#include"../libs/ctp/ThostFtdcTraderApi.h"

extern MainWindow * mw;

using namespace std;

void orderlist::init()
{
	_ordercount=0;
}
void orderlist::show_warning(const string & warninfo)
{
    cerr << "Warning from ol" << endl;
    cerr << warninfo <<endl;
}
std::string orderlist::new_order(const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size)
{
    string ordername="";
    return ordername;
}
void orderlist::cancel_order(const std::string & ordername)
{

}
void orderlist::change_order(const std::string & ordername,const std::string & change_cancel,double changeto)
{

}
void orderlist::OnRtnOrder(CThostFtdcOrderField *p)
{
    cerr << endl << "--->>> OnRtnOrder" <<endl;
    string mapid=wfunction::itos(p->FrontID)+"_"+wfunction::itos(p->SessionID)+"_"+p->OrderRef;

    cerr << "map id\t" << mapid << endl;
    cerr << "FrontID\t" << p->FrontID << endl;
    cerr << "SessionID\t" << p->SessionID << endl;
    cerr << "OrderRef\t" << p->OrderRef << endl;
    cerr << "OrderStatus\t" << p->OrderStatus << endl;
    cerr << "iRequestID\t" << p->RequestID << endl;
    show_warning("Warning from OnRtnOrder");

//    cerr << "OrderRef" << p->OrderRef << endl;


    //
    //继续添加功能
    //
}
void orderlist::OnRtnTrade(CThostFtdcTradeField *pTrade)
{

}
