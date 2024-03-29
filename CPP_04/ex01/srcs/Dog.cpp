/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/24 14:05:55 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Dog::Dog(void) : Animal(), _brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const &instance) : Animal(instance), _brain(new Brain(*instance._brain)) // deep copy
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = instance;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	if (this->_brain)
		delete this->_brain; // free the memory of the brain
}

/******************************************************************************
 * OPERATORS
 */

Dog	&Dog::operator=(Dog const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->_type = rhs.getType();
		if (this->_brain)
			delete this->_brain; // free the memory of the brain
		this->_brain = new Brain(*rhs._brain); // copy the brain of the instance
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Dog::makeSound(void) const {
	std::cout << this->_type << ": " << "Woof woof" << std::endl;
}

Brain	*Dog::getBrain(void) const { // return a pointer to the brain of the dog
	return (this->_brain);
}