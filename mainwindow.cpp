#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mpMenu = new QMenu("View");
    mpMenu->addAction("Sky");
    mpMenu->addAction("Cloud");
    mpMenu->addAction("Tree");

    ui->menubar->addMenu(mpMenu);

    connect(mpMenu, SIGNAL(triggered(QAction*)), this, SLOT(trigerMenu(QAction*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    ui->labelText->setText("clicked Open");
}


void MainWindow::on_actionSave_triggered()
{
    ui->labelText->setText("clicked Save");
}


void MainWindow::on_actionExit_triggered()
{
    ui->labelText->setText("clicked Exit");
}


void MainWindow::on_actionTest_triggered()
{
    ui->labelText->setText("clicked Test");
}

void MainWindow::trigerMenu(QAction *act)
{
    QString str = QString("View menu is %1").arg(act->text());
    ui->labelText->setText(str);
}

void MainWindow::floatMenu(QAction *act)
{
    QString str = QString("Floating Menu is %1").arg(act->text());
    ui->labelText->setText(str);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::RightButton) {
        QMenu* menu = new QMenu(this);

        menu->addAction(new QAction("Left"));
        menu->addAction(new QAction("Right"));
        menu->addAction(new QAction("Top"));
        menu->addAction(new QAction("Bottom"));

        QPoint point;
        point.setX(event->globalX());
        point.setY(event->globalY());

        menu->popup(point);

        connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(floatMenu(QAction*)));
    }
}

