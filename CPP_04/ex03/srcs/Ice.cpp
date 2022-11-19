/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &instance) : AMateria(instance)
{
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Ice	&Ice::operator=(Ice const &rhs)
{
	(void)rhs;
	return (*this);
}

/******************************************************************************
* MEMBER FUNCTIONS
*/

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}
