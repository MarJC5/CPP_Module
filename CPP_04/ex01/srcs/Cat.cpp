/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/24 14:06:16 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Cat::Cat(void): Animal(), _brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &instance) : Animal(instance), _brain(new Brain(*instance._brain)) // deep copy
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = instance;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	if (this->_brain)
		delete this->_brain; // delete the brain to avoid memory leaks when the cat is destroyed
}

/******************************************************************************
 * OPERATORS
 */

Cat	&Cat::operator=(Cat const &rhs) {
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
		if (this->_brain)
			delete this->_brain; // free memory for the brain before copying the brain of the rhs cat
		this->_brain = new Brain(*rhs._brain); // copy the brain of the rhs cat
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Cat::makeSound(void) const {
	std::cout << this->_type << ": " << "Meow meow" << std::endl;
}


Brain	*Cat::getBrain(void) const { // return a pointer to the brain of the cat
	return (this->_brain);
}
