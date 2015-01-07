#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <QObject>

class orderbook : public QObject
{
    Q_OBJECT
public:
    explicit orderbook(QObject *parent = 0);

signals:

public slots:

};

#endif // ORDERBOOK_H
