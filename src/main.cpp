#include "../include/repl.h"

int main(){
	std::string input;
	std::cout << ">>> ";
	std::cin >> input;
	while(input != "exit") {
		try {
			std::cout << evaluate(input);
		}
		catch (...) {
			std::cout << "Invalid Expression";
		}
		std::cout << std::endl << ">>> ";
		std::cin >> input;
	}
	std::cout << "Exiting!\n";
}
