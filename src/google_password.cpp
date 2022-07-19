#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string &url,
                            const std::string &login,
                            const std::string &password) {
    /**
       * Lembre-se que as credenciais so podem ser inseridas com as seguintes
       * condicoes:
       * Condicao 1: A senha nao pode ter a seguencia '123456'.
       * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
       * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
       * Condicao 4: A senha nao pode ter caracteres em branco ' '.
       *
       * Exemplos de senhas invalidas:
       * 123456
       * test_123456
       * 123456_test
       * test_123456_test
       * senha test
       */
    if (checkPassword(password)) {
        m_passwords.insert(std::make_pair(url, Usuario(login, password)));
    }
}

void GooglePassword::remove(const std::string &url) {
    auto it = m_passwords.find(url);
    if (it != m_passwords.end()) {
        m_passwords.erase(it);
    }
}

void GooglePassword::update(const std::string &url,
                            const std::string &login,
                            const std::string &old_password,
                            const std::string &password) {
    // TODO: Implemente este metodo
    /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
    auto it = m_passwords.find(url);
    if (it != m_passwords.end()) {
        if (it->second.getPassword() == old_password && checkPassword(password)) {
            it->second.setLogin(login);
            it->second.setPassword(password);
        }
    }
}

void GooglePassword::printPasswords() {
    // TODO: Implemente este metodo
    /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */

    std::cout << m_passwords.size() << std::endl;
    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++) {
        std::cout << it->first << ": " << it->second.getLogin() << " and " << it->second.getPassword() << std::endl;
    }
}

bool whiteCaracthers(const std::string &password) {
    for (int i = 0; i < (int)password.length(); i++) {
        if (isspace(password[i])) {
            return true;
        }
    }
    return false;
}

bool GooglePassword::checkPassword(const std::string &password) const {
    if (password.find("123456") != std::string::npos || password.length() > 50 || password.length() < 6 || whiteCaracthers(password)) {
        return false;
    }

    return true;
}
