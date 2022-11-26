/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/26 15:33:34 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarTypes.hpp"

ScalarTypes::ScalarTypes(void) {}

ScalarTypes::ScalarTypes(std::string str) : _str(str) {}

ScalarTypes::~ScalarTypes(void) {}

ScalarTypes::ScalarTypes(ScalarTypes const &instance)
{
	*this = instance;
}

ScalarTypes &ScalarTypes::operator=(ScalarTypes const &rhs)
{
	this->_str = rhs._str;
	return *this;
}

void	ScalarTypes::_convChar(void) {
	if (std::isnan(this->_double)
		|| std::isinf(this->_double)
		|| this->_double  < 0
		|| this->_double  > 127)
		std::cout << "char: impossible" << std::endl;
	else if((this->_double < 127 && this->_double > 31))
		std::cout << "char: '" << static_cast<char>(this->_double) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void    ScalarTypes::_convInt(void) {
	if (std::isnan(this->_double)
		|| std::isinf(this->_double)
		|| this->_double > std::numeric_limits<int>::max()
		|| this->_double < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->_double) << std::endl;
}

void    ScalarTypes::_convFloat(void) {
	this->_float = static_cast<float>(this->_double);
	std::cout << "float: " << this->_float;
	if (!(std::isnan(this->_float)
		|| std::isinf(this->_float)) && this->_str.find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void    ScalarTypes::_convDouble(void) {
	std::cout << "double: " << this->_double;
	if (!(std::isnan(this->_double)
		|| std::isinf(this->_double)) && this->_str.find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarTypes::convert(void)
{
	if(this->_str.length() == 1 && !std::isdigit(this->_str[0]))
		this->_double = static_cast<double>(this->_str[0]);
	else
		this->_double = atof(this->_str.c_str());
	/*
	 * Convert and print stuff
	 */
	this->_convChar();
	this->_convInt();
	this->_convFloat();
	this->_convDouble();
}
