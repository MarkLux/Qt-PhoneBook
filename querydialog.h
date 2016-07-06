#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryDialog(QWidget *parent = 0);
    void ShowQueryResult(const QList <QListWidgetItem *> &);
    QString getTarget();
    ~QueryDialog();
    Ui::QueryDialog *ui;

public slots:

private:

};

#endif // QUERYDIALOG_H
