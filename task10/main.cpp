#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using std::string;
using std::unordered_map;

bool is_variable(const string& word) {
    if (word == "AND" || word == "OR" || word == "NOT") {
        return false;
    }
    for (char ch : word) {
        if (!isalpha(ch) && !isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool count_expression(const string& expression, const unordered_map<string, bool>& variables) {
    std::istringstream iss(expression);
    string word;
    bool result = false;
    bool curr_value = false;
    string last_op;

    while (iss >> word) {
        if (word == "AND" || word == "OR" || word == "NOT") {
            last_op = word;
        } else {
            if (variables.find(word) == variables.end()) {
                std::cerr << "Error: undefined variable " << word << std::endl;
                return false;
            }
            curr_value = variables.at(word);

            if (last_op.empty()) {
                result = curr_value;
            } else if (last_op == "NOT") {
                result = !curr_value;
                last_op.clear();
            } else if (last_op == "AND") {
                result = result && curr_value;
                last_op.clear();
            } else if (last_op == "OR") {
                result = result || curr_value;
                last_op.clear();
            }
        }
    }

    return result;
}


bool find_set(const string& expression, const std::vector<string>& variables, unordered_map<string, bool>& assignment, size_t index) {
    if (index == variables.size()) {
        return count_expression(expression, assignment);
    }

    assignment[variables[index]] = false;
    if (find_set(expression, variables, assignment, index + 1)) {
        return true;
    }

    assignment[variables[index]] = true;
    if (find_set(expression, variables, assignment, index + 1)) {
        return true;
    }

    return false;
}

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