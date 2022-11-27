/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:46 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:47 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::vector<int> v; // vector of ints
	std::vector<int>::iterator it; // iterator to a vector of int

	for (int i = 0; i < 10; i++)
		v.push_back(i); // fill the vector with 0 to 9 values (dynamic allocation)

	// Will fail and throw an exception because 42 is not in the vector
	try {
		it = easyfind(v, 42);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Will succeed and print the value 2
	try {
		it = easyfind(v, 2);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}