#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <string>
#include <QString>
using namespace std;

const int INF = 0x3f3f3f3f; //定义无穷大
const double Epslion = 1e-8; //double判断误差

typedef struct eNode //边链表结点
{
    string Line;    //线路编号
    eNode *next; //指向边链表下一个结点

    eNode() { next = nullptr; }
    eNode(string line) : eNode() { Line = line; } //初始化

} *teNode;

typedef struct vNode //顶点链表结点
{
    double x, y;      //坐标,采用double方便计算路程
    string station;   //站名
    teNode firstEdge; //指向一个边结点

    vNode() { firstEdge = nullptr; }

    void add(string line); //插入一条路
    bool erase(string line); //删除一条路，删除后为空返回true

} *tvNode;

double distance(vNode* one, vNode* other); //计算两点间的曼哈顿距离
struct lNode
{
    double price;           //价格
    int time;               //来车时间
    double speed;           //速度
    vector<tvNode> station; //途径站点

    vector<tvNode>::iterator find(string &name); //找到站点x，返回其迭代器
};

struct Graph //邻接表储存
{
    unordered_map<string, lNode> Line;    //线路信息
    unordered_map<string, vNode> Station; //站表
};
#endif // GRAPH_H
