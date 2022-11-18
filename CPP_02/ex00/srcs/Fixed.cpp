/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:19:32 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:19:33 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

// Default constructor
Fixed::Fixed( void ) {
	std::cout << "Fixed constructor called" << std::endl;
	this->_value = 0;
}

// Copy constructor
Fixed::Fixed( Fixed const &instance ) {
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = instance;
}

// Destructor
Fixed::~Fixed( void ) {
	std::cout << "Fixed destructor called" << std::endl;
}

/******************************************************************************
 * OPERATORS
 */

// Assignation operator
Fixed &Fixed::operator=( Fixed const &rhs ) {
	this->_value = rhs.getRawBits();
	return *this;
}

/******************************************************************************
 * GETTERS / SETTERS
 */

int Fixed::getRawBits( void ) const {
	return this->_value;
}

void    Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}