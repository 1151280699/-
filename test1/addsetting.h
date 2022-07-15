#ifndef ADDSETTING_H
#define ADDSETTING_H

#include <QWidget>
#include <QTextBrowser>
#include "graph.h"

namespace Ui {
class addsetting;
}

class addsetting : public QWidget
{
    Q_OBJECT

signals:
    void change();

public:
    explicit addsetting(Graph *q, QTextBrowser *text, QWidget *parent = 0);
    ~addsetting();

private slots:
    void on_trueButton_clicked();

    void on_addStation_clicked();

    void on_deleteStation_clicked();

    void on_StationNums_cellChanged(int row, int column);

private:
    Ui::addsetting *ui;
    QTextBrowser *area;
    Graph *data;
};

#endif // ADDSETTING_H
