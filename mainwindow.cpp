#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_querydialog.h"
#include "editdialog.h"
#include "confirmdialog.h"
#include "querydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(qdlg.ui->queryButton,SIGNAL(clicked()),this,SLOT(SendQueryResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    EditDialog editDialog(this);
    if(editDialog.exec()==1)
        ui->listWidget->addItem(editDialog.name()+"---"+editDialog.number());
}

void MainWindow::on_editButton_clicked()
{
    if(!ui->listWidget->currentItem())
        return;
    QStringList parts = ui->listWidget->currentItem()->text().split("---");
    EditDialog editDialog(this);
    editDialog.setName(parts[0]);
    editDialog.setNumber(parts[1]);

    if(editDialog.exec()==1)
        ui->listWidget->currentItem()->setText(editDialog.name()+"---"+editDialog.number());
}

void MainWindow::on_delButton_clicked()
{
    ConfirmDialog *confirmDialog = new ConfirmDialog(this);
    if(confirmDialog->exec()==1)
        delete ui->listWidget->currentItem();
}

void MainWindow::on_queryButton_clicked()
{
    qdlg.exec();
}

void MainWindow::SendQueryResult()
{
    QString target = qdlg.getTarget();
    QList <QListWidgetItem *> resList = ui->listWidget->findItems(target,Qt::MatchContains);
    qdlg.ShowQueryResult(resList);
    qdlg.exec();
}
