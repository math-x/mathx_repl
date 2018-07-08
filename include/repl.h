/*
 * MathX REPL
 * include/repl.h
 * Authors: Kanav Gupta
 */

#ifndef MATHX_REPL_
#define MATHX_REPL_

#include<iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <fstream>

/* parser.cpp */
std::string parser(std::string x);

/* evaluate.cpp */
std::string evaluate(std::string x);

/* tools.cpp */
bool is_operator(char op);
void trim(std::string &s);
void remove_zeroes(std::string &x);
void remove_outer_spaces(std::string &x);

/* function_map.cpp */
std::string function_map(std::string function, std::string parameter);

/* variable_map.cpp */
extern std::map<std::string, std::string> variables;
bool variable_exists (std::string x);
bool valid_var_name (std::string x);
void initialise_constants();
bool is_constant(std::string x);

/* assignment.cpp */
std::string assignments_evaluate (std::string x);

/* error.cpp */
void error_handler (int x);

/* run_repl.cpp */
void run_repl();

/* process_file.cpp */
void process_file(std::string filename);

/* main.cpp */
extern bool is_silenced;

#endif
