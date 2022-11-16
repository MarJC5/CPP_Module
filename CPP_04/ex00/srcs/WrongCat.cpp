/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &instance) : WrongAnimal(instance)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = instance;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

WrongCat	&WrongCat::operator=(WrongCat const &rhs) {
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	WrongCat::makeSound(void) const {
	std::cout << this->_type << ": "  << "Wrong Meow meow" << std::endl;
}

