#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "graph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void change();

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    inline double distance(vNode* one, vNode* other);

private slots:

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_NewText_textChanged();

    void on_loadin_clicked();

    void on_loudout_clicked();

    void on_computer_clicked();

    void on_mapChoice_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QLabel *lab;
};

#endif // MAINWINDOW_H
