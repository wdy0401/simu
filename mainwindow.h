#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_qa(QApplication * p){qa=p;}
public slots:
    void show_quote(const std::string & symbol,const std::string & bidask,long level,double price,long size);
private:
    Ui::MainWindow *ui;
    QApplication * qa;
};

#endif // MAINWINDOW_H
