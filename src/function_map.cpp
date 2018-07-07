#include "../include/repl.h"

std::string function_map(std::string function, std::string parameter) {

	std::vector<std::string> args;
	int start = 0;

	for (int i = 0; i < parameter.size(); ++i)
	{
		if(parameter[i] == ',') {
			args.push_back(parameter.substr(start, i - start));
			start = i + 1;
		}
	}
	args.push_back(parameter.substr(start));

	if(function == "cos") {
		return std::to_string(std::cos(std::stold(args[0])));
	}
	else if (function == "sin") {
		return std::to_string(std::sin(std::stold(args[0])));
	}
	else if (function == "tan") {
		return std::to_string(std::tan(std::stold(args[0])));
	}
	else if(function == "acos") {
		return std::to_string(std::acos(std::stold(args[0])));
	}
	else if (function == "asin") {
		return std::to_string(std::asin(std::stold(args[0])));
	}
	else if (function == "atan") {
		return std::to_string(std::atan(std::stold(args[0])));
	}
	else if(function == "cosh") {
		return std::to_string(std::cosh(std::stold(args[0])));
	}
	else if (function == "sinh") {
		return std::to_string(std::sinh(std::stold(args[0])));
	}
	else if (function == "tanh") {
		return std::to_string(std::tanh(std::stold(args[0])));
	}
	else if(function == "acosh") {
		return std::to_string(std::acosh(std::stold(args[0])));
	}
	else if (function == "asinh") {
		return std::to_string(std::asinh(std::stold(args[0])));
	}
	else if (function == "atanh") {
		return std::to_string(std::atanh(std::stold(args[0])));
	}
	else if (function == "log") {
		return std::to_string(std::log(std::stold(args[0])));
	}
	else if (function == "log10") {
		return std::to_string(std::log10(std::stold(args[0])));
	}
	else if (function == "exp") {
		return std::to_string(std::exp(std::stold(args[0])));
	}
	else if (function == "sqrt") {
		return std::to_string(std::sqrt(std::stold(args[0])));
	}
	else if (function == "floor") {
		return std::to_string(std::floor(std::stold(args[0])));
	}
	else if (function == "ceil") {
		return std::to_string(std::ceil(std::stold(args[0])));
	}
	else if (function == "fabs") {
		return std::to_string(std::fabs(std::stold(args[0])));
	}
	else if (function == "round") {
		return std::to_string(std::round(std::stold(args[0])));
	}
	/*
	else if (function == "NEW_FUNCTION") {
		return std::to_string(NEW_FUNCTION(std::stold(args[0])));
	}
	*/
	else {
		throw 1;
	}
}
