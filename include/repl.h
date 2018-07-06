#ifndef MATHX_REPL_
#define MATHX_REPL_

#include<iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

std::string parser(std::string x);
std::string evaluate(std::string x);
bool is_operator(char op);
void trim(std::string &s);
void remove_zeroes(std::string &x);
std::string function_map(std::string function, std::string parameter);
bool variable_exists (std::string x);
bool valid_var_name (std::string x);
std::string assignments_evaluate (std::string x);

extern std::map<std::string, std::string> variables;
#endif