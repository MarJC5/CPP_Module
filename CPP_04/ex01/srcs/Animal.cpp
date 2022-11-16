/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &instance)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = instance;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

Animal	&Animal::operator=(Animal const &rhs)
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

std::string	Animal::getType(void) const
{
	return (this->_type);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << ": " << " can't make sound" << std::endl;
}
