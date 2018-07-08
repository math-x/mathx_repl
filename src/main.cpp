#include "../include/repl.h"

bool is_silenced = false;
bool is_file = false;

int main (int argc, char const *argv[]) {

	/* Parsing command line arguments */
	std::string temp_arg;
	std::string filename;

	/* Iterating through all arguements */
	for (int i = 1; i < argc; ++i)
	{
		temp_arg = argv[i];

		/* If the arguement's first character is `-` then its an option else its a filename */
		if (temp_arg[0] != '-') {
			is_file = true;
			filename = temp_arg;
		}
		/* Silenced mode */
		if (temp_arg == "-s") {
			is_silenced = true;
		}
	}

	initialise_constants();
	if (is_file) {
		/* So that errors are seperated by endline (see error.cpp) */
		is_silenced = true;
		/* Process the file */
		process_file(filename);
	}
	else {
		/* If no file is specified then run the REPL */
		run_repl();
	}

	return 0;
}
