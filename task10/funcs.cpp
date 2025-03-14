#include "funcs.h"


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