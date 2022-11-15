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

/*** EX00 ***/
Fixed::Fixed( void ) {
	std::cout << "Fixed constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed( Fixed const &instance ) {
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = instance; // *this = instance.operator=(instance);
}

Fixed::~Fixed( void ) {
	std::cout << "Fixed destructor called" << std::endl;
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	this->_value = rhs.getRawBits();
	return *this; // return this.operator=(rhs);
}

int     Fixed::getRawBits( void ) const {
	return this->_value;
}

void    Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

/*** EX01 ***/

