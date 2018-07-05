#include "../include/repl.h"

std::string parser(std::string x) {
	bool is_num = true;
	bool decimal_point = false;
	
	for (int i = 0; i < x.size(); ++i) {
		if(x[i] == '.') {
			if(!decimal_point) {
				decimal_point = true;
			}
			else {
				printf("Error!\n");
				exit(1);
			}
		}
		else if (x[i] <= '9' && x[i] >= '0') {
			continue;
		}
		else {
			is_num = false;
			break;
		}
	}

	if(is_num) {
		return x;
	}

	std::string function, parameter;
	size_t left_par = x.find_first_of("(");
	size_t right_par = x.find_last_of(")");

	function = x.substr(0, left_par);
	parameter = x.substr(left_par + 1, right_par - left_par - 1);
	std::string y = evaluate(parameter);
	return function_map(function, y);
}
