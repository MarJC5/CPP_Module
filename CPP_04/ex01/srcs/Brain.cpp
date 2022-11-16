/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:08 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &instance) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = instance;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

Brain	&Brain::operator=(Brain const &rhs) {
	if (&rhs != this) // self-assignment check expected
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

std::string	Brain::getIdea(int i) const {
	return (this->_ideas[i]);
}

void	Brain::setIdea(int i, std::string idea) {
	this->_ideas[i] = idea;
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	Brain::printIdeas(void) const {
	for (int i = 0; i < 100; i++)
		std::cout << this->_ideas[i] << std::endl;
}
