#include "../include/repl.h"

int main(){
	std::string input;
	std::cout << "MathX REPL, version 0.1\nType `exit` to exit\n";
	std::cout << ">>> ";
	std::getline(std::cin, input);
	while(input != "exit") {
		try {
			std::cout << evaluate(input);
		}
		catch (...) {
			std::cout << "Invalid Expression";
		}
		std::cout << std::endl << ">>> ";
		std::getline(std::cin, input);
	}
}
