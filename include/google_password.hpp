#ifndef GOOGLE_PASSWORD_H
#define GOOGLE_PASSWORD_H

#include "usuario.hpp"

#include <map>

class GooglePassword {
public:
    void insert(const std::string& url,
        const std::string& login,
        const std::string& password);

    void remove(const std::string& url);

    void update(const std::string& url,
        const std::string& login,
        const std::string& old_password,
        const std::string& new_password);

    void printPasswords();

private:
    bool checkPassword(const std::string& password) const;

private:
    std::map<std::string, Usuario> m_passwords;
};

#endif