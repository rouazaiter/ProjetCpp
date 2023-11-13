#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fourisseur.h"
#include<QIntValidator>
#include <QMessageBox>
#include <QSqlQueryModel>

#include "fourisseur.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new   QIntValidator(0, 999999, this));
    ui->tab_forni->setModel(f.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_clicked()
{
    fourisseur f;
        int id=ui->le_id->text().toInt();
        QString nom=ui->le_nom->text();
        QString met_pai=ui->le_met->text();
        QString localistion=ui->le_loka->text();
        QString evo_critique=ui->le_evoulition->text();
        QString condi_credit=ui->le_condit->text();
        int tele = ui->le_tele->text().toInt();
        ui->le_id->setText(QString::number(id));
        ui->le_tele->setText(QString::number(tele));
      fourisseur fo(id,nom,evo_critique,localistion ,met_pai, condi_credit, tele);

      bool test1=fo.ajouter();
      QMessageBox msgBox;
    if(test1){
        msgBox.setText("Ajout avec succes");
    ui->tab_forni->setModel(fo.afficher());
    }
    else
        msgBox.setText("echec d'ajout.");
    msgBox.exec();

}

void MainWindow::on_pushButton_clicked()
{
    fourisseur f1;
    f1.setId(ui->le_idsupp->text().toInt());
    bool test=f1.supprimer(f1.getId());
    QMessageBox msgBox;
    if(test){
      msgBox.setText("supprition avec succes");
    ui->tab_forni->setModel(f1.afficher());
    }
    else
      msgBox.setText("echec du supprimer.");
    msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->le_id2->text().toInt();
       QString nom=ui->le_nom2->text();
       QString evo_critique=ui->le_evo2->text();
       QString met_pai=ui->le_met2->text();
       QString condi_credit=ui->le_condi2->text();
       QString localistion=ui->le_loka2->text();

       int tele = ui->le_tele2->text().toInt();
       ui->le_id2->setText(QString::number(id));
       ui->le_tele2->setText(QString::number(tele));
           fourisseur fourni(id,nom,evo_critique,localistion ,met_pai, condi_credit, tele);

           bool test=fourni.modifier();
           if (test)
           {
               QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""click cancel to exit."),QMessageBox::Cancel);
              ui->tab_forni->setModel((fourni.afficher()));
               }
               else
               QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    fourisseur f;
            ui->tab_forni->setModel(f.tri());
}

void MainWindow::on_pushButton_4_clicked()
{
    fourisseur P;
        QString id = ui->le_id_rech->text();

          QSqlQueryModel* res = P.recherche(id);

          if (res->rowCount() > 0) {
              ui->tab_rech->setModel(res);

              QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                       QObject::tr("La recherche a effectuée."), QMessageBox::Ok);

          } else {
              QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                       QObject::tr("Aucun résultat trouvé pour cet ID."), QMessageBox::Ok);
          }
}
