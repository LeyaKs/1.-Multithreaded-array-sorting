#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using std::string;
using std::unordered_map;

bool is_variable(const string& word);

bool count_expression(const string& expression, const unordered_map<string, bool>& variables);

bool find_set(const string& expression, const std::vector<string>& variables, unordered_map<string, bool>& assignment, size_t index);
