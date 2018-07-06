#include "../include/repl.h"

int main(){
	std::string input;
	std::cout << "MathX REPL, version 0.1\nType `exit` to exit\n";
	std::cout << ">>> ";
	std::getline(std::cin, input);
	while(input != "exit") {
		try {
			if(input != "")
				std::cout << assignments_evaluate(input);
		}
		catch (int x) {
			error_handler(x);
		}
		catch (...) {
			std::cout << "Error: Invalid Expression";
		}

		if(input != "")
			std::cout << std::endl << ">>> ";
		else
			std::cout << ">>> ";
		std::getline(std::cin, input);
	}
}
