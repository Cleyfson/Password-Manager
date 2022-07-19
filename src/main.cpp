/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include "google_password.hpp"
#include "util.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <usuario.hpp>

int main() {
    GooglePassword passwords;
    std::string command;
    while (std::getline(std::cin, command) && !command.empty()) {
        if (command == "insert") {
            testaInsert(passwords);
        } else if (command == "remove") {
            testaRemove(passwords);
        } else if (command == "update") {
            testaUpdate(passwords);
        }
        command = "";
    }
    passwords.printPasswords();
    return 0;
}