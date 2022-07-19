#ifndef USUARIO_H
#define USUARIO_H

#include <string>
class Usuario {
public:
    Usuario(const std::string& login, const std::string& password);

    std::string getLogin() const;
    std::string getPassword() const;
    void setLogin(const std::string& login);
    void setPassword(const std::string& password);

private:
    std::string _login;
    std::string _password;
};

#endif