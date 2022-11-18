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

#include "../inc/AAnimal.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

AAnimal::AAnimal(void) : _type()
{
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &instance): _type(instance.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = instance;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
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

const std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(const std::string &type)
{
	this->_type = type;
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	AAnimal::makeSound(void) const
{
	std::cout << "Can't make sound" << std::endl;
}
