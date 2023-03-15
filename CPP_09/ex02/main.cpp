#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pm(ac, av);
	pm.process();

	return EXIT_SUCCESS;
}
