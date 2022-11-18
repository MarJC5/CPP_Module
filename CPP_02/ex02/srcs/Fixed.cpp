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

// Addition operator
Fixed Fixed::operator+( Fixed const &rhs ) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

// Substraction operator
Fixed Fixed::operator-( Fixed const &rhs ) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

// Multiplication operator
Fixed Fixed::operator*( Fixed const &rhs ) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

// Division operator
Fixed Fixed::operator/( Fixed const &rhs ) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment operator
Fixed &Fixed::operator++( void ) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

// Decrement operator
Fixed &Fixed::operator--( void ) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

// Min operator
Fixed &Fixed::min( Fixed &a, Fixed &b ) {
	return (a < b) ? a : b;
}

Fixed const &Fixed::min( Fixed const &a, Fixed const &b ) {
	return (a < b) ? a : b;
}

// Max operator
Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	return (a > b) ? a : b;
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b ) {
	return (a > b) ? a : b;
}

// << operator overload
std::ostream &operator<<( std::ostream &o, Fixed const &rhs ) {
	o << rhs.getRawBits();
	return o;
}

/******************************************************************************
 * COMPARISON OPERATORS
 */

// Equal operator
bool Fixed::operator==( Fixed const &rhs ) const {
	return this->_value == rhs.getRawBits();
}

// Not equal operator
bool Fixed::operator!=( Fixed const &rhs ) const {
	return this->_value != rhs.getRawBits();
}

// Greater than operator
bool Fixed::operator>( Fixed const &rhs ) const {
	return this->_value > rhs.getRawBits();
}

// Less than operator
bool Fixed::operator<( Fixed const &rhs ) const {
	return this->_value < rhs.getRawBits();
}

// Greater than or equal operator
bool Fixed::operator>=( Fixed const &rhs ) const {
	return this->_value >= rhs.getRawBits();
}

// Less than or equal operator
bool Fixed::operator<=( Fixed const &rhs ) const {
	return this->_value <= rhs.getRawBits();
}

/******************************************************************************
 * GETTERS / SETTERS
 */

int     Fixed::getRawBits( void ) const {
	return this->_value;
}

void    Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

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
	return ((float)this->_value / (float)(1 << this->_bits));
}

int		Fixed::toInt( void ) const {
	/*
	 * 1 << this->_bits = 2 ^ this->_bits
	 * bit shift right by 8 bits to get the integer part of the fixed point number
	 * and then cast it to int to get rid of the fractional part
	 */
	return (this->_value >> this->_bits);
}



