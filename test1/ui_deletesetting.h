/********************************************************************************
** Form generated from reading UI file 'deletesetting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETESETTING_H
#define UI_DELETESETTING_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteSetting
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *trueButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;

    void setupUi(QWidget *deleteSetting)
    {
        if (deleteSetting->objectName().isEmpty())
            deleteSetting->setObjectName(QStringLiteral("deleteSetting"));
        deleteSetting->resize(290, 115);
        verticalLayout = new QVBoxLayout(deleteSetting);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(deleteSetting);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(deleteSetting);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        trueButton = new QPushButton(deleteSetting);
        trueButton->setObjectName(QStringLiteral("trueButton"));

        horizontalLayout_2->addWidget(trueButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel = new QPushButton(deleteSetting);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout_2->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(deleteSetting);
        QObject::connect(cancel, SIGNAL(clicked()), deleteSetting, SLOT(close()));

        QMetaObject::connectSlotsByName(deleteSetting);
    } // setupUi

    void retranslateUi(QWidget *deleteSetting)
    {
        deleteSetting->setWindowTitle(QApplication::translate("deleteSetting", "\345\210\240\351\231\244\347\272\277\350\267\257", Q_NULLPTR));
        label->setText(QApplication::translate("deleteSetting", "\345\210\240\351\231\244\347\272\277\350\267\257\345\220\215", Q_NULLPTR));
        trueButton->setText(QApplication::translate("deleteSetting", "\347\241\256\345\256\232", Q_NULLPTR));
        cancel->setText(QApplication::translate("deleteSetting", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class deleteSetting: public Ui_deleteSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETESETTING_H
