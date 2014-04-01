#ifndef DIALOG_H
#define DIALOG_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    MainWindow *newWindow;
    QSqlTableModel *model;
    ~Dialog();
    
private slots:
    void on_clear_clicked();

    void on_login_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase myDb;

};

#endif // DIALOG_H
