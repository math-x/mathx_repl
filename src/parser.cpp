#include "../include/repl.h"
/*
 * Sister function of evaluate() which handles constants, variables and
 * function calls in expression.
 */
std::string parser(std::string x) {
	bool is_num = true;
	bool decimal_point = false;
	
	/* Case 1: If the string is a number */
	for (int i = 0; i < x.size(); ++i) {
		/* If period (here decimal point) occurs */
		if(x[i] == '.') {
			if(!decimal_point) {
				/* Its a floating point number */
				decimal_point = true;
			}
			else {
				/* Multiple decimal points */
				throw 4;
			}
		}
		/* If the character is a number */
		else if (x[i] <= '9' && x[i] >= '0') {
			continue;
		}
		/* Else its not a number */
		else {
			is_num = false;
			break;
		}
	}

	/* If number, return as it is */
	if(is_num) {
		remove_zeroes(x);
		return x;
	}

	/* Case 2: If the string is a variable */
	std::string function, parameter;
	size_t left_par = x.find_first_of("(");
	size_t right_par = x.find_last_of(")");

	/* If it doesn't contain parenthesis then its a variable */
	if(left_par == std::string::npos && right_par == std::string::npos) {
		/* If variable exists, return its value */
		if (variable_exists(x)) {
			return variables[x];
		}
		else {
			/* Variable not declared yet */
			throw 3;
		}
	}
	/* Case 3: If the string is function call */
	/* Split the call into function name and parameters */
	function = x.substr(0, left_par);
	parameter = x.substr(left_par + 1, right_par - left_par - 1);
	std::string y;
	int start = 0;
	/* Split the parameters about `,` and evaluate them and again concatenate them comma seperated */
	for (int i = 0; i < parameter.size(); ++i)
	{
		if(parameter[i] == ',') {
			y += evaluate(parameter.substr(start, i - start));
			y += ",";
			start = i + 1;
		}
	}
	/* Last parameter */
	y += evaluate(parameter.substr(start));
	y = function_map(function, y);
	remove_zeroes(y);
	/* Call and return the value */
	return y;
}
