#ifndef FILLPOLICY_H
#define FILLPOLICY_H

#include <QObject>

class fillpolicy : public QObject
{
    Q_OBJECT
public:
    explicit fillpolicy(QObject *parent = 0);

signals:
    void ack();
    void fill();
    void rej();
    void done();
public slots:
    void rec_quote();
};

#endif // FILLPOLICY_H
