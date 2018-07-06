#include "../include/repl.h"

std::map<std::string, std::string> variables;

bool variable_exists (std::string x) {
	if(variables.find(x) != variables.end())
		return true;
	return false;
}

bool valid_var_name (std::string x) {
	if(!(x[0] >= 'a' && x[0] <= 'z') && !(x[0] >= 'A' && x[0] <= 'Z'))
		return false;

	for (int i = 1; i < x.size(); ++i)
	{
		if(!(x[i] >= 'a' && x[i] <= 'z') && !(x[i] >= 'A' && x[i] <= 'Z') && !(x[i] >= '0' && x[i] <= '9'))
		return false;
	}
	return true;
}
