#include "../include/repl.h"

std::string function_map(std::string function, std::string parameter) {

	if(function == "cos") {
		return std::to_string(std::cos(std::stold(parameter)));
	}
	else if (function == "sin") {
		return std::to_string(std::sin(std::stold(parameter)));
	}
	else if (function == "tan") {
		return std::to_string(std::tan(std::stold(parameter)));
	}
	else if(function == "acos") {
		return std::to_string(std::acos(std::stold(parameter)));
	}
	else if (function == "asin") {
		return std::to_string(std::asin(std::stold(parameter)));
	}
	else if (function == "atan") {
		return std::to_string(std::atan(std::stold(parameter)));
	}
	else if(function == "cosh") {
		return std::to_string(std::cosh(std::stold(parameter)));
	}
	else if (function == "sinh") {
		return std::to_string(std::sinh(std::stold(parameter)));
	}
	else if (function == "tanh") {
		return std::to_string(std::tanh(std::stold(parameter)));
	}
	else if(function == "acosh") {
		return std::to_string(std::acosh(std::stold(parameter)));
	}
	else if (function == "asinh") {
		return std::to_string(std::asinh(std::stold(parameter)));
	}
	else if (function == "atanh") {
		return std::to_string(std::atanh(std::stold(parameter)));
	}
	else if (function == "log") {
		return std::to_string(std::log(std::stold(parameter)));
	}
	else if (function == "log10") {
		return std::to_string(std::log10(std::stold(parameter)));
	}
	else if (function == "exp") {
		return std::to_string(std::exp(std::stold(parameter)));
	}
	else if (function == "sqrt") {
		return std::to_string(std::sqrt(std::stold(parameter)));
	}
	else if (function == "floor") {
		return std::to_string(std::floor(std::stold(parameter)));
	}
	else if (function == "ceil") {
		return std::to_string(std::ceil(std::stold(parameter)));
	}
	else if (function == "fabs") {
		return std::to_string(std::fabs(std::stold(parameter)));
	}
	/*
	else if (function == "NEW_FUNCTION") {
		return std::to_string(NEW_FUNCTION(std::stold(parameter)));
	}
	*/
}
