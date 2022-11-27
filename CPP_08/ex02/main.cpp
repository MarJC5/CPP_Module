/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:25:09 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

# define GREEN    "\033[1;32m"
# define RED      "\033[1;31m"
# define ORANGE   "\033[1;33m"
# define CYAN     "\033[1;36m"
# define GREY     "\033[1;37m"
# define NC       "\033[0m"

int main(void) {
	{
		std::cout << ORANGE << "---------------------------------" << std::endl;
		std::cout << "Stack without iterator" << std::endl;
		std::cout << "---------------------------------" << NC << std::endl;
		MutantStack<float> mstack;

		mstack.push(64.0f);
		mstack.push(5.0f);
		mstack.push(17.0f);
		mstack.push(42.0f);
		mstack.push(25.0f);

		for (int i = 0; i < 5; i++) {
			std::cout << mstack.top() << std::endl; // print the top of the stack
			mstack.pop(); // remove the top element of the stack
		}
	}

	std::cout << std::endl;

	{
		std::cout << CYAN << "---------------------------------" << std::endl;
		std::cout << "Stack with iterator" << std::endl;
		std::cout << "---------------------------------" << NC << std::endl;

		MutantStack<std::string> mstack;

		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");

		MutantStack<std::string>::iterator it = mstack.begin(); // create an iterator to the beginning of the stack
		MutantStack<std::string>::iterator ite = mstack.end(); // end() is the last element of the stack

		for (; it != ite; it++) {
			std::cout << *it;
			if (it != ite)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "---------------------------------" << std::endl;
		std::cout << "Main from subject" << std::endl;
		std::cout << "---------------------------------" << NC << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop(); // remove the top element of the stack

		std::cout << "size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	return (0);
}