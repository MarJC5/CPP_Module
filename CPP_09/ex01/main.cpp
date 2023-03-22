#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
		return 1;
	}

	try {
		RPN rpn(argv[1]);
		rpn.evaluate();
		double result = rpn.getResult();
		if (!rpn.isError()) {
			std::cout << result << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
