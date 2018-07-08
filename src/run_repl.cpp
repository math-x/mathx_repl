#include "../include/repl.h"
/*
 * Function to start REPL
 */
void run_repl () {
	std::string input;
	/* Banner */
	std::cout << "MathX REPL, version 0.1\nType `exit` to exit\n";
	std::cout << ">>> ";
	std::getline(std::cin, input);
	while(input != "exit") {
		try {
			if(input != "") {
				if(!is_silenced)
					/* If not silenced, print the return value of every line */
					/* See assignment.cpp */
					std::cout << assignments_evaluate(input);
				else
					/* If sileneced, dont print return value */
					assignments_evaluate(input);
			}
		}
		catch (int x) {
			/* Handle thrown error */
			error_handler(x);
		}
		catch (...) {
			std::cout << "Error: Invalid Expression";
		}

		if(input != "" && !is_silenced)
			std::cout << std::endl << ">>> ";
		else
			std::cout << ">>> ";
		std::getline(std::cin, input);
	}
}