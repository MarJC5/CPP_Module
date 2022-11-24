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

// Using int constructor
Fixed::Fixed( const int value ) {
	std::cout << "Fixed constructor called" << std::endl;
	this->_value = value << this->_bits;
}

// Using float constructor
Fixed::Fixed( const float value ) {
	std::cout << "Fixed constructor called" << std::endl;
	this->_value = (int)(roundf(value * (1 << this->_bits)));
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

Fixed &Fixed::operator=( Fixed const &rhs ) {
	this->_value = rhs.getRawBits();
	return *this;
}

/******************************************************************************
 * GETTERS / SETTERS
 */

int     Fixed::getRawBits( void ) const {
	return this->_value; // return the raw value of the fixed point value
}

void    Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

std::ostream &operator<<( std::ostream &o, Fixed const &rhs ) { // << operator overload
	o << rhs.getRawBits();
	return o;
}

float	Fixed::toFloat( void ) const {
	/*
	 * we use the left shift operator to multiply by 2 to the power of _bits (here 8)
	 * and we cast the result to float to avoid integer division
	 *
	 * 1.0f = 1.0 * 2^0
	 * 0.5f = 1.0 * 2^-1
	 * 0.25f = 1.0 * 2^-2
	 * 0.125f = 1.0 * 2^-3
	 * 0.0625f = 1.0 * 2^-4
	 * ... etc
	 */
	if (this->_value == 0)
		return 0;
	return ((float)this->_value / (float)(1 << this->_bits));
}

int		Fixed::toInt( void ) const {
	/*
	 * 1 << this->_bits = 2 ^ this->_bits
	 * bit shift right by 8 bits to get the integer part of the fixed point number
	 * and then cast it to int to get rid of the fractional part
	 */
	if (this->_value == 0)
		return 0;
	return (this->_value >> this->_bits);
}



