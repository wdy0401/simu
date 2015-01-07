#ifndef MATCH_ENGINE
#define MATCH_ENGINE

#include<string>
#include<map>
#include"orderlist.h"
#include"../gpp_qt/wtimer/wtimer.h"
#include"../gpp_qt/fillpolicy/fillpolicy.h"
#include"../gpp_qt/datafeed/datafeed.h"

#include<QObject>

//修改此类以满足通用要求




//tactic
//所需函数
//0.初始化
//1.收回报
//2.读行情
//3.发单 改单 撤单


//主要功能
//模拟交易所进行撮合交易，本撮合引擎可处理多symbol的交易。
//本引擎并不基于实际时间，其速度取决于信息流速度。可以更快的给出模拟结果。
//本引擎仅处理leg信息，组合另文处理。


//鉴于多策略合成的复杂性，本ME不处理多策略的关系。若有需求，须包装成同样接口

//时序关系为
//更新orderbook(怎样调用，调用几次 取决于数据源)
//查看fillpolicy（顺序给出fill load新order 给出ack or rej）
//更新tactic（包含更新orderlist）

//信息流均通过trans_event进行


class match_engine:public QObject
{
    Q_OBJECT
public:

    match_engine();

    bool loadtactic(std::string &);
    bool loadfillpolicy(std::string &);

    void rec_update(const std::string & symbol, const std::string & ba, long level, double price, long size);

    void setnowsymbol(const std::string & symbol);
    void updateorderbook(const std::string &,const std::string &,long,double,long);//IF1405 bid 1 2100.2 5
    void updatefp();//改写orderlist各个order的状态
    void updatetactic(const std::string & symbol, const std::string & ba, long level, double price, long size);//根新的orderbook来判断时候发送order
//	void updatetacticbooks();//在策略需要看多个book时使用 暂未实现

    void new_order(const std::string & symbol,  const std::string & buysell, double price ,long size);
    void add_order(const std::string & msg);



private:
    std::map<std::string,orderbook> _orderbooks;
    fillpolicy _fp;
    orderlist _ol;
    std::string _nowsymbol;
    TRANS_ORDER::order _order_message;
};
#endif
