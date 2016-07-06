#include "querydialog.h"
#include "ui_querydialog.h"
#include <QString>

QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
}

QueryDialog::~QueryDialog()
{
    delete ui;
}

void QueryDialog::ShowQueryResult(const QList <QListWidgetItem *> & resList)
{
    if(resList.size()==0)
    {
        ui->resLabel->setText("No results!");
        return;
    }
    else
    {
        QString resNumber = QString::number(resList.size());

        ui->resLabel->setText(resNumber+" item(s) founded:");

        for(int i=0;i<resList.size();i++)
        {
            ui->listWidget->addItem(resList[i]->text());
        }
    }
}

QString QueryDialog::getTarget()
{
    return ui->QueryEdit->toPlainText();
}
