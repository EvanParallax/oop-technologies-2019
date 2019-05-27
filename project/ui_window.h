/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralWidget;
    QPushButton *Remove;
    QPushButton *addItem;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QComboBox *GoalBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *ThemeBox;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QLabel *label_4;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(1005, 496);
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Remove = new QPushButton(centralWidget);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(10, 400, 80, 25));
        addItem = new QPushButton(centralWidget);
        addItem->setObjectName(QString::fromUtf8("addItem"));
        addItem->setGeometry(QRect(10, 370, 80, 25));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 30, 571, 391));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(6);
        layout->setContentsMargins(11, 11, 11, 11);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setSizeConstraint(QLayout::SetNoConstraint);
        layout->setContentsMargins(0, 0, 0, 0);
        GoalBox = new QComboBox(centralWidget);
        GoalBox->setObjectName(QString::fromUtf8("GoalBox"));
        GoalBox->setGeometry(QRect(10, 130, 121, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 121, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 160, 81, 16));
        ThemeBox = new QComboBox(centralWidget);
        ThemeBox->setObjectName(QString::fromUtf8("ThemeBox"));
        ThemeBox->setGeometry(QRect(10, 180, 121, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 10, 71, 16));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(730, 30, 256, 391));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(730, 10, 141, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 270, 81, 23));
        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1005, 21));
        Window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Window);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Window->setStatusBar(statusBar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", nullptr));
        Remove->setText(QApplication::translate("Window", "Remove", nullptr));
        addItem->setText(QApplication::translate("Window", "Add", nullptr));
        label->setText(QApplication::translate("Window", "Selected goal", nullptr));
        label_2->setText(QApplication::translate("Window", "Selected theme", nullptr));
        label_3->setText(QApplication::translate("Window", "Goal scheme", nullptr));
        label_4->setText(QApplication::translate("Window", "Selected theme description", nullptr));
        pushButton->setText(QApplication::translate("Window", "Find way?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
