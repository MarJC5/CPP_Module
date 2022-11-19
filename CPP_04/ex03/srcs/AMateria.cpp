/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

AMateria::AMateria(void) : _type()
{
	std::cout << "AMateria Default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria Parametric constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &instance)
{
	*this = instance;
	std::cout << "AMateria copy of " <<  instance.getType() << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

/******************************************************************************
 * OPERATORS
 */

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	(void)rhs;
	return (*this);
}

/******************************************************************************
 * GETTERS / SETTERS
 */

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << CYAN
					<< "* shoots an ice bolt at "
					<< NC
					<< target.getName()
					<< CYAN
					<< " *" << NC << std::endl;
	else if (this->_type == "cure")
		std::cout << GREEN
					<< "* heals "
					<< NC
					<< target.getName()
					<< GREEN
					<< "'s wounds *" << NC << std::endl;
	return ;
}
