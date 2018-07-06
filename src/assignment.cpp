#include "../include/repl.h"

std::string assignments_evaluate (std::string x) {
	int len = x.size();
	int end = len - 1;
	bool last_val = true;
	std::string value;
	std::string var_name;
	for (int i = len - 1; i >= 0; --i)
	{
		if(x[i] == '=') {
			if(last_val) {
				value = evaluate(x.substr(i + 1));
				last_val = false;
			}
			else {
				var_name = x.substr(i + 1, end - i);
				std::cout << var_name << std::endl;
				if(variable_exists(var_name) || valid_var_name(var_name))
					variables[var_name] = value;
				else {
					// Variable not valid
					throw 2;
				}
			}
			end = i - 1;
		}
	}
	if(last_val) {
		value = evaluate(x);
	}
	else {
		var_name = x.substr(0, end + 1);
		if(variable_exists(var_name) || valid_var_name(var_name))
			variables[var_name] = value;
		else {
			// Variable not valid
			throw 2;
		}
	}
	return value;
}
