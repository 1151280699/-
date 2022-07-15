#include "addsetting.h"
#include "ui_addsetting.h"
#include <qstring.h>

using namespace std;

addsetting::addsetting(Graph *q, QTextBrowser *text, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addsetting)
{
    ui->setupUi(this);
    area = text;    //绑定输出提示框
    data = q;   //绑定数据库
    //设置表格宽度
    ui->StationNums->setColumnWidth(0, 120);
    ui->StationNums->setColumnWidth(1, 40);
    ui->StationNums->setColumnWidth(2, 40);

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Dialog);
}

addsetting::~addsetting()
{
    delete ui;
}

void addsetting::on_trueButton_clicked()
{
    string line = ui->lineText->text().toStdString();
    if (data->Line.find(line)== data->Line.end()) //新线路
    {
        data->Line[line].price = ui->MoneyText->text().toDouble();
        data->Line[line].time = ui->timeText->text().toInt();
        data->Line[line].speed = ui->speedText->text().toDouble();

        for (int i = 0; i < ui->StationNums->rowCount() && ui->StationNums->item(i,0); ++i)
        {
            //注意未编辑时为空指针
            QString temp = ui->StationNums->item(i, 0)->text();
            if (temp.isEmpty()) break;

            string name = temp.toStdString();
            if (data->Station.find(name) == data->Station.end()) //新站点
            {
                data->Station[name].x = ui->StationNums->item(i, 1)->text().toDouble();
                data->Station[name].y = ui->StationNums->item(i, 2)->text().toDouble();
                data->Station[name].station = name;
            }
            data->Station[name].add(line);
            data->Line[line].station.push_back(&data->Station[name]);
        }
        QString temp = "线路 ";
        temp.push_back(ui->lineText->text());
        temp.push_back(" 已创建");
        area->append(temp);
        emit change(); //发出信号
    }
    else area->append("创建失败，该线路已存在！");
    close();
}

void addsetting::on_addStation_clicked()
{
    ui->StationNums->insertRow(ui->StationNums->rowCount()); //添加最后一行
}

void addsetting::on_deleteStation_clicked()
{
    ui->StationNums->removeRow(ui->StationNums->rowCount()-1); //删除最后一行
}

void addsetting::on_StationNums_cellChanged(int row, int column) //当站点存在时，补全x,y并锁定
{
    if (column == 0)
    {
        string name = ui->StationNums->item(row, 0)->text().toStdString();
        if (data->Station.find(name) != data->Station.end()) //该站点已存在
        {
            //直接处理item，可能不存在
            QTableWidgetItem *item1 = new QTableWidgetItem;
            QTableWidgetItem *item2 = new QTableWidgetItem;
            item1->setText(QString::number(data->Station[name].x));
            item1->setFlags(Qt::ItemIsEditable);
            item2->setText(QString::number(data->Station[name].y));
            item2->setFlags(Qt::ItemIsEditable);
            ui->StationNums->setItem(row, 1, item1);
            ui->StationNums->setItem(row, 2, item2);
        }
        else
        {
            //恢复单元格的可编辑性
            for (int i = 1; i <= 2; ++i)
                if (ui->StationNums->item(row, i))
                    delete ui->StationNums->item(row, i);
        }
    }
}
