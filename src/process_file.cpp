#include "../include/repl.h"

/*
 * Function to run scripts
 */
void process_file(std::string filename) {
	std::string line;
	std::ifstream script (filename);
	int line_number = 0;
	if (script.is_open())
	{
		try {
			/* Run the script line wise */
			while (getline (script,line))
			{
				++line_number;
				assignments_evaluate(line);
			}
			script.close();
		}
		/* A script should run as long as an error occurs because we dont know if the later
		 * commands depend on the previous ones.
		 */
		catch (int x) {
			std::cout << "Error at line " << line_number << std::endl;
			error_handler(x);
		}
		catch (...) {
			std::cout << "Error: Invalid Expression";
		}

	}
	/* File not found */
	else {
		std::cout << "Error: File not found or already in use" << std::endl;
	}
}
