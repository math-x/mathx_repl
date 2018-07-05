#include "../include/repl.h"
bool is_operator(char op) {
	if(op == '+' || op == '-' ||  op == '*' ||  op == '/' ||  op == '^' || op == '%')
		return true;
	return false;
}
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
