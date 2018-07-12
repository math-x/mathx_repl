#include "../include/repl.h"
/*
 * Function that recursively evaluates the sub-expressions of an
 * expression splitted about outer operators (operators that are 
 * not enclosed within any parenthesis) and then finds the
 * resulting value.
 */
std::string evaluate(std::string x) {
	/* Remove all spaces */
	trim(x);
	/* Vector that stores all the positions of outer operators */
	std::vector<int> ops;
	/* Vector that stores the values of sub-expressions in the order of occurance */
	std::vector<std::string> values;
	/* Count of left and right parenthesis occured at a particular index */
	int num_lef_pars = 0;
	int num_rig_pars = 0;
	/* Handles the unary `-` or `+` by concatenating 0 in front */
	if(x[0] == '-' || x[0] == '+') {
		x.insert(0, "0");
	}
	/* Iterating through the expression */
	for (int i = 0; i < x.size(); ++i) {
		/* On occurance of left parenthesis */
		if(x[i] == '(') {
			num_lef_pars++;
			continue;
		}
		/* On right parenthesis */
		else if(x[i] == ')') {
			num_rig_pars++;
			/* Expression is invalid if `)` exceed `(` */
			if (num_rig_pars > num_lef_pars)
				throw 6;
			continue;
		}
		/* On occurance of operator */
		else if(is_operator(x[i])) {
			/* If the operator if outer */
			if(num_rig_pars == num_lef_pars) {
				ops.push_back(i);
			}
		}
	}

	/* If parentheses count is unequal, expression is invalid */
	if(num_lef_pars != num_rig_pars) {
		throw 6;
	}

	int start = 0;

	/* Iterate through all outer operators */
	for (int i = 0; i < ops.size(); ++i) {
		/* Evaluate the sub-expression on the left of operator and push in `values` vector */
		/* If the sub-expression starts and ends with parenthesis, its an expression */
		if(x[start] == '(' && x[ops[i]-1] == ')')
			values.push_back(evaluate(x.substr(start + 1, ops[i]-start-2)));
		else
		/* Else its constant, variable or function which is handled in parser() function */
			values.push_back(parser(x.substr(start , ops[i]-start)));
		start = ops[i] + 1;
	}

	/* Evaluate last expression in similar way and push in `values` vector */
	if(x[start] == '(' && x[x.size()-1] == ')')
		values.push_back(evaluate(x.substr(start + 1, x.size() - 2 - start)));
	else
		values.push_back(parser(x.substr(start)));

	/* Operators in correct precedence order */
	/* Level 1: Exponentiation(^). This is evaluated right to left */
	for (int i = ops.size() - 1; i >= 0; --i)
	{
		if(x[ops[i]] == '^') {
			values[i] = std::to_string(std::pow(std::stold(values[i]), std::stold(values[i+1])));
			remove_zeroes(values[i]);
			values.erase(values.begin() + i + 1);
			ops.erase(ops.begin() + i);
		}
	}
	/* Level 2: (*,/,%) : Left to right */
	for (int i = 0; i < ops.size(); ++i)
	{
		if(x[ops[i]] == '*') {
			values[i] = std::to_string(std::stold(values[i]) * std::stold(values[i+1]));
			remove_zeroes(values[i]);
			values.erase(values.begin() + i + 1);
			ops.erase(ops.begin() + i);
			i--;
		}
		else if(x[ops[i]] == '/') {
			/* Divide by zero error */
			if (values[i + 1] == "0")
				throw 8;
			values[i] = std::to_string(std::stold(values[i]) / std::stold(values[i+1]));
			remove_zeroes(values[i]);
			values.erase(values.begin() + i + 1);
			ops.erase(ops.begin() + i);
			i--;
		}
		else if(x[ops[i]] == '%') {
			/* % only works for integer values */
			if (type_id(values[i]) == "f" || type_id(values[i+1]) == "f")
				throw 9;
			/* Divide by zero error */
			if (values[i + 1] == "0")
				throw 8;
			values[i] = std::to_string(std::stol(values[i]) % std::stol(values[i+1]));
			remove_zeroes(values[i]);
			values.erase(values.begin() + i + 1);
			ops.erase(ops.begin() + i);
			i--;
		}
	}
	/* Level 3: (+,-) : Left to right */
	for (int i = 0; i < ops.size(); ++i)
	{
		if(x[ops[i]] == '+') {
			values[i] = std::to_string(std::stold(values[i]) + std::stold(values[i+1]));
			remove_zeroes(values[i]);
			values.erase(values.begin() + i + 1);
			ops.erase(ops.begin() + i);
			i--;
		}
		else if(x[ops[i]] == '-') {
			values[i] = std::to_string(std::stold(values[i]) - std::stold(values[i+1]));
			remove_zeroes(values[i]);
			values.erase(values.begin() + i + 1);
			ops.erase(ops.begin() + i);
			i--;
		}
	}

	/* Finally only one value remains */
	std::string result = values[0];
	/* Removes all the excess zeroes after decimal point */
	remove_zeroes(result);
	return result;
}
