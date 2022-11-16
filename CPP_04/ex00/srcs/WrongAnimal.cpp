/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &instance)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = instance;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType()<< ": " << " can't make sound" << std::endl;
}
