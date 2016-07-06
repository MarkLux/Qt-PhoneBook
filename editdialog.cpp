#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

QString EditDialog::name() const
{
    return ui->nameEdit->toPlainText().trimmed();
}

QString EditDialog::number() const
{
    return ui->numEdit->toPlainText().trimmed();
}

void EditDialog::setName(const QString & name)
{
    ui->nameEdit->setPlainText(name);
}

void EditDialog::setNumber(const QString & num)
{
    ui->numEdit->setPlainText(num);
}
