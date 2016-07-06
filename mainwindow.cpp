#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_querydialog.h"
#include "editdialog.h"
#include "confirmdialog.h"
#include "querydialog.h"

#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    file.setFileName("data.txt");
    //从文件读取
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream readin(&file);
        while(!readin.atEnd())
        {
            QString line = readin.readLine();
            ui->listWidget->addItem(line);
        }
        file.close();
    }

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
    {
        QString line = editDialog.name()+"---"+editDialog.number();
        ui->listWidget->addItem(line);
        this->statusBar()->showMessage("1 item added",2000);
    }
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
    {
        ui->listWidget->currentItem()->setText(editDialog.name()+"---"+editDialog.number());
        this->statusBar()->showMessage("1 item updated",2000);
    }
}

void MainWindow::on_delButton_clicked()
{
    if(!ui->listWidget->currentItem())
        return;

    ConfirmDialog *confirmDialog = new ConfirmDialog(this);
    if(confirmDialog->exec()==1)
    {
        delete ui->listWidget->currentItem();
        this->statusBar()->showMessage("1 item deleted",2000);
    }
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

void MainWindow::on_saveButton_clicked()
{
    //功能：把当前程序中的所有记录保存到data.txt
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        for(int i=0;i<ui->listWidget->count();i++)
        {
            out<<ui->listWidget->item(i)->text()<<endl;
        }
        file.close();
        this->statusBar()->showMessage("File saved",2000);
    }
    else
    {
        this->statusBar()->showMessage("Save failed!",2000);
        return;
    }
}
