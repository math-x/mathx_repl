#include "../include/repl.h"
bool is_operator(char op) {
	if(op == '+' || op == '-' ||  op == '*' ||  op == '/' ||  op == '^' || op == '%')
		return true;
	return false;
}
