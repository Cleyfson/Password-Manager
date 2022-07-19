#include "usuario.hpp"

Usuario::Usuario(const std::string &login, const std::string &password) {
    this->_login = login;
    this->_password = password;
}

std::string Usuario::getLogin() const {
    return this->_login;
}

std::string Usuario::getPassword() const {
    return this->_password;
}

void Usuario::setPassword(const std::string &password) {
    this->_password = password;
}

void Usuario::setLogin(const std::string &login) {
    this->_login = login;
}