#include "databasesingleton.h"
using namespace std;
DataBaseSingleton * DataBaseSingleton::p_instance;
DataBaseSingletonDestroyer DataBaseSingleton::destroyer;

DataBaseSingletonDestroyer::~DataBaseSingletonDestroyer()
{
    delete p_instance;
}

void DataBaseSingletonDestroyer::initialize(DataBaseSingleton * p)
{
    p_instance = p;
}

DataBaseSingleton::DataBaseSingleton()
{
    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        qDebug() << "Driver SQLite not avalible!";
        return;
    }

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("DataBase.db");

    if(!db.open()){
        qDebug()<<db.lastError().text();
    }

    QSqlQuery query(this->db);
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            login TEXT NOT NULL UNIQUE,
            password TEXT NOT NULL,
            ROLE TEXT NOT NULL DEFAULT user,
            Balance DOUBLE NOT NULL DEFAULT (0),
            TotalBets INTEGER NOT NULL DEFAULT (0),
            TotalWins INTEGER NOT NULL DEFAULT (0)
        )
    )";
    QString createBobr = R"(
        INSERT INTO Users (login, password, ROLE, Balance) VALUES ('bobr', '123123','admin','1000000');
    )";
    QString createChupep = R"(
        INSERT INTO Users (login, password, ROLE, Balance) VALUES ('chupep', '321321','admin','999990');
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Create table error:" << query.lastError().text();
    }
    query.exec(createBobr);
    query.exec(createChupep);
    qDebug() << "DataBase is connected";

}

DataBaseSingleton::~DataBaseSingleton()
{
    db.close();
}

DataBaseSingleton* DataBaseSingleton::getInstance(){
    if(!p_instance){
        p_instance = new DataBaseSingleton();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

QString DataBaseSingleton::auth(QString log, QString pas)
{
    if (!this->db.isOpen()) {
        qDebug() << "DataBase is not opened!";
        return "DataBaseIsNotOpen";
    }
    QSqlQuery query(this->db);

    query.prepare("select ROLE, Balance, TotalBets, TotalWins from users where login = :login and password = :password");
    query.bindValue(":login", log);
    query.bindValue(":password", pas);

    if (!query.exec()) {
        qDebug() << "Query exec error:" << query.lastError().text();
        return "QueryIsNotValid";
    }
    QString role, balance, totalbets, totalwins;
    QString count_of_users = "nan";
    if (query.next()) {
        qDebug() << "User " << log << " exists";
        role = query.value(0).toByteArray();
        balance = query.value(1).toByteArray();
        totalbets = query.value(2).toByteArray();
        totalwins = query.value(3).toByteArray();
        if(role == "admin")
        {
            query.clear();
            QSqlQuery query_admin(this->db);
            query_admin.prepare("select Count(*) from users");
            if (!query_admin.exec()) {
                qDebug() << "Query_admin exec error:" << query_admin.lastError().text();
                return "QueryIsNotValid";
            }
            if(query_admin.next()){count_of_users = query_admin.value(0).toByteArray();}
        }
        return "auth+ " + log + " " + role + " " + balance + " " + totalbets + " " + totalwins + " " + count_of_users;
    } else {
        qDebug() << "User " << log << " is not exists";
        return "auth-";
    }
    return "auth CriticalError";
}

QString DataBaseSingleton::reg(QString log, QString pas)
{
    QSqlQuery query(this->db);
    query.prepare("select login from users where password = :password");
    query.bindValue(":password", pas);
    if(query.exec()){if(query.next()){QString login = query.value(0).toByteArray(); return "reg- " + login;}}

    query.clear();
    if(log!="\t" && log != "" && pas != "\t" && pas != ""){
        query.prepare("INSERT INTO Users (login, password) VALUES (:login, :password);");
        query.bindValue(":password",pas);
        query.bindValue(":login",log);

        if(query.exec()){
            query.clear();
            return "reg+";
        }
        else{
            QString text = query.lastError().text();
            qDebug() << "Query error: " << text;
            if(text[text.indexOf("Users.") + 6] == 'e'){return "emailNotUNIQ";}
            else if(text[text.indexOf("Users.") + 6] == 'l'){return "loginNotUNIQ";}
            return "reg QueryError";
        }
    }
    return "reg CriticalError";
}
QString DataBaseSingleton::toAccount(QString login, QString balance, QString totalBets, QString totalWins)
{
    QSqlQuery query(this->db);
    query.prepare("update Users set Balance = :Balance, TotalBets = :TotalBets, TotalWins = :TotalWins where login = :login;");
    query.bindValue(":login", login);
    query.bindValue(":Balance", balance.toDouble());
    query.bindValue(":TotalWins", totalWins.toInt());
    query.bindValue(":TotalBets", totalBets.toInt());

    if(query.exec()){
        query.clear();
        qDebug() << "Update user account";
        return "account+";
    }
    else{
        QString text = query.lastError().text();
        qDebug() << "Query error: " << text;
        return "account-";
    }
    return "account CriticalError";
}

QString DataBaseSingleton::UserData(QString ID)
{
    QSqlQuery query(this->db);
    QString login, role, balance, totalbets, totalwins, password;
    query.prepare("select login, password, ROLE, Balance, TotalBets, TotalWins from users where id = :id");
    query.bindValue(":id", ID);
    if(query.exec()){
        if(query.next())
        {
            login = query.value(0).toByteArray();
            password = query.value(1).toByteArray();
            role = query.value(2).toByteArray();
            balance = query.value(3).toByteArray();
            totalbets = query.value(4).toByteArray();
            totalwins = query.value(5).toByteArray();
            return "UserData+ " + login + " " + password + " " + role + " " + balance + " " + totalbets + " " + totalwins;
        }
    }
    else{
        QString text = query.lastError().text();
        qDebug() << "Query error: " << text;
        return "UserData-";
    }
    return "UserData CriticalError";
}
