#include "../include/repl.h"
/*
 * Function that intakes function name and parameters (comma seperated) as
 * string and returns the respective function.
 */
std::string function_map(std::string function, std::string parameter) {
	/* Vector that stores the arguments/parameters */
	std::vector<std::string> args;
	int start = 0;

	/* Split the arguments about `,` and push them in `args` vector */
	for (int i = 0; i < parameter.size(); ++i)
	{
		if(parameter[i] == ',') {
			args.push_back(parameter.substr(start, i - start));
			start = i + 1;
		}
	}
	args.push_back(parameter.substr(start));
	int num_args = args.size();

	/* Function map */
	if(function == "cos") {
		if (num_args == 1)
			return std::to_string(std::cos(std::stold(args[0])));
		else
			/* Invalid number of arguments */
			throw 5;
	}
	else if (function == "sin") {
		if (num_args == 1)
			return std::to_string(std::sin(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "tan") {
		if (num_args == 1)
			return std::to_string(std::tan(std::stold(args[0])));
		else
			throw 5;
	}
	else if(function == "acos") {
		if (num_args == 1)
			return std::to_string(std::acos(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "asin") {
		if (num_args == 1)
			return std::to_string(std::asin(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "atan") {
		if (num_args == 1)
			return std::to_string(std::atan(std::stold(args[0])));
		else
			throw 5;
	}
	else if(function == "cosh") {
		if (num_args == 1)
			return std::to_string(std::cosh(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "sinh") {
		if (num_args == 1)
			return std::to_string(std::sinh(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "tanh") {
		if (num_args == 1)
			return std::to_string(std::tanh(std::stold(args[0])));
		else
			throw 5;
	}
	else if(function == "acosh") {
		if (num_args == 1)
			return std::to_string(std::acosh(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "asinh") {
		if (num_args == 1)
			return std::to_string(std::asinh(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "atanh") {
		if (num_args == 1)
			return std::to_string(std::atanh(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "log") {
		if (num_args == 1)
			return std::to_string(std::log(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "log10") {
		if (num_args == 1)
			return std::to_string(std::log10(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "exp") {
		if (num_args == 1)
			return std::to_string(std::exp(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "sqrt") {
		if (num_args == 1)
			return std::to_string(std::sqrt(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "floor") {
		if (num_args == 1)
			return std::to_string(std::floor(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "ceil") {
		if (num_args == 1)
			return std::to_string(std::ceil(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "fabs") {
		if (num_args == 1)
			return std::to_string(std::fabs(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "round") {
		if (num_args == 1)
			return std::to_string(std::round(std::stold(args[0])));
		else
			throw 5;
	}
	else if (function == "pow") {
		if (num_args == 2)
			return std::to_string(std::pow(std::stold(args[0]), std::stold(args[1])));
		else
			throw 5;
	}
	else if (function == "print") {
		if (num_args == 1) {
			if(is_silenced)
				std::cout << args[0] << std::endl;
			return args[0];
		}
		else
			throw 5;
	}
	/*
	Template for new function : 
	else if (function == "NEW_FUNCTION") {
		if (num_args == NUM_OF_ARGS)
			return std::to_string(NEW_FUNCTION(std::stold(args[0])));
		else
			throw 5;
	}
	*/
	else {
		/* Function not found */
		throw 1;
	}
}
