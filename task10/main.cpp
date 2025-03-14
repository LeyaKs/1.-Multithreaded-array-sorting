#include <iostream>
#include "funcs.h"

using std::string;


int main() {
    string expression;
    std::cout << "Enter logical expression: ";
    std::getline(std::cin, expression);

    std::vector<string> variables;
    std::istringstream iss(expression);
    string word;
    while (iss >> word) {
        if (is_variable(word)) {
            bool is_unique = true;
            for (const string& var : variables) {
                if (var == word) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                variables.push_back(word);
            }
        }
    }

    std::unordered_map<std::string, bool> assignment;
    if (find_set(expression, variables, assignment, 0)) {
        std::cout << "Set of values:" << std::endl;
        for (const auto& var : assignment) {
            std::cout << var.first << " = " << (var.second ? "1" : "0") << std::endl;
        }
    } else {
        std::cout << "There is no such set of variables." << std::endl;
    }

    return 0;
}