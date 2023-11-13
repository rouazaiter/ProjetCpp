#include "fourisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
fourisseur::fourisseur()
{
    id=0;
    nom=" ";
    evo_critique=" ";
    localisation=" ";
    condi_credit=" ";
    met_pai=" ";

    tele=0;
}
fourisseur::fourisseur(int id,QString nom,QString evo_critique,QString localisation ,QString met_pai,QString condi_credit,int tele)
{
    this->id=id;
    this->nom=nom;
    this->evo_critique=evo_critique;
    this->localisation=localisation;
    this->met_pai=met_pai;
    this->condi_credit=condi_credit;
    this->tele=tele;

}

int fourisseur:: getId() {
    return id;
}
    QString fourisseur:: getNom() {
        return nom;
    }
    QString fourisseur:: getmet_pai()  {
        return met_pai;
    }
    QString fourisseur:: getlocalisation() {
        return localisation;
    }
    QString fourisseur:: getevo() {
        return evo_critique;
    }
    QString fourisseur:: getcondit() {
        return condi_credit;
    }

    int fourisseur:: gettele(){
        return tele;
    }

    void fourisseur:: setId(int newId ){
        id = newId;
    }
    void fourisseur:: setNom( QString newNom ) {
        nom = newNom;
    }
    void fourisseur:: setlocalization( QString newlok ) {
        localisation = newlok;
    }
    void fourisseur:: setmet_pay( QString newmet ) {
        met_pai = newmet;
    }void fourisseur:: setcondit( QString newcondit ) {
       condi_credit = newcondit;
    }
    void fourisseur:: setevo(QString newevo ){
        evo_critique = newevo;
    }
    void fourisseur:: settele(int newtele ) {
        tele = newtele;
    }

    bool fourisseur:: ajouter()
    {

        QSqlQuery query;
        QString id_string=QString::number(id);
        QString tele_string=QString::number(tele);
            query.prepare("INSERT INTO FOURNISSEURS (ID, NOM, TELEPHONE, EVALUATIONS_CRITIQUES ,CONDITIONS_CREDITS,METHODE_PAIEMENT,LOCALISATION) "
                          "VALUES ( :ID, :NOM, :TELEPHONE,:EVALUATIONS_CRITIQUES, :CONDITIONS_CREDITS,:METHODE_PAIEMENT ,:LOCALISATION)");
            query.bindValue(":ID", id_string);
            query.bindValue(":NOM", nom);
            query.bindValue(":EVALUATIONS_CRITIQUES", evo_critique);
            query.bindValue(":CONDITIONS_CREDITS", condi_credit);
            query.bindValue(":METHODE_PAIEMENT", met_pai);
            query.bindValue(":LOCALISATION", localisation);
            query.bindValue(":TELEPHONE", tele_string);
          return  query.exec();

    }
    QSqlQueryModel* fourisseur::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

             model->setQuery("SELECT * FROM FOURNISSEURS");
             model->setHeaderData(0, Qt::Horizontal, QObject ::tr("id_string"));
             model->setHeaderData(1, Qt::Horizontal,QObject :: tr("nom"));
             model->setHeaderData(2, Qt::Horizontal, QObject ::tr("EVALUATIONS_CRITIQUES"));
             model->setHeaderData(3, Qt::Horizontal,QObject :: tr("CONDITIONS_CREDITS"));
             model->setHeaderData(4, Qt::Horizontal,QObject :: tr("METHODE_PAIEMENT"));
             model->setHeaderData(5, Qt::Horizontal,QObject :: tr("LOCALISATION"));
             model->setHeaderData(6, Qt::Horizontal,QObject :: tr("TELEPHONE"));

        return  model;
    }
    bool fourisseur:: supprimer (int id)
    {      QSqlQuery query;

        query.prepare("Delete from FOURNISSEURS where id=:id");
        query.bindValue(":id", id);

      return  query.exec();

    }

    bool fourisseur::modifier()
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        QString tele_string=QString::number(tele);

               query.prepare("update FOURNISSEURS set nom=:nom,TELEPHONE=:TELEPHONE,EVALUATIONS_CRITIQUES=:EVALUATIONS_CRITIQUES,CONDITIONS_CREDITS=:CONDITIONS_CREDITS,METHODE_PAIEMENT=:METHODE_PAIEMENT,LOCALISATION=:LOCALISATION  where id=:ID ");
               query.bindValue(":ID", id_string);
               query.bindValue(":nom", nom);
               query.bindValue(":TELEPHONE", tele_string);
               query.bindValue(":EVALUATIONS_CRITIQUES", evo_critique);
               query.bindValue(":CONDITIONS_CREDITS", condi_credit);
               query.bindValue(":METHODE_PAIEMENT", met_pai);
               query.bindValue(":LOCALISATION", localisation);


               return query.exec();
    }

    QSqlQueryModel * fourisseur::tri()
    {
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT ID, NOM, TELEPHONE, EVALUATIONS_CRITIQUES ,CONDITIONS_CREDITS,METHODE_PAIEMENT,LOCALISATION FROM FOURNISSEURS ORDER BY NOM ASC");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("LOCALISATION"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("EVALUATIONS_CRITIQUES"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("CONDITIONS_CREDITS"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("METHODE_PAIEMENT"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("TELEPHONE"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("id"));

        return model;
    }

    QSqlQueryModel* fourisseur::recherche(QString id) {

        QSqlQueryModel* model = new QSqlQueryModel();

        QSqlQuery query;
        query.prepare("SELECT * FROM FOURNISSEURS WHERE id = :ID");
        query.bindValue(":ID", id);
        query.exec();

        model->setQuery(query);
         return model;
    }




    //update
    //contrôle de saisie




















