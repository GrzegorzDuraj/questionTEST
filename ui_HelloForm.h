/********************************************************************************
** Form generated from reading UI file 'HelloForm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOFORM_H
#define UI_HELLOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QPushButton *check;
    QPushButton *next;
    QPushButton *closeButton;
    QLabel *question;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutAnsRadio;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_1;
    QLabel *answer_1;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_2;
    QLabel *answer_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_3;
    QLabel *answer_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_4;
    QLabel *answer_4;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_5;
    QLabel *answer_5;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *numerPyt;
    QLabel *attemptLabel;
    QLabel *correctAns;
    QLabel *labelCorrect;

    void setupUi(QDialog *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QStringLiteral("HelloForm"));
        HelloForm->resize(1050, 908);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(16);
        sizePolicy.setVerticalStretch(9);
        sizePolicy.setHeightForWidth(HelloForm->sizePolicy().hasHeightForWidth());
        HelloForm->setSizePolicy(sizePolicy);
        check = new QPushButton(HelloForm);
        check->setObjectName(QStringLiteral("check"));
        check->setGeometry(QRect(10, 820, 191, 80));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(check->sizePolicy().hasHeightForWidth());
        check->setSizePolicy(sizePolicy1);
        check->setMinimumSize(QSize(100, 80));
        check->setMaximumSize(QSize(16777215, 80));
        check->setSizeIncrement(QSize(24, 17));
        next = new QPushButton(HelloForm);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(260, 820, 161, 80));
        next->setMinimumSize(QSize(0, 80));
        next->setMaximumSize(QSize(16777215, 80));
        closeButton = new QPushButton(HelloForm);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(930, 860, 80, 23));
        question = new QLabel(HelloForm);
        question->setObjectName(QStringLiteral("question"));
        question->setGeometry(QRect(20, 10, 1001, 161));
        QFont font;
        font.setPointSize(13);
        question->setFont(font);
        layoutWidget = new QWidget(HelloForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 212, 1024, 431));
        verticalLayoutAnsRadio = new QVBoxLayout(layoutWidget);
        verticalLayoutAnsRadio->setObjectName(QStringLiteral("verticalLayoutAnsRadio"));
        verticalLayoutAnsRadio->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_1 = new QCheckBox(layoutWidget);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));

        horizontalLayout->addWidget(checkBox_1);

        answer_1 = new QLabel(layoutWidget);
        answer_1->setObjectName(QStringLiteral("answer_1"));
        answer_1->setMinimumSize(QSize(1000, 0));
        QFont font1;
        font1.setPointSize(11);
        answer_1->setFont(font1);

        horizontalLayout->addWidget(answer_1);


        verticalLayoutAnsRadio->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        QPalette palette;
        QBrush brush(QColor(0, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        checkBox_2->setPalette(palette);
        QFont font2;
        font2.setPointSize(15);
        checkBox_2->setFont(font2);

        horizontalLayout_2->addWidget(checkBox_2);

        answer_2 = new QLabel(layoutWidget);
        answer_2->setObjectName(QStringLiteral("answer_2"));
        answer_2->setMinimumSize(QSize(1000, 0));
        answer_2->setFont(font1);

        horizontalLayout_2->addWidget(answer_2);


        verticalLayoutAnsRadio->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);

        answer_3 = new QLabel(layoutWidget);
        answer_3->setObjectName(QStringLiteral("answer_3"));
        answer_3->setMinimumSize(QSize(1000, 0));
        answer_3->setFont(font1);

        horizontalLayout_3->addWidget(answer_3);


        verticalLayoutAnsRadio->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_4 = new QCheckBox(layoutWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_4->addWidget(checkBox_4);

        answer_4 = new QLabel(layoutWidget);
        answer_4->setObjectName(QStringLiteral("answer_4"));
        answer_4->setMinimumSize(QSize(1000, 0));
        answer_4->setFont(font1);

        horizontalLayout_4->addWidget(answer_4);


        verticalLayoutAnsRadio->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBox_5 = new QCheckBox(layoutWidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout_10->addWidget(checkBox_5);

        answer_5 = new QLabel(layoutWidget);
        answer_5->setObjectName(QStringLiteral("answer_5"));
        answer_5->setMinimumSize(QSize(1000, 0));
        answer_5->setFont(font1);

        horizontalLayout_10->addWidget(answer_5);


        verticalLayoutAnsRadio->addLayout(horizontalLayout_10);

        layoutWidget1 = new QWidget(HelloForm);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 670, 1001, 81));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        numerPyt = new QLabel(layoutWidget1);
        numerPyt->setObjectName(QStringLiteral("numerPyt"));
        QFont font3;
        font3.setPointSize(18);
        numerPyt->setFont(font3);

        horizontalLayout_5->addWidget(numerPyt);

        attemptLabel = new QLabel(layoutWidget1);
        attemptLabel->setObjectName(QStringLiteral("attemptLabel"));
        attemptLabel->setFont(font3);

        horizontalLayout_5->addWidget(attemptLabel);

        correctAns = new QLabel(layoutWidget1);
        correctAns->setObjectName(QStringLiteral("correctAns"));
        correctAns->setFont(font3);

        horizontalLayout_5->addWidget(correctAns);

        labelCorrect = new QLabel(HelloForm);
        labelCorrect->setObjectName(QStringLiteral("labelCorrect"));
        labelCorrect->setGeometry(QRect(20, 760, 351, 41));
        labelCorrect->setFont(font);

        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QDialog *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "Hello Qt World", 0));
        check->setText(QApplication::translate("HelloForm", "Check", 0));
        next->setText(QApplication::translate("HelloForm", "Next", 0));
        closeButton->setText(QApplication::translate("HelloForm", "Close", 0));
        question->setText(QApplication::translate("HelloForm", "Enter your name below", 0));
        checkBox_1->setText(QString());
        answer_1->setText(QApplication::translate("HelloForm", "TextLabel", 0));
        checkBox_2->setText(QString());
        answer_2->setText(QApplication::translate("HelloForm", "TextLabel", 0));
        checkBox_3->setText(QString());
        answer_3->setText(QApplication::translate("HelloForm", "TextLabel", 0));
        checkBox_4->setText(QString());
        answer_4->setText(QApplication::translate("HelloForm", "TextLabel", 0));
        checkBox_5->setText(QString());
        answer_5->setText(QApplication::translate("HelloForm", "TextLabel", 0));
        numerPyt->setText(QApplication::translate("HelloForm", "Numer pytania", 0));
        attemptLabel->setText(QApplication::translate("HelloForm", "Attempt:", 0));
        correctAns->setText(QApplication::translate("HelloForm", "correctAns:", 0));
        labelCorrect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
