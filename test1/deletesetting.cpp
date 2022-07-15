#include "deletesetting.h"
#include "ui_deletesetting.h"
#include <qstring.h>

deleteSetting::deleteSetting(Graph *q, QTextBrowser *text, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteSetting)
{
    ui->setupUi(this);
    area = text;
    data = q;   //绑定数据库

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Dialog);
}

deleteSetting::~deleteSetting()
{
    delete ui;
}

void deleteSetting::on_trueButton_clicked()
{
    string line = ui->lineEdit->text().toStdString();
    if (data->Line.find(line) != data->Line.end()) //存在线路
    {
        for (tvNode x : data->Line[line].station)
        {
            x->erase(line);
            if (x->firstEdge == nullptr) //空站
                data->Station.erase(x->station);
        }

        data->Line.erase(line);
        QString temp = "线路 ";
        temp.push_back(ui->lineEdit->text());
        temp.push_back(" 已删除");
        area->append(temp);
        emit change(); //发出信号
    }
    else area->append("删除失败，该线路不存在！");
    close();
}
