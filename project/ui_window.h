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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QComboBox *GraphBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(729, 496);
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Remove = new QPushButton(centralWidget);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(10, 320, 80, 25));
        addItem = new QPushButton(centralWidget);
        addItem->setObjectName(QString::fromUtf8("addItem"));
        addItem->setGeometry(QRect(10, 290, 80, 25));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 0, 611, 421));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(6);
        layout->setContentsMargins(11, 11, 11, 11);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setSizeConstraint(QLayout::SetNoConstraint);
        layout->setContentsMargins(0, 0, 0, 0);
        GraphBox = new QComboBox(centralWidget);
        GraphBox->setObjectName(QString::fromUtf8("GraphBox"));
        GraphBox->setGeometry(QRect(8, 80, 81, 22));
        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 21));
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
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
