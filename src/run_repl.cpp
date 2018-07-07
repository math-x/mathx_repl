#include "../include/repl.h"

void run_repl () {
	std::string input;
	std::cout << "MathX REPL, version 0.1\nType `exit` to exit\n";
	std::cout << ">>> ";
	std::getline(std::cin, input);
	while(input != "exit") {
		try {
			if(input != "") {
				if(!is_silenced)
					std::cout << assignments_evaluate(input);
				else
					assignments_evaluate(input);
			}
		}
		catch (int x) {
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