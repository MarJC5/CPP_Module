/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
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
	this->_double = atof(this->getStr().c_str());
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

/* cast to char */
void	ScalarTypes::fromChar(void) {
	this->_char = static_cast<char>(this->getStr()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}

/* cast to int */
void	ScalarTypes::fromInt(void) {
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
	this->_double = static_cast<double>(this->getDouble());
}

/* cast to float */
void	ScalarTypes::fromFloat(void) {
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
	this->_double = static_cast<double>(this->getFloat());
}

/* cast to double */
void	ScalarTypes::fromDouble(void) {
	this->_double = static_cast<double>(this->getDouble());
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}

void    ScalarTypes::checkType(void) {
	if (this->_str == "nan" || this->_str == "nanf"
		|| this->_str == "-inff" || this->_str == "+inff"
		|| this->_str == "-inf" || this->_str == "+inf")
	{
		if (this->_str == "nan")
			throw ScalarTypes::NanException();
		else if (this->_str == "nanf")
			throw ScalarTypes::NanfException();
		else
			throw ScalarTypes::ImpossibleException();
	}
	/* check if char */
	if (this->_str.length() == 1 && isprint(this->_str[0]))
		return ("char");
	/* check if int */
	else if (this->_str.find('.') == std::string::npos
			&& this->_str.find('f') == std::string::npos)
		return ("int");
	/* check if float */
	else if (this->_str.find('.') != std::string::npos
			&& this->_str.find('f') != std::string::npos)
		return ("float");
	/* check if double */
	else if (this->_str.find('.') != std::string::npos
			&& this->_str.find('f') == std::string::npos)
		return ("double");
	else
		throw ScalarTypes::ImpossibleException();
}

void    ScalarTypes::display(void) {
	/*
	 * display the value of the char
	 */
	std::cout << "char: ";
	if (this->getChar() < 32 || this->getChar() > 126)
		std::cout << "'" << this->getChar() << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	/*
	 * display the value of the int
	 */
	std::cout << "int: ";
	if (this->getInt() < std::numeric_limits<int>::min() || this->getInt() > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->getInt() << std::endl;
	/*
	 * display the value of the float
	 */
	std::cout << "float: ";
	if (this->getFloat() < std::numeric_limits<float>::min() || this->getFloat() > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << this->getFloat() << "f" << std::endl;
	/*
	 * display the value of the double
	 */
	std::cout << "double: ";
	if (this->getDouble() < std::numeric_limits<double>::min() || this->getDouble() > std::numeric_limits<double>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << this->getDouble() << std::endl;
}
