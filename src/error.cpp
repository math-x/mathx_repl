#include "../include/repl.h"

void error_handler (int x) {
	if (x == 1) {
		std::cout << "Error: Function not valid";
	}
	else if (x == 2) {
		std::cout << "Error: Variable not declared or invalid";
	}
	else if (x == 3) {
		std::cout << "Error: Variable not declared";
	}
	else if (x == 4) {
		std::cout << "Error: Multiple decimal points in number";
	}
	else {
		std::cout << "Error: Unknown error";
	}
}