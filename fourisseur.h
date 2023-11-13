#ifndef FOURISSEUR_H
#define FOURISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fourisseur
{
public:
    fourisseur();
    fourisseur(int,QString,QString,QString,QString,QString,int);
    int getId() ;
        QString getNom() ;
        QString getmet_pai() ;
        QString getlocalisation() ;
        QString getevo() ;
        QString getcondit() ;

        int gettele();
        void setId(int );
        void setNom( QString ) ;
        void setmet_pay( QString ) ;
        void setlocalization( QString ) ;
        void setevo( QString ) ;
        void setcondit( QString ) ;

        void settele(int );
        bool ajouter();
        QSqlQueryModel* afficher();
        bool  supprimer (int);
        bool modifier();
        QSqlQueryModel * tri();
   QSqlQueryModel  * recherche(QString );

private:
    int id,tele;
    QString nom,met_pai,localisation,evo_critique,condi_credit;


};

#endif // FOURISSEUR_H
