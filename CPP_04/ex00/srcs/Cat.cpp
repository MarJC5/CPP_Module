/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &instance) : Animal(instance)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = instance;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

Cat	&Cat::operator=(Cat const &rhs) {
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Cat::makeSound(void) const {
	std::cout << this->_type << ": " << "Meow meow" << std::endl;
}

