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
	this->_value = 0;
}

// Using int constructor
Fixed::Fixed( const int value ) {
	// bit shift left to get the value in the right position
	this->_value = value << this->_bits;
}

// Using float constructor
Fixed::Fixed( const float value ) {
	// bit shift left value * 2^bits to get the value in the right position
	this->_value = (int)(roundf(value * (1 << this->_bits)));
}

// Copy constructor
Fixed::Fixed( Fixed const &instance ) {
	*this = instance;
}

// Destructor
Fixed::~Fixed( void ) {
	return ;
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
	if (this->toFloat() == 0 || rhs.toFloat() == 0)
		return Fixed(0);
	return Fixed(this->toFloat() * rhs.toFloat());
}

// Division operator
Fixed Fixed::operator/( Fixed const &rhs ) const {
	if (rhs.toFloat() == 0)
		return Fixed(0);
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment operator (prefix)
Fixed &Fixed::operator++( void ) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

// Decrement operator (prefix)
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
	o << rhs.toFloat();
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
	if (this->_value == 0)
		return 0;
	return ((float)this->_value / (float)(1 << this->_bits));
}

int		Fixed::toInt( void ) const {
	if (this->_value == 0)
		return 0;
	return (this->_value >> this->_bits);
}



