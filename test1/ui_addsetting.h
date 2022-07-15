/********************************************************************************
** Form generated from reading UI file 'addsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSETTING_H
#define UI_ADDSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addsetting
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineText;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *MoneyText;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *speedText;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *timeText;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *addStation;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deleteStation;
    QTableWidget *StationNums;
    QHBoxLayout *horizontalLayout;
    QPushButton *trueButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *falseButton;

    void setupUi(QWidget *addsetting)
    {
        if (addsetting->objectName().isEmpty())
            addsetting->setObjectName(QStringLiteral("addsetting"));
        addsetting->resize(270, 376);
        verticalLayout = new QVBoxLayout(addsetting);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(-1, 7, 7, 7);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(addsetting);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineText = new QLineEdit(addsetting);
        lineText->setObjectName(QStringLiteral("lineText"));

        horizontalLayout_2->addWidget(lineText);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(addsetting);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        MoneyText = new QLineEdit(addsetting);
        MoneyText->setObjectName(QStringLiteral("MoneyText"));

        horizontalLayout_3->addWidget(MoneyText);

        label_5 = new QLabel(addsetting);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(addsetting);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        speedText = new QLineEdit(addsetting);
        speedText->setObjectName(QStringLiteral("speedText"));

        horizontalLayout_4->addWidget(speedText);

        label_7 = new QLabel(addsetting);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(addsetting);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        timeText = new QLineEdit(addsetting);
        timeText->setObjectName(QStringLiteral("timeText"));

        horizontalLayout_5->addWidget(timeText);

        label_6 = new QLabel(addsetting);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        addStation = new QPushButton(addsetting);
        addStation->setObjectName(QStringLiteral("addStation"));

        horizontalLayout_6->addWidget(addStation);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        deleteStation = new QPushButton(addsetting);
        deleteStation->setObjectName(QStringLiteral("deleteStation"));

        horizontalLayout_6->addWidget(deleteStation);


        verticalLayout->addLayout(horizontalLayout_6);

        StationNums = new QTableWidget(addsetting);
        if (StationNums->columnCount() < 3)
            StationNums->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        StationNums->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        StationNums->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        StationNums->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (StationNums->rowCount() < 2)
            StationNums->setRowCount(2);
        StationNums->setObjectName(QStringLiteral("StationNums"));
        StationNums->setLineWidth(1);
        StationNums->setAutoScrollMargin(16);
        StationNums->setDefaultDropAction(Qt::IgnoreAction);
        StationNums->setAlternatingRowColors(false);
        StationNums->setIconSize(QSize(0, 0));
        StationNums->setTextElideMode(Qt::ElideRight);
        StationNums->setGridStyle(Qt::SolidLine);
        StationNums->setRowCount(2);
        StationNums->horizontalHeader()->setCascadingSectionResizes(false);
        StationNums->horizontalHeader()->setDefaultSectionSize(81);
        StationNums->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        StationNums->horizontalHeader()->setStretchLastSection(false);
        StationNums->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(StationNums);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        trueButton = new QPushButton(addsetting);
        trueButton->setObjectName(QStringLiteral("trueButton"));
        trueButton->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(trueButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        falseButton = new QPushButton(addsetting);
        falseButton->setObjectName(QStringLiteral("falseButton"));

        horizontalLayout->addWidget(falseButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(addsetting);
        QObject::connect(falseButton, SIGNAL(clicked()), addsetting, SLOT(close()));

        QMetaObject::connectSlotsByName(addsetting);
    } // setupUi

    void retranslateUi(QWidget *addsetting)
    {
        addsetting->setWindowTitle(QApplication::translate("addsetting", "\345\210\233\345\273\272\347\272\277\350\267\257", Q_NULLPTR));
        label->setText(QApplication::translate("addsetting", "\347\272\277\350\267\257\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("addsetting", "\350\264\271\347\224\250", Q_NULLPTR));
        label_5->setText(QApplication::translate("addsetting", "\345\205\203", Q_NULLPTR));
        label_3->setText(QApplication::translate("addsetting", "\350\275\246\351\200\237", Q_NULLPTR));
        label_7->setText(QApplication::translate("addsetting", "\347\261\263/\345\210\206\351\222\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("addsetting", "\347\255\211\350\275\246\346\227\266\351\227\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("addsetting", "\345\210\206\351\222\237", Q_NULLPTR));
        addStation->setText(QApplication::translate("addsetting", "\346\267\273\345\212\240\350\275\246\347\253\231", Q_NULLPTR));
        deleteStation->setText(QApplication::translate("addsetting", "\345\210\240\351\231\244\350\275\246\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = StationNums->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addsetting", "\350\275\246\347\253\231\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = StationNums->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addsetting", "x", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = StationNums->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("addsetting", "y", Q_NULLPTR));
        trueButton->setText(QApplication::translate("addsetting", "\347\241\256\345\256\232", Q_NULLPTR));
        falseButton->setText(QApplication::translate("addsetting", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addsetting: public Ui_addsetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSETTING_H
