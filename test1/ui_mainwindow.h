/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <map.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Map *map;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *NewText;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QComboBox *mapChoice;
    QComboBox *choices;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *_2;
    QLabel *label_2;
    QLineEdit *StationA;
    QLabel *label_4;
    QVBoxLayout *_3;
    QLabel *label_3;
    QLineEdit *StationB;
    QPushButton *computer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loadin;
    QPushButton *loudout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(670, 454);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        map = new Map(centralWidget);
        map->setObjectName(QStringLiteral("map"));

        gridLayout->addWidget(map, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        NewText = new QTextBrowser(widget);
        NewText->setObjectName(QStringLiteral("NewText"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NewText->sizePolicy().hasHeightForWidth());
        NewText->setSizePolicy(sizePolicy1);
        QFont font;
        font.setKerning(true);
        NewText->setFont(font);
        NewText->setTabStopWidth(80);

        verticalLayout->addWidget(NewText);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(widget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        verticalLayout_2->addLayout(horizontalLayout);

        mapChoice = new QComboBox(widget);
        mapChoice->setObjectName(QStringLiteral("mapChoice"));

        verticalLayout_2->addWidget(mapChoice);

        choices = new QComboBox(widget);
        choices->setObjectName(QStringLiteral("choices"));

        verticalLayout_2->addWidget(choices);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        _2 = new QVBoxLayout();
        _2->setSpacing(6);
        _2->setObjectName(QStringLiteral("_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        _2->addWidget(label_2);

        StationA = new QLineEdit(widget);
        StationA->setObjectName(QStringLiteral("StationA"));

        _2->addWidget(StationA);


        horizontalLayout_2->addLayout(_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        _3 = new QVBoxLayout();
        _3->setSpacing(6);
        _3->setObjectName(QStringLiteral("_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        _3->addWidget(label_3);

        StationB = new QLineEdit(widget);
        StationB->setObjectName(QStringLiteral("StationB"));

        _3->addWidget(StationB);


        horizontalLayout_2->addLayout(_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        computer = new QPushButton(widget);
        computer->setObjectName(QStringLiteral("computer"));

        verticalLayout_2->addWidget(computer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        loadin = new QPushButton(widget);
        loadin->setObjectName(QStringLiteral("loadin"));

        horizontalLayout_3->addWidget(loadin);

        loudout = new QPushButton(widget);
        loudout->setObjectName(QStringLiteral("loudout"));

        horizontalLayout_3->addWidget(loudout);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\267\257\345\276\204\346\237\245\350\257\2422.3", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\266\210\346\201\257\346\240\217", Q_NULLPTR));
        addButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        mapChoice->clear();
        mapChoice->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\226\234\347\272\277\345\233\276", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\233\264\347\272\277\345\233\276", Q_NULLPTR)
        );
        choices->clear();
        choices->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\234\200\344\276\277\345\256\234\347\232\204\350\267\257\345\276\204", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\200\347\234\201\346\227\266\351\227\264\347\232\204\350\267\257\345\276\204\357\274\210\344\270\215\350\200\203\350\231\221\347\255\211\350\275\246\357\274\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\200\347\234\201\346\227\266\351\227\264\347\232\204\350\267\257\345\276\204\357\274\210\350\200\203\350\231\221\347\255\211\350\275\246\357\274\211", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\347\253\231\347\202\271A", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "->", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\231\347\202\271B", Q_NULLPTR));
        computer->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", Q_NULLPTR));
        loadin->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", Q_NULLPTR));
        loudout->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
