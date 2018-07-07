#include "../include/repl.h"

bool is_silenced = false;
bool is_file = false;

int main (int argc, char const *argv[]) {

	std::string temp_arg;
	std::string filename;
	for (int i = 1; i < argc; ++i)
	{
		temp_arg = argv[i];
		if (temp_arg[0] != '-') {
			is_file = true;
			filename = temp_arg;
		}
		if (temp_arg == "-s") {
			is_silenced = true;
		}
	}
	
	if (is_file) {
		is_silenced = true;
		process_file(filename);
	}
	else {
		run_repl();
	}

	return 0;
}
