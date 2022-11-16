/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &instance) : Animal(instance)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = instance;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

Dog	&Dog::operator=(Dog const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Dog::makeSound(void) const {
	std::cout << this->_type << ": " << "Woof woof" << std::endl;
}
