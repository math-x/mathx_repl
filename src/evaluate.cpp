#include "../include/repl.h"
std::string evaluate(std::string x) {
	std::vector<int> ops;
	std::vector<std::string> values;
	int num_lef_pars = 0;
	int num_rig_pars = 0;
	if(x[0] == '-' || x[0] == '+') {
		x.insert(0, "0");
	}
	for (int i = 0; i < x.size(); ++i) {
		if(x[i] == '(') {
			num_lef_pars++;
			continue;
		}
		else if(x[i] == ')') {
			num_rig_pars++;
			continue;
		}
		else if(is_operator(x[i])) {
			if(num_rig_pars == num_lef_pars) {
				ops.push_back(i);
			}
		}
	}
	int start = 0;

	for (int i = 0; i < ops.size(); ++i) {
		if(x[start] == '(' && x[ops[i]-1] == ')')
			values.push_back(evaluate(x.substr(start + 1, ops[i]-start-2)));
		else
			values.push_back(parser(x.substr(start , ops[i]-start)));
		start = ops[i] + 1;
	}

	if(x[start] == '(' && x[x.size()-1] == ')')
		values.push_back(evaluate(x.substr(start + 1, x.size() - 2 - start)));
	else
		values.push_back(parser(x.substr(start)));

	std::string result = values[0];
	for (int i = 0; i < ops.size(); ++i)
	{
		if(x[ops[i]] == '+') {
			result = std::to_string(std::stold(result) + std::stold(values[i+1]));
		}
		else if(x[ops[i]] == '-') {
			result = std::to_string(std::stold(result) - std::stold(values[i+1]));
		}
		else if(x[ops[i]] == '*') {
			result = std::to_string(std::stold(result) * std::stold(values[i+1]));
		}
		else if(x[ops[i]] == '/') {
			result = std::to_string(std::stold(result) / std::stold(values[i+1]));
		}
	}
	return result;
}
