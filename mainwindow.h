#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "querydialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void SendQueryResult();

private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_queryButton_clicked();

private:
    Ui::MainWindow *ui;
    QueryDialog qdlg;
};

#endif // MAINWINDOW_H
