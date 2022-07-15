#include "map.h"
#include "qgraphicsscene.h"
#include <QGraphicsEllipseItem>

//50种鲜明颜色以供选择
const QColor color[50] = {"#ed1299", "#09f9f5", "#246b93", "#cc8e12", "#d561dd", "#c93f00", "#ddd53e",
                          "#4aef7b", "#e86502", "#9ed84e", "#39ba30", "#6ad157", "#8249aa", "#99db27", "#e07233", "#ff523f",
                          "#ce2523", "#f7aa5d", "#cebb10", "#03827f", "#931635", "#373bbf", "#a1ce4c", "#ef3bb6", "#d66551",
                          "#1a918f", "#ff66fc", "#2927c4", "#7149af", "#57e559", "#8e3af4", "#f9a270", "#22547f", "#db5e92",
                          "#edd05e", "#6f25e8", "#0dbc21", "#280f7a", "#6373ed", "#5b910f", "#7b34c1", "#0cf29a", "#d80fc1",
                          "#dd27ce", "#07a301", "#167275", "#391c82", "#2baeb5","#925bea", "#63ff4f"};

const double sizeS = 28; //站点的大小
const double sf = 12;    //放大倍数

inline void addArrow(double x1, double y1, double x2, double y2, QGraphicsScene *sc, QPen &pen)
{
    x1 = x1*sf + sizeS/2;
    y1 = y1*sf + sizeS/2;
    x2 = x2*sf + sizeS/2;
    y2 = y2*sf + sizeS/2;
    double angle = atan2(y2-y1,x2-x1);//计算线段的夹角
    double l = 10;  //箭头边的长度
    double a = 0.4; //箭头与线段的夹角
    double new_x1 = x2 - l * cos(angle - a);
    double new_y1 = y2 - l * sin(angle - a);
    double new_x2 = x2 - l * cos(angle + a);
    double new_y2 = y2 - l * sin(angle + a);
    QGraphicsLineItem *wl = new QGraphicsLineItem(new_x1, new_y1, x2, y2);
    QGraphicsLineItem *wr = new QGraphicsLineItem(new_x2, new_y2, x2, y2);
    wl->setPen(pen);
    wr->setPen(pen);
    sc->addItem(wl);
    sc->addItem(wr);
}

inline void addLine(double x1, double y1, double x2, double y2, QGraphicsScene *sc, QString &tip, QPen &pen)
{
    x1 = x1*sf + sizeS/2;
    y1 = y1*sf + sizeS/2;
    x2 = x2*sf + sizeS/2;
    y2 = y2*sf + sizeS/2;
    QGraphicsLineItem *line = new QGraphicsLineItem(x1, y1, x2, y2);
    line->setPen(pen);
    line->setToolTip(tip);
    sc->addItem(line);
}

Map::Map(QWidget *parent) : QGraphicsView(parent)
{
}

void Map::setC(QComboBox *c)
{
    choice = c;
}

void Map::paint()
{
    QGraphicsScene *mm = new QGraphicsScene;
    QPen pen;

    //画线路
    pen.setWidth(5);
    int i = 0;
    for (auto x : data.Line)
    {
        double dy = (i % 2 ? 1 : -1) * ((i - 1) / 2 + 1) * 2.5 / sizeS; //偏差
        if (i < 50) pen.setColor(color[i]);
        else pen.setColor(QColor(rand() % 256, rand() % 256, rand() % 256)); //随机颜色
        pen.setWidth(sizeS / 10);
        double nx, ny;
        double x2, y2;
        bool cou = false; //第一个点不画
        QString tip =  "线路 " + QString::fromStdString(x.first) + "\n";
        tip += "车费" + QString::number(x.second.price) + "元，车速" + QString::number(x.second.speed) + "m/min\n";
        tip += "平均发车间隔" + QString::number(x.second.time) + "分钟/次\n";
        tip += "包含站点：";
        for (tvNode t : x.second.station)
            tip += "\n" + QString::fromStdString(t->station);

        for (tvNode t : x.second.station)
        {
            x2 = t->x + dy, y2 = t->y + dy;
            if (cou)
            {
                if (choice->currentIndex()) //直线图
                {
                    addLine(nx, ny, x2, ny, mm, tip, pen);
                    addArrow(nx, ny, x2, ny, mm, pen);
                    addLine(x2, ny, x2, y2, mm, tip, pen);
                }
                else  //斜线图
                {
                    addLine(nx, ny, x2, y2, mm, tip, pen);
                    addArrow(nx, ny, (nx + x2) / 2, (ny + y2) / 2, mm, pen);
                }
            }
            else cou = true;
            nx = x2, ny = y2;
        }
        ++i;
    }

    //画站点
    pen.setColor(QColor("#f9a270"));
    pen.setWidth(sizeS/5);
    for (auto x : data.Station)
    {
        QGraphicsEllipseItem *cir = new QGraphicsEllipseItem(x.second.x*sf, x.second.y*sf, sizeS, sizeS);
        cir->setPen(pen);
        cir->setBrush(QBrush(QColor("#ffffff")));

        //贴提示文字
        QString tip = "站点：" + QString::fromStdString(x.first);
        tip += "\n(" + QString::number(x.second.x) + ", " + QString::number(x.second.y) + ")\n";
        tip += "包含线路：";
        for (teNode t = x.second.firstEdge; t; t = t->next)
            tip += "\n" + QString::fromStdString(t->Line);
        cir->setToolTip(tip);
        mm->addItem(cir);

        QGraphicsTextItem *text = new QGraphicsTextItem(QString::fromStdString(x.first).mid(0, 1));
        text->setPos(x.second.x*sf + sizeS/5, x.second.y*sf + sizeS/5);
        mm->addItem(text);
    }

    setScene(mm);
}
