#include "MySQLConnector.h"

using namespace std;

MySQLConnector::MySQLConnector(): driver(nullptr), connection(nullptr) {
    try {
        // Se intenta crear una instancia del controlador de MySQL
        this->driver = sql::mysql::get_mysql_driver_instance();

        // Se intenta establecer la conexión a la base de datos
        this->connection = driver->connect(this->host, this->user, this->password);
        this->connection->setSchema(this->database);
    } catch (sql::SQLException& e) {
        delete this->connection;
        this->connection = nullptr;
        this->driver = nullptr;
        cout << REDB "Error de MySQL: " << e.getErrorCode() << " - " << e.what() << "" NC << endl << endl;
    }
}

sql::Connection* MySQLConnector::getConnection() {
    return this->connection;
}

MySQLConnector::~MySQLConnector() {
    delete this->connection;
}
 
 
