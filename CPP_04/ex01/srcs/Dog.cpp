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

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
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
	delete this->_brain; // free memory for the brain when the dog is destroyed (to avoid memory leaks)
}

/******************************************************************************
 * OPERATORS
 */

Dog	&Dog::operator=(Dog const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
		delete this->_brain; // free memory for the brain before copying the brain of the rhs dog
		this->_brain = new Brain(*rhs.getBrain()); // copy the brain of the rhs dog
	}
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

Brain	*Dog::getBrain(void) const {
	return (this->_brain);  // return the address of the brain
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Dog::makeSound(void) const {
	std::cout << this->_type << ": " << "Woof woof" << std::endl;
}
