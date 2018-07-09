#include "../include/repl.h"
/*
 * Inputs an expression and splits the input about `=`
 * Evaluates the last token and assigns the value of all
 * the variables named by remaining tokens
 */
std::string assignments_evaluate (std::string x) {
	int len = x.size();
	int end = len - 1;
	bool last_val = true;
	std::string value;
	std::string var_name;
	/* Iterate through all the characters from the last */
	for (int i = len - 1; i >= 0; --i)
	{
		/* If an `=` is encountered */
		if(x[i] == '=') {
			if(last_val) {
				/* When the first `=` is encounterd, evaluate the value */
				value = evaluate(x.substr(i + 1));
				last_val = false;
			}
			else {
				/* All others are variables */
				var_name = x.substr(i + 1, end - i);
				remove_outer_spaces(var_name);
				/* Check for valid variable name */
				if(valid_var_name(var_name)) {
					if(!is_constant(var_name)) {
						variables[var_name] = value;
					}
					else {
						/* Cannot change value of a constant */
						throw 7;
					}
				}
				else {
					/* Variable not valid */
					throw 2;
				}
			}
			end = i - 1;
		}
	}
	/* Handle the left most variable/expression */
	if(last_val) {
		value = evaluate(x);
	}
	else {
		var_name = x.substr(0, end + 1);
		remove_outer_spaces(var_name);
		if(variable_exists(var_name) || valid_var_name(var_name))
			if(!is_constant(var_name)) {
				variables[var_name] = value;
			}
			else {
				throw 7;
			}
		else {
			/* Variable not valid */
			throw 2;
		}
	}
	return value;
}
