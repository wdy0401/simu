#ifndef MATCH_ENGINE_H
#define MATCH_ENGINE_H

#include <QObject>
#include<string>

class match_engine : public QObject
{
    Q_OBJECT
public:
    explicit match_engine(QObject *parent = 0);
    std::string new_order(const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size);

signals:
    void send_quote_book();
    void send_quote_fp();
    void send_quote_tactic();
    void send_add_order();

public slots:
    void rec_quote();
};

#endif // MATCH_ENGINE_H
