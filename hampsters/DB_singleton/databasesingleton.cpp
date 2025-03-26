#include "databasesingleton.h"

//определение статических переменных для выделения для них памяти (так надо для статических членов класса)
DatabaseSingleton* DatabaseSingleton::p_instance;
DatabaseSingletonDestroyer DatabaseSingleton::destroyer;

DatabaseSingletonDestroyer::~DatabaseSingletonDestroyer()
{
    delete p_instance; //освобождаем память - удаляем объект, на который указывает указатель
}
void DatabaseSingletonDestroyer::initialize(DatabaseSingleton * p)
{
    p_instance = p; //присваиваем указателю адрес предаваемого объекта
}

bool DatabaseSingleton::isUserAuthenticated(int userId) {
    QSqlQuery checkAuthQuery(this->db);
    checkAuthQuery.prepare("SELECT IsAuth FROM User WHERE id = :userId");
    checkAuthQuery.bindValue(":userId", userId);

    if (!checkAuthQuery.exec()) {
        qDebug() << "Failed to check auth: " << checkAuthQuery.lastError().text();
        return false;
    }

    if (checkAuthQuery.next()) {
        return checkAuthQuery.value(0).toBool(); // возвращаем значение IsAuth
    } else {
        qDebug() << "User not found during auth check.";
        return false; // пользователь не найден -> считаем, что не аутентифицирован
    }
}

DatabaseSingleton::DatabaseSingleton()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //для работы работы с SQLite, не утсановлен драйвер SQLite -> ошибка
    db.setDatabaseName(DataBaseName); //устанавливает имя БД, с которой будет работать соединение. DataBaseName определяется в заголовочном файле

    if (!db.open()) //открывает соединение с БД
        qDebug()<<db.lastError().text(); //если не удалось открыть соединение -> вывод сообщения об ошибке в консоль
}
DatabaseSingleton::~DatabaseSingleton()
{
    db.close(); //закрывает соединение с БД
}
DatabaseSingleton* DatabaseSingleton::getInstance(){
    if (!p_instance) //проверка, был ли уде создан экземляр
    {
        p_instance = new DatabaseSingleton(); //если экземпляр еще не создан -> создает его
        destroyer.initialize(p_instance); //инициализирует объект destroyer указателем на созданный экземпляр класса
    }
    return p_instance; //возвращает указатель на экземпляр класса
}

QStringList DatabaseSingleton::getquery(QSqlQuery& query)
{
    query.exec(); //выполняет SQL-запрос
    QStringList res; //список строк для харнения результатов запроса
    QSqlRecord rec = query.record(); //получение описание записи(кол-во столбцов, имена столбцов и т.д.)
    int cols = rec.count(); //количество столбцов в записи

    while (query.next()) { //перебор всех записей, полученных в результате запроса
        QString row_str; //строка для хранения данных одной записи
        for (int i = 0; i < cols; ++i) { //перебор всех стобцов записи
            row_str += query.value(i).toString(); //получение значения и добавление в строку
            if (i < cols - 1) { //если не послений стобец -> добавить разделитель между значениями столбцов
                row_str += "//";
            }
        }
        res.append(row_str); //добавление строки с данными записи в список результатов
    }
    return res;
}

QString DatabaseSingleton::auth(QString login, QString password){
    QSqlQuery querry(this->db); //создание объекта для выполнения запроса
    querry.prepare("SELECT id, Login, Password, Role FROM User WHERE Login = :login AND Password = :password"); // подгтовка запроса с праметрами - защита от инъекций
    querry.bindValue(":password", password); //привязывает знач переменной password к соответсвтующему параметру в запрос
    querry.bindValue(":login", login); //аналогично паролю

    QStringList res = this->getquery(querry);  //выполнение запроса и получение разультата в виде списка строк

    if (res.size() > 0){ //если в результате запроса получены запис (пользователь найден)
        QStringList userData = res[0].split("//"); //разделение строку с данными пользователя
        QString role = userData[3]; //получение роли пользователя
        QString id = userData[0]; //получение id пользователя

        // устанавливаем IsAuth = 1 и LastLogin = now()
        QSqlQuery updateAuthQuery(this->db);
        updateAuthQuery.prepare("UPDATE User SET IsAuth = 1, LastLogin = DATETIME('now') WHERE id = :id");
        updateAuthQuery.bindValue(":id", id.toInt()); // Преобразуем id в int
        if (!updateAuthQuery.exec()) {
            qDebug() << "Failed to update IsAuth: " << updateAuthQuery.lastError().text();
            return "auth-errror";
        }

        return "auth+&" + login + "&" + role + "&" + id; // успешная авторизация
    }
    else {
        return "auth-"; //неудачная авторизация
    }
};

QString DatabaseSingleton::Registration(const QString& login, const QString& password)
{
    QSqlQuery checkingLog(this->db); //создание объекта для выполнения запроса
    checkingLog.prepare("SELECT COUNT(*) FROM User WHERE Login = :login");  // для проверки существования пользователя с таким логином. подгтовка запроса с праметрами - защита от инъекций.
    checkingLog.bindValue(":login", login); //привязываем значение к параметру в запросе

    QStringList checkResult = getquery(checkingLog); //выполнение запроса и получение результата

    if (checkResult.size() > 0) { //если запрос вернул результат (пользователь с таким логином уже существует или нет)
        QString countStr = checkResult[0]; //получение строки с количеством пользователей с таким логином.
        int count = countStr.toInt(); //преобразование строки в число

        if (count > 0) { //пользователь с таким логином существует -> выводим ошибку
            qDebug() << "Ошибка: Пользователь с логином " << login << " уже существует.";
            return "registration-exists";
        }
    } else { //не удалось выполнить запрос проверки существования пользователя -> выводим ошибку
        qDebug() << "Ошибка: Не удалось выполнить запрос проверки существования пользователя.";
        return "registration-error";
    }

    //логин уникальны -> можно продолжать регистрацию
    checkingLog.prepare("INSERT INTO User (Login, Password, Role) VALUES (:login, :password, 'user')"); // changed
    checkingLog.bindValue(":login", login);
    checkingLog.bindValue(":password", password);
    if (!checkingLog.exec()) { //выполнение запроса
        qDebug() << "Ошибка при регистрации:" << checkingLog.lastError().text(); //сообщение об ошибке, неудачная регистрация
        return "registration-";
    } else {
        return "registration+";
    }
}

QString DatabaseSingleton::MyStats(int socket_id)
{
    //проверка авторизован ли пользователь
    if (!isUserAuthenticated(socket_id)) {
        qDebug() << "User not authenticated.";
        return "stats-unauthenticated";
    }

    QSqlQuery query(this->db); //создание объекта для выполнения запроса
    query.prepare("SELECT Login, Balance, TotalBets, TotalWins FROM User WHERE id = :socket_id");
    query.bindValue(":socket_id", socket_id);

    QStringList res = this->getquery(query);

    if (res.size() > 0) { //если вернул запрос (нашли пользователя)
        QStringList stats = res[0].split("//");
        return "stats+&" + stats[0] + "&" + stats[1] + "&" + stats[2] + "&" + stats[3]; // login, balance, totalBets, totalWins
    } else {
        return "stats-";
    }
}

bool DatabaseSingleton::isUserAdmin(int socket_id) {
    QSqlQuery checkAdminQuery(this->db);
    checkAdminQuery.prepare("SELECT Role FROM User WHERE id = :socket_id");
    checkAdminQuery.bindValue(":socket_id", socket_id);

    if (!checkAdminQuery.exec()) {
        qDebug() << "Failed to check role: " << checkAdminQuery.lastError().text();
        return false;
    }

    if (checkAdminQuery.next()) {
        QString role = checkAdminQuery.value(0).toString();
        return (role == "admin"); //true, если роль пользователя - "admin"
    } else {
        qDebug() << "User not found during role check.";
        return false; //пользователь не найден
    }
}

QList<QString> DatabaseSingleton::AllStats(int socket_id = NULL)
{
    //проверка авторизован ли пользователь
    if (!isUserAuthenticated(socket_id)) {
        qDebug() << "User not authenticated.";
        return QList<QString>{"allstats-unauthenticated"};
    }
    //проверка является ли пользователь администратором
    if (!isUserAdmin(socket_id)) {
        qDebug() << "User is not an admin.";
        return QList<QString>{"allstats-unauthorized"};
    }
    QSqlQuery query(this->db);
    query.prepare("SELECT id, Login, Role, Balance, TotalBets, TotalWins, LastLogin FROM User");

    QStringList res = this->getquery(query);
    if (!res.isEmpty()) {
        return QList<QString>(res); //возвращаем список строк со статистикой
    } else {
        return QList<QString>{"allstats-"}; //возвращаем список с кодом отсутствия данных
    }
}

bool DatabaseSingleton::addWin(int socket_id, double winAmount) {
    if (!isUserAuthenticated(socket_id)) {
        qDebug() << "User not authenticated.";
        return false;
    }

    if (winAmount <= 0) {
        qDebug() << "Invalid win amount.";
        return false;
    }

    QSqlQuery updateBalanceQuery(this->db);
    updateBalanceQuery.prepare("UPDATE User SET Balance = Balance + :winAmount, TotalWins = TotalWins + 1 WHERE id = :socket_id");
    updateBalanceQuery.bindValue(":winAmount", winAmount);
    updateBalanceQuery.bindValue(":socket_id", socket_id);

    if (!updateBalanceQuery.exec()) {
        qDebug() << "Failed to update balance: " << updateBalanceQuery.lastError().text();
        return false;
    }

    return true;
}

double DatabaseSingleton::getBalance(int socket_id) {
    if (!isUserAuthenticated(socket_id)) {
        qDebug() << "User not authenticated.";
        return -1; //для неавторизованного пользователя
    }
    QSqlQuery query(this->db);
    query.prepare("SELECT Balance FROM User WHERE id = :socket_id");
    query.bindValue(":socket_id", socket_id);

    if (!query.exec()) {
        qDebug() << "Failed to get balance: " << query.lastError().text();
        return -1;
    }

    if (query.next()) {
        return query.value(0).toDouble();
    } else {
        qDebug() << "User not found.";
        return -1;
    }
}
