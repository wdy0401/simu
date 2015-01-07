#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <QObject>

class orderlist : public QObject
{
    Q_OBJECT
public:
    explicit orderlist(QObject *parent = 0);

signals:

public slots:
    void rev_add_order();

};

#endif // ORDERLIST_H
