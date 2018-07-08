#include "../include/repl.h"

/* Map between variable identifier and value */
std::map<std::string, std::string> variables;

/*
 * Function to check if variable is already declared by the name
 */
bool variable_exists (std::string x) {
	if(variables.find(x) != variables.end())
		return true;
	return false;
}

/*
 * Check if the name is a valid variable name
 */
bool valid_var_name (std::string x) {
	/* First letter should be a alphabet */
	if(!(x[0] >= 'a' && x[0] <= 'z') && !(x[0] >= 'A' && x[0] <= 'Z'))
		return false;
	/* Rest all the characters should be alphabet or number */
	for (int i = 1; i < x.size(); ++i)
	{
		if(!(x[i] >= 'a' && x[i] <= 'z') && !(x[i] >= 'A' && x[i] <= 'Z') && !(x[i] >= '0' && x[i] <= '9'))
		return false;
	}
	return true;
}
