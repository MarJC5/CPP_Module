#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <cctype>

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
		for (size_t j = 0; j < strlen(av[i]); j++){
			if (!std::isdigit(av[i][j])) {
				std::cerr << "Error: invalid argument \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		int num = std::atoi(av[i]);
		if (num <= 0) {
			std::cerr << "Error: invalid argument \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(EXIT_FAILURE);
		}
		_sequence.push_back(num);
		_vec.push_back(num);
		_list.push_back(num);
	}
}

PmergeMe::~PmergeMe() {}

void PmergeMe::process()
{	
	// Inital
	std::cout << "Before: ";
	for (int i = 0; i < _size; i++) {
		std::cout << _sequence[i] << " ";
	}
	std::cout << std::endl;

	// Vector
	_firstContainer = "std::vector";
	clock_t begin1 = clock();
	std::sort(_vec.begin(), _vec.end());
	clock_t end1 = clock();

	// List
	_secondContainer = "std::list";
	clock_t begin2 = clock();
	_list.sort();
	clock_t end2 = clock();

	// Result sorted
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vec.begin(); it!= _vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with " << _firstContainer << ": " << elapsed_secs1 * 100 << " us" << std::endl;

	double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with " << _secondContainer << ": " << elapsed_secs2 * 100 << " us" << std::endl;
}