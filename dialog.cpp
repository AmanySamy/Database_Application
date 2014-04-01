#include "dialog.h"
#include "ui_dialog.h"

#define path_DB "D:/QT/Qt program/Database_Application/Admins.sqlite"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    newWindow = new MainWindow;
    myDb = QSqlDatabase::addDatabase("QSQLITE");
    myDb.setDatabaseName(path_DB);
    QFileInfo file(path_DB);
    if(file.isFile())
    {
        if(myDb.open())
        {
            ui->status->setText("[+] Connection to Database File sucucess :)");
        }
    }
    else
    {
        ui->status->setText("[!] Database File is not Exist :( ");
    }

    connect(ui->login,SIGNAL(clicked()),this,SLOT(on_login_clicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_clear_clicked()
{
    ui->txtuser->clear();
    ui->txtpass->clear();
}

void Dialog::on_login_clicked()
{
    QString Username,Password;
    Username = ui->txtuser->text();
    Password = ui->txtpass->text();

    if(!myDb.open())
    {
        qDebug()<<"Not possible to connect to Database";
        return;
    }

    QSqlQuery query;
    query.prepare( "SELECT * FROM admins WHERE user_name=? AND password=?" );
    query.bindValue( 0, ui->txtuser->text() );
    query.bindValue( 1, ui->txtpass->text() );
    if(query.exec())
    {
        if(query.next())
        {

          ui->status->setText("[+] Vaild Username and Password");

          this->model = new QSqlTableModel();
          model->setTable("admins");
          model->select();
          newWindow->ui->tableView->setModel(model);
          newWindow->show();


        }else
        {
            ui->status->setText("error");
            qDebug()<<"error" << query.lastError().text();

        }
    }
}




