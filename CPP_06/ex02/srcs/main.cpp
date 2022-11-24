/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <unistd.h>
#include <cstdlib>

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << " " << NC << std::endl;
		usleep(usleep_time);
	}
}

/*
 * Generate class A, B or C randomly
 */
Base	*generate(void)
{
	int		random = rand() % 3;
	Base	*base;

	if (random == 0)
		base = new A;
	else if (random == 1)
		base = new B;
	else
		base = new C;
	return (base);
}

/*
 * Identify the class of the object pointed to by the pointer passed as a parameter
 */
void    identify(Base* p)
{
	std::cout << "Identify by pointer: \n" << GREEN;

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	std::cout << NC << std::endl;
}

/*
 * Identify the class of the object passed as reference
 */
void    identify(Base& p)
{
	std::cout << "Identify by reference: \n" ;

	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN << "A" << NC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "A" << NC << std::endl;
	}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << GREEN << "B" << NC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "B" << NC << std::endl;
	}

	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << GREEN << "C" << NC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "C" << NC << std::endl;
	}
}

int main(void)
{
	for (int i = 0; i < 10; i++, tic_tac(100000, 3, NC))
	{
		Base *base = generate();
		Base &ref = *base;
		identify(base); // will return null if not A, B or C
		identify(ref); // will throw exception if not A, B or C (because of dynamic_cast)
		delete base;
	}
	return (0);
}