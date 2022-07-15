#include "graph.h"

//插入一条路
void vNode::add(string line)
{
    teNode temp = new eNode(line);
    temp->next = firstEdge;
    firstEdge = temp;
}

//删除一条路，删除后为空返回true
bool vNode::erase(string line)
{
    if (firstEdge->Line == line)
    {
        teNode temp = firstEdge;
        firstEdge = temp->next;
        delete temp;
    }
    else
    {
        for (teNode prime = firstEdge; prime->next; prime = prime->next)
            if (prime->next->Line == line)
            {
                teNode temp = prime->next;
                prime->next = temp->next;
                delete temp;
                break;
            }
    }
    return firstEdge == nullptr;
}

//找到站点x，返回其迭代器
vector<tvNode>::iterator lNode::find(string &name)
{
    vector<tvNode>::iterator it = station.begin();
    while (it != station.end() && (*it)->station != name)
        ++it;
    return it;
}
