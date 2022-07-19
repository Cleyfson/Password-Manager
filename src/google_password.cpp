#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url, const std::string& login, const std::string& password)
{
    if (checkPassword(password)) {
        m_passwords.insert(std::make_pair(url, Usuario(login, password)));
    }
}

void GooglePassword::remove(const std::string& url)
{
    auto it = m_passwords.find(url);
    if (it != m_passwords.end()) {
        m_passwords.erase(it);
    }
}

void GooglePassword::update(const std::string& url, const std::string& login, const std::string& old_password, const std::string& password)
{
    auto it = m_passwords.find(url);
    if (it != m_passwords.end()) {
        if (it->second.getPassword() == old_password && checkPassword(password)) {
            it->second.setLogin(login);
            it->second.setPassword(password);
        }
    }
}

void GooglePassword::printPasswords()
{
    std::cout << m_passwords.size() << std::endl;
    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++) {
        std::cout << it->first << ": " << it->second.getLogin() << " and " << it->second.getPassword() << std::endl;
    }
}

bool removeSpace(const std::string& password)
{
    for (int i = 0; i < (int)password.length(); i++) {
        if (isspace(password[i])) {
            return true;
        }
    }
    return false;
}

bool GooglePassword::checkPassword(const std::string& password) const
{
    if (password.find("123456") != std::string::npos || password.length() > 50 || password.length() < 6 || removeSpace(password)) {
        return false;
    }

    return true;
}
