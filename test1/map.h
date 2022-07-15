#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include "qcombobox.h"
#include "graph.h"

class Map : public QGraphicsView
{
    Q_OBJECT

public:
    Graph data; //地图存储
    explicit Map(QWidget *parent = nullptr);
    void setC(QComboBox *c);
signals:

public slots:
    void paint();

private:
    QComboBox *choice;
};

#endif // MAP_H
