#include "../include/repl.h"
/*
 * Function that returns `true` if the parameter is an operator
 */
bool is_operator(char op) {
	if(op == '+' || op == '-' ||  op == '*' ||  op == '/' ||  op == '^' || op == '%' || op == '^')
		return true;
	return false;
}
/*
 * Function to remove all the whitespaces (` `) in a string
 */
void trim(std::string &s) {
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if(s[i] == ' ') {
			s.erase(i,1);
			i--;
			len--;
		}
	}
}
/*
 * Function to remove all the unneccesary `0` and `.` (if not useful)
 * `2.36600` -> `2.366`
 * `3.00000` -> `3`
 */
void remove_zeroes(std::string &x) {
	int len = x.length() - 1;
	if(x.find(".") != std::string::npos) {
		while(x[len] == '0') {
			x.erase(len,1);
			len--;
		}
		if(x[len] == '.') {
			x.erase(len,1);
			len--;
		}
	}
}
/*
 * Function to remove the whitespaces from left and right of the string
 */
void remove_outer_spaces(std::string &x) {
	while (x[0] == ' ') {
		x.erase(0,1);
	}
	while(x[x.size() - 1] == ' ') {
		x.erase(x.size() - 1, 1);
	}
}
