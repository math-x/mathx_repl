#include "../include/repl.h"

void process_file(std::string filename) {
	std::string line;
	std::ifstream script (filename);
	int line_number = 0;
	if (script.is_open())
	{
		try {
			while (getline (script,line))
			{
				++line_number;
				assignments_evaluate(line);
			}
			script.close();
		}
		catch (int x) {
			std::cout << "Error at line " << line_number << std::endl;
			error_handler(x);
		}
		catch (...) {
			std::cout << "Error: Invalid Expression";
		}

	}
	else {
		std::cout << "Error: File not found or already in use" << std::endl;
	}
}