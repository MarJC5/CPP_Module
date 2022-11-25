/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/25 19:36:32 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarTypes.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

ScalarTypes::ScalarTypes(): _str()
{
	return ;
}

ScalarTypes::ScalarTypes(std::string value): _str(value)
{
	// check input type
	this->checkType();
	return ;
}

ScalarTypes::ScalarTypes(ScalarTypes const &instance)
{
	*this = instance;
	return ;
}

ScalarTypes::~ScalarTypes()
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

ScalarTypes	&ScalarTypes::operator=(ScalarTypes const &rhs)
{
	if (this != &rhs) {
		this->_str = rhs.getStr();
		this->_double = rhs.getDouble();
		this->_int = rhs.getInt();
		this->_char = rhs.getChar();
		this->_float = rhs.getFloat();
	}
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

void    ScalarTypes::setStr(std::string str) {
	this->_str = str;
}

std::string	ScalarTypes::getStr(void) const {
	return (this->_str);
}

char	ScalarTypes::getChar(void) const {
	return (this->_char);
}

int	ScalarTypes::getInt(void) const {
	return (this->_int);
}

float	ScalarTypes::getFloat(void) const {
	return (this->_float);
}

double	ScalarTypes::getDouble(void) const {
	return (this->_double);
}


/******************************************************************************
 * MEMBER FUNCTIONS
 */

/* Check type */

bool	ScalarTypes::_isInt(void)
{
	
}

bool	ScalarTypes::_isChar(void)
{
	
}

bool	ScalarTypes::_isFloat(void)
{
	
}

bool	ScalarTypes::_isDouble(void)
{
	
}

bool	ScalarTypes::_isNanInf(void)
{
	
}


/* cast to char */
void	ScalarTypes::fromChar(void) {
	this->_char = this->_str[0];
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}

/* cast to int */
void	ScalarTypes::fromInt(void) {
	this->_int = atoi(this->_str.c_str());
	this->_char = static_cast<char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
	this->_double = static_cast<double>(this->getDouble());
}

/* cast to float */
void	ScalarTypes::fromFloat(void) {
	this->_float = atof(this->_str.c_str());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
	this->_double = static_cast<double>(this->getFloat());
}

/* cast to double */
void	ScalarTypes::fromDouble(void) {
	this->_double = atof(this->_str.c_str());
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}
