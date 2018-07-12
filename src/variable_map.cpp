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

/*
 * Function to initialise constants
 */
void initialise_constants () {
	variables["pi"] = "3.141592";
	variables["exp"] = "2.718282";
}
/*
 * Function which returns true if the variable is constant
 */
bool is_constant (std::string x) {
	if(x == "pi" ||
		x == "exp")
		return true;
	return false;
}

std::string type_id (std::string x) {
	bool is_num = true;
	bool decimal_point = false;

	/* Check if the string is a number */
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

	/* Return specific type ids */
	if(is_num) {
		if(decimal_point) {
			return "f";
		}
		else {
			return "i";
		}
	}
	else {
		return "e";
	}
}
