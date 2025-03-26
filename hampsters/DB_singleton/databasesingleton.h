#ifndef DATABASESINGLETON_H
#define DATABASESINGLETON_H

#include <QVariant> //для хранения различных типов данных в Qt
#include <QDebug> //для вывода отладочной инф-и в консоль
#include <QSqlDatabase> //для работы с базами данных
#include <QSqlQuery> //классы для выполнения SQL-запросов к базе данных
#include <QSqlError> //классы для обработки ошибок, возникающих при работе с БД
#include <QSqlRecord> //классы для доступа к данным, полученным через SQL-запрос

#define DataBaseName "C:/Users/alina/Downloads/DataBase.db" //путь к используемой БД

class DatabaseSingleton;
class DatabaseSingletonDestroyer //отвечает за удаление экземпляра синглота при завершении работы приложения, гарантирует освобождение ресурсов - закрытие соединения с БД
{
private:
    DatabaseSingleton * p_instance; //указатель на экземляр класса DatabaseSingleton, хранящий адрес созданного объекта
public:
    ~DatabaseSingletonDestroyer();
    void initialize(DatabaseSingleton * p); //для инициализации указателя p_instance, вызывается из метода getInstance()
};

class DatabaseSingleton //класс, реализующий паттерн синглтон: существует только один экземпляр этого класса в течение всего времени работы приложения
{
private:
    static DatabaseSingleton * p_instance; //статический указатель на единственный экземпляр класса, хранит адрес созданного объекта. static означает, что эта переменная принадлежит классу, а не отдельным объектам класса (тип одна копия стат переменной разделяется между всеми объекатми).Существует даже тогда, когда ни одного объекта класса еще не создано
    static DatabaseSingletonDestroyer destroyer; //статический объект класса DatabaseSingletonDestroyer, будет уничтожен при завершении работы приложения, и в его деструкторе будет удален экземпляр синглтона. Так же существует на протяжении всего времени выполнения программы
    QSqlDatabase db; //соединение с БД
    bool isUserAuthenticated(int userId);//для проверки аутентификации пользователя
protected:
    DatabaseSingleton(); //приватный конструктор для того, чтобы нельзя было напрямую создать объект этого класса (только через метод getInstance())
    DatabaseSingleton(const DatabaseSingleton&) = delete; //запрет на создание копий объекта. синглтон должен быть единственным
    DatabaseSingleton& operator = (DatabaseSingleton&) = delete; //запрет на присваивание одного объекта другому. синглтон должен быть единственным
    ~DatabaseSingleton(); //закрытие соединения с БД
    friend class DatabaseSingletonDestroyer; //предоставляем DatabaseSingletonDestroyer доступ к приватным членам DatabaseSingleton, чтобы уничтожитель мог удалить экземпляр синглтона
    QStringList getquery(QSqlQuery&); //для выполнения SQL-запросов и получения результатов в виде списка строк, используется внутри класса для упрощения работы с бд
public:
    static DatabaseSingleton* getInstance(); //статический метод для получения единственного экземпляра класса.  Это единственный способ получить доступ к объекту синглтона
    QString auth(QString login, QString password); //авторизация пользователя
    QString Registration(const QString& login, const QString& password); //регистрация пользователя
    QString MyStats(int socket_id); //получение статистики пользователя
    bool isUserAdmin(int socket_id);
    QList<QString> AllStats(int socket_id); //получение статистики по всем пользователям
    bool addWin(int socket_id, double winAmount); //добавление выигрыша
    double getBalance(int socket_id); //получение текущего баланса пользователя
};



#endif // DATABASESINGLETON_H
