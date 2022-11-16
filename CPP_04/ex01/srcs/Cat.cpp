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

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &instance): Animal(instance)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = instance;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain; // delete the brain of the cat when the cat is destroyed (to avoid memory leaks)
}

/******************************************************************************
 * OPERATORS
 */

Cat	&Cat::operator=(Cat const &rhs) {
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
		delete this->_brain; // free memory for the brain before copying the brain of the rhs cat
		this->_brain = new Brain(*rhs.getBrain()); // copy the brain of the rhs cat
	}
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

Brain	*Cat::getBrain(void) const {
	return (this->_brain);  // return the address of the brain
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Cat::makeSound(void) const {
	std::cout << this->_type << ": " << "Meow meow" << std::endl;
}

