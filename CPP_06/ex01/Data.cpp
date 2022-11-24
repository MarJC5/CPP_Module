/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Data::Data(void)
{
	return ;
}

Data::Data(Data const &instance) : _value(instance.getValue())
{
	return ;
}

Data::~Data()
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Data &Data::operator=(Data const & rhs)
{
	if (this != &rhs)
		this->_value = rhs.getValue();
	return (*this);
}


/******************************************************************************
 * GETTERS / SETTERS
 */

std::string	Data::getValue(void) const
{
	return (this->_value);
}

void	Data::setValue(std::string value)
{
	this->_value = value;
}

/* ************************************************************************** *
 *  FUNCTIONS
 */

/*
 * We reinterpret_cast when we receive a void* from a function and we want to convert it to a pointer of a specific type.
 *
 * reinterpret_cast is a cast operator that converts any pointer type to any other pointer type, even of unrelated classes.
 * The operation result is a simple binary copy of the value from one pointer to the other.
 * All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.
 *
 * To be simple, reinterpret_cast is used to convert a pointer to any other pointer type.
 * It allows us to convert a pointer to a pointer of a different type and then back again to its original type.
 */

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
