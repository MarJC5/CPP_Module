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

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Fixed constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const &instance ) {
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = instance; // *this = instance.operator=(instance);
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Fixed destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	std::cout << "Fixed assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this; // return this.operator=(rhs);
}

Fixed::getRawBits( void ) const {
	std::cout << "Fixed getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed::setRawBits( int const raw ) {
	std::cout << "Fixed setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}