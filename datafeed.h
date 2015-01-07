#ifndef DATAFEED_H
#define DATAFEED_H

#include <QObject>

class datafeed : public QObject
{
    Q_OBJECT
public:
    explicit datafeed(QObject *parent = 0);

signals:
    void send_quote();
public slots:

};

#endif // DATAFEED_H
