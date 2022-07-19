#include "google_password.hpp"
#include "util.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <usuario.hpp>

int main()
{
    GooglePassword passwords;
    std::string command;
    while (std::getline(std::cin, command) && !command.empty()) {
        if (command == "insert") {
            Insert(passwords);
        } else if (command == "remove") {
            Remove(passwords);
        } else if (command == "update") {
            Update(passwords);
        }
        command = "";
    }
    passwords.printPasswords();
    return 0;
}