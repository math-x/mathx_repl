#include "../include/repl.h"

/*
 * Function which prints error according to error code
 */
void error_handler (int x) {
	if (x == 1) {
		std::cout << "\033[1;31mError\033[0m: Function not valid";
	}
	else if (x == 2) {
		std::cout << "\033[1;31mError\033[0m: Variable not declared or invalid";
	}
	else if (x == 3) {
		std::cout << "\033[1;31mError\033[0m: Variable not declared";
	}
	else if (x == 4) {
		std::cout << "\033[1;31mError\033[0m: Multiple decimal points in number";
	}
	else if (x == 5) {
		std::cout << "\033[1;31mError\033[0m: Incorrect number of arguments";
	}
	else if (x == 6) {
		std::cout << "\033[1;31mError\033[0m: Invalid number or order of parentheses";
	}
	else if (x == 7) {
		std::cout << "\033[1;31mError\033[0m: Constant value cannot be changed";
	}
	else {
		std::cout << "\033[1;31mError\033[0m: Unknown error";
	}

	if(is_silenced)
		std::cout << std::endl;
}