#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("testr");
db.setUserName("roua");//inserer nom de l'utilisateur
db.setPassword("roua");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

