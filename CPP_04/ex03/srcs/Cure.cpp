/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &instance) : AMateria(instance)
{
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Cure	&Cure::operator=(Cure const &rhs)
{
	(void)rhs;
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}


