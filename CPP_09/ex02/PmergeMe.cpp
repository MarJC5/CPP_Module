#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>

/*
 * std::vector is implemented as a contiguous array in memory,
 * which means that elements are stored next to each other in memory.
 * This allows for efficient access to elements using pointer arithmetic,
 * and also leads to good cache locality, which is important for performance.
 *
 * std::list is implemented as a doubly-linked list,
 * which means that each element stores a pointer to its neighboring elements.
 * This makes it slower to access individual elements,
 * because you need to follow the pointers to find the desired element.
 *
 * However,
 * std::list can be faster than std::vector for operations that involve adding or removing elements from the middle of the container,
 * because it only requires updating pointers, whereas std::vector may need to shift elements around in memory.
 */

PmergeMe::PmergeMe(int ac, char **av): _size(ac - 1)
{
	if (_size == 0) {
		std::cerr << "Error: no argument provided." << std::endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i <= _size; i++) {
		int num = std::atoi(av[i]);
		if (num <= 0) {
			std::cerr << "Error: invalid argument \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(EXIT_FAILURE);
		}
		_sequence.push_back(num);
	}
}

PmergeMe::~PmergeMe() {}

void PmergeMe::process()
{
	std::cout << "Before: ";
	for (int i = 0; i < _size; i++) {
		std::cout << _sequence[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int> tmp(_size);
	std::copy(_sequence.begin(), _sequence.end(), tmp.begin());
	clock_t begin1 = clock();
	std::sort(tmp.begin(), tmp.end());
	clock_t end1 = clock();
	_firstContainer = "std::vector";

	for (int i = 0; i < _size; i++) {
		_sequence[i] = tmp[i];
	}

	std::list<int> l(_sequence.begin(), _sequence.end());
	clock_t begin2 = clock();
	l.sort();
	clock_t end2 = clock();
	_secondContainer = "std::list";

	std::cout << "After: ";
	for (int i = 0; i < _size; i++) {
		std::cout << _sequence[i] << " ";
	}
	std::cout << std::endl;

	double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with " << _firstContainer << ": " << std::fixed << std::setprecision(6) << elapsed_secs1 * 1000000 << " us" << std::endl;

	double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with " << _secondContainer << ": " << std::fixed << std::setprecision(6) << elapsed_secs2 * 1000000 << " us" << std::endl;
}
