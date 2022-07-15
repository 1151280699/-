#ifndef DELETESETTING_H
#define DELETESETTING_H

#include <QWidget>
#include <QTextBrowser>
#include "graph.h"


namespace Ui {
class deleteSetting;
}

class deleteSetting : public QWidget
{
    Q_OBJECT

signals:
    void change();

public:
    explicit deleteSetting(Graph *q, QTextBrowser *text, QWidget *parent = 0);
    ~deleteSetting();

private slots:
    void on_trueButton_clicked();

private:
    Ui::deleteSetting *ui;
    QTextBrowser *area;
    Graph *data;
};

#endif // DELETESETTING_H
