#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addsetting.h"
#include "deletesetting.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qdir.h"
#include "stack"

const QString Separator = "**********";//规定存档分隔符

inline double MainWindow::distance(vNode* one, vNode* other) //计算两点间的距离
{
    if (ui->mapChoice->currentIndex())
        return abs(one->x - other->x) + abs(one->y - other->y); //曼哈顿距离
    else return sqrt(pow(one->x - other->x, 2) + pow(one->y - other->y, 2)); //两点距离
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->map->setC(ui->mapChoice);
    connect(this, MainWindow::change, ui->map, Map::paint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    addsetting* newAdd = new addsetting(&ui->map->data, ui->NewText, this);
    connect(newAdd, addsetting::change, ui->map, Map::paint);
    newAdd->show();
}

void MainWindow::on_deleteButton_clicked()
{
    deleteSetting* newDelete = new deleteSetting(&ui->map->data, ui->NewText, this);
    connect(newDelete, deleteSetting::change, ui->map, Map::paint);

    newDelete->show();
}


void MainWindow::on_NewText_textChanged() //光标自动下移
{
    ui->NewText->moveCursor(QTextCursor::End);
}

void MainWindow::on_loadin_clicked() //导入数据
{
    static int count = 0; //确认次数
    QFile file("./Appdata/save.txt");

    Graph &data = ui->map->data;
    //检测当前是否存在数据避免造成混乱
    if ((data.Line.empty() && data.Station.empty()) || count == 1)
    {
        count = 0;
        data.Line.clear();
        data.Station.clear();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            int lNum = 0, slNum = 0, sNum = 0;
            QTextStream in(&file);
            QString temp;
            //读取线路信息
            while (in >> temp, temp != Separator)
            {
                ++lNum;
                string line = temp.toStdString();
                in >> data.Line[line].price;
                in >> data.Line[line].time;
                in >> data.Line[line].speed;
                QString station;
                while (in >> station, station != "*")
                {
                    string tt = station.toStdString();
                    if (data.Station.find(tt) == data.Station.end()) ++slNum;
                    data.Station[tt].station = tt;
                    data.Station[tt].add(line);
                    data.Line[line].station.push_back(&data.Station[tt]);
                }
            }
            //读取站点信息
            while (!in.atEnd() && (in >> temp, !temp.isEmpty()))
            {
                ++sNum;
                string station = temp.toStdString();
                in >> data.Station[station].x >> data.Station[station].y;
            }
            //判断存档是否正常
            if (slNum == sNum)
            {
                temp = "共找到 ";
                temp += QString::number(lNum);
                temp += " 条线路，";
                temp += QString::number(sNum);
                temp += " 个站点";
                ui->NewText->append(temp);
                ui->NewText->append("已导入存档！");
                emit change(); //发出信号
            }
            else ui->NewText->append("存档数据异常，请重启应用，并清除存档！");
        }
        else ui->NewText->append("未检测到存档！");

    }
    else
    {
        ui->NewText->append("检查到当前已有数据，是否导入新的数据?");
        ui->NewText->append("请再次按下导入确认");
        ++count;
    }
}

void MainWindow::on_loudout_clicked() //导出数据
{
    QDir dir;
    if (!dir.exists("./Appdata"))
        dir.mkdir("./Appdata"); //不存在文件夹，创建文件夹

    QFile file("./Appdata/save.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream out(&file);

    //存储线路信息
    for (auto x: ui->map->data.Line)
    {
        out << QString::fromStdString(x.first) << '\n';
        out << x.second.price << ' ' << x.second.time << ' ' << x.second.speed << '\n';
        for (tvNode y: x.second.station)
            out << QString::fromStdString(y->station) << ' ';
        out << "*\n"; //*作为一条线路截止
    }
    out << Separator << '\n'; //规定分隔符;
    //存储站点信息
    for (auto x: ui->map->data.Station)
    {
        out << QString::fromStdString(x.first) << ' ';
        out << x.second.x << ' ' << x.second.y << '\n';
    }
    ui->NewText->append("存档已保存！");
    file.close();
}

void MainWindow::on_computer_clicked() //查找功能（核心）
{
    auto &Station = ui->map->data.Station;
    auto &Line = ui->map->data.Line;
    if (ui->StationA && ui->StationB)
    {
        string a = ui->StationA->text().toStdString();
        string b = ui->StationB->text().toStdString();
        if (Station.find(a) == Station.end() ||
                Station.find(b) == Station.end())
        {
            ui->NewText->append("未找到对应车站，请确认输入！");
            return;
        }

        //dijkstra算法
        map<string , bool> st;  //离散化标记


        typedef pair<string, string> pss; //(站点、线路)
        unordered_map<string, pss> path; //保存路径
        for (auto x : Station) path[x.first] = {x.first, ""};

        switch (ui->choices->currentIndex())
        {
        case 0: //最便宜的路径
        {
            map<string , map<string , bool>> stLine;  //离散化标记
            unordered_map<string, double> price;
            for (auto x : Station) price[x.first] = INF;
            price[a] = 0.0f;

            for (int i = 0; i < (signed)Station.size() - 1; ++i)
            {
                string mi = "";
                for (auto x : Station)
                {
                    if (!st[x.first] && (mi == "" || price[x.first] < price[mi]))
                        mi = x.first;
                }
                st[mi] = true;

                for (teNode x = Station[mi].firstEdge; x; x = x->next)
                {
                    for (auto y = Line[x->Line].find(mi);
                         y != Line[x->Line].station.end() && !stLine[(*y)->station][x->Line]; ++y)
                    {
                        stLine[(*y)->station][x->Line] = true;
                        double d = price[mi] + Line[x->Line].price;
                        if (d < price[(*y)->station])
                        {
                            price[(*y)->station] = d;
                            path[(*y)->station] = {mi, x->Line};
                        }
                    }
                }
            }

            stack<pss> res;
            bool hc = false;
            //输出结果
            ui->NewText->append(QString::fromStdString(a) + "到" + QString::fromStdString(b) + "的最便宜路径为：\n");
            for (pss t = path[b]; t.second != ""; t = path[t.first])
                res.push(t);

            while (res.size())
            {
                if (!hc)
                {
                    ui->NewText->insertPlainText("线路" + QString::fromStdString(res.top().second) +
                                                 ":" + QString::fromStdString(res.top().first));
                    hc = true;
                }
                else ui->NewText->append("换乘线路" + QString::fromStdString(res.top().second) +
                                         ":" + QString::fromStdString(res.top().first));

                string temp = res.top().first;
                string line = res.top().second;
                res.pop();
                auto y = Line[line].find(temp);
                do
                {
                    ++y;
                    ui->NewText->insertPlainText("，" + QString::fromStdString((*y)->station));
                } while ((res.size() && (*y)->station != res.top().first) ||
                         (!res.size() && (*y)->station != b));
            }
            if (abs(price[b]-INF) < Epslion) ui->NewText->insertPlainText("不存在相关路径！");
            else ui->NewText->append("共花费" + QString::asprintf("%.2lf", price[b]) + "元");
            break;
        }
        case 1: //最省时间的路径（不考虑等车）
        {
            unordered_map<string, double> time;
            for (auto x : Station) time[x.first] = INF;
            time[a] = 0.0f;

            for (int i = 0; i < (signed)Station.size() - 1; ++i)
            {
                string mi = "";
                for (auto x : Station)
                {
                    if (!st[x.first] && (mi == "" || time[x.first] < time[mi]))
                        mi = x.first;
                }
                st[mi] = true;

                //更新
                for (teNode x = Station[mi].firstEdge; x; x = x->next)
                {
                    auto y = ++Line[x->Line].find(mi);
                    if (y == Line[x->Line].station.end()) continue;
                    double ti = time[mi] + distance(&Station[mi], *y) / Line[x->Line].speed;

                    if (ti < time[(*y)->station])
                    {
                        time[(*y)->station] = ti;
                        path[(*y)->station] = {mi, x->Line};
                    }
                }
            }

            stack<pss> res;
            bool hc = false;
            //输出结果
            ui->NewText->append(QString::fromStdString(a) + "到" + QString::fromStdString(b) + "的最省时间的路径：\n");
            for (pss t = path[b]; t.second != ""; t = path[t.first])
                res.push(t);

            string pline = "";
            while (res.size())
            {
                if (pline != res.top().second)
                {
                    pline = res.top().second;
                    if (!hc)
                    {
                        ui->NewText->insertPlainText("线路" + QString::fromStdString(pline) +
                                                     ":" + QString::fromStdString(res.top().first));
                        hc = true;
                    }
                    else ui->NewText->append("换乘线路" + QString::fromStdString(pline) +
                                             ":" + QString::fromStdString(res.top().first));
                }

                string temp = res.top().first;
                string line = res.top().second;
                res.pop();
                auto y = Line[line].find(temp);
                do
                {
                    ++y;
                    ui->NewText->insertPlainText("，" + QString::fromStdString((*y)->station));
                } while ((res.size() && (*y)->station != res.top().first) ||
                         (!res.size() && (*y)->station != b));
            }
            if (abs(time[b]-INF) < Epslion) ui->NewText->insertPlainText("不存在相关路径！");
            else ui->NewText->append("共花费" + QString::asprintf("%.2lf", time[b]) + "分钟");
            break;
        }
        case 2: //最省时间的路径（考虑等车）
        {
            map<string , map<string , bool>> stLine;  //离散化标记
            unordered_map<string, double> time;
            unordered_map<string, unordered_map<string, double>> lTime; // 站点、线路、第一次到达时间
            for (auto x : Station) time[x.first] = INF;
            for (auto x : Line) //初始化时间
            {
                string prime = "";
                for (tvNode y : x.second.station)
                {
                    if (prime == "") lTime[y->station][x.first] = 0;
                    else lTime[y->station][x.first] =
                            lTime[prime][x.first] + distance(&Station[prime], &Station[y->station]) /  Line[x.first].speed;
                    prime = y->station;
                }
            }
            time[a] = 0.0f;

            for (int i = 0; i < (signed)Station.size() - 1; ++i)
            {
                string mi = "";
                for (auto x : Station)
                {
                    if (!st[x.first] && (mi == "" || time[x.first] < time[mi]))
                        mi = x.first;
                }
                st[mi] = true;

                for (teNode x = Station[mi].firstEdge; x; x = x->next)
                {
                    double n = (time[mi] - lTime[mi][x->Line]) / Line[x->Line].time;
                    n = max(1.0, ceil(n + 1));
                    double t = (n - 1) * Line[x->Line].time + lTime[mi][x->Line];
                    string prime = mi;
                    for (auto y = Line[x->Line].find(mi);
                         y != Line[x->Line].station.end( )&& !stLine[(*y)->station][x->Line]; ++y)
                    {
                        stLine[(*y)->station][x->Line] = true;
                        t += distance(&Station[prime], &Station[(*y)->station]) /  Line[x->Line].speed;
                        if ( t < time[(*y)->station])
                        {
                            time[(*y)->station] = t;
                            path[(*y)->station] = {mi, x->Line};
                        }
                        prime = (*y)->station;
                    }
                }
            }

            stack<pss> res;
            bool hc = false;
            //输出结果
            ui->NewText->append(QString::fromStdString(a) + "到" + QString::fromStdString(b) + "的最省时间的路径为（考虑等车）：\n");
            for (pss t = path[b]; t.second != ""; t = path[t.first])
                res.push(t);

            while (res.size())
            {
                if (!hc)
                {
                    ui->NewText->insertPlainText("线路" + QString::fromStdString(res.top().second) +
                                                 ":" + QString::fromStdString(res.top().first));
                    hc = true;
                }
                else ui->NewText->append("换乘线路" + QString::fromStdString(res.top().second) +
                                         ":" + QString::fromStdString(res.top().first));

                string temp = res.top().first;
                string line = res.top().second;
                res.pop();
                auto y = Line[line].find(temp);
                do
                {
                    ++y;
                    ui->NewText->insertPlainText("，" + QString::fromStdString((*y)->station));
                } while ((res.size() && (*y)->station != res.top().first) ||
                         (!res.size() && (*y)->station != b));
            }
            if (abs(time[b]-INF) < Epslion) ui->NewText->insertPlainText("不存在相关路径！");
            else ui->NewText->append("共花费" + QString::asprintf("%.2lf", time[b]) + "分钟");
            break;
        }
        default:
        {
            //以防出现意外
            ui->NewText->append("功能选择错误，请反馈bug！");
            break;
        }
        }
    }
    else ui->NewText->append("请输入车站");

}

void MainWindow::on_mapChoice_currentIndexChanged(int )
{
    emit change();
}
