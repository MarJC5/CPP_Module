/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

MateriaSource::MateriaSource(void) : _materia(), _type()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &instance)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (instance._materia[i] != NULL)
			this->_materia[i] = instance._materia[i]->clone();
		else
			this->_materia[i] = NULL;
		this->_type[i] = instance._type[i];
	}
	return ;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	return ;
}

/******************************************************************************
 * OPERATORS
 */

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL){
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
		if (rhs._materia[i] != NULL)
			this->_materia[i] = rhs._materia[i]->clone();
		else
			this->_materia[i] = NULL;
		this->_type[i] = rhs._type[i];
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = m;
			this->_type[i] = m->getType();
			break;
		}
	}
	if (this->_materia[3] != NULL)
		std::cout << "MateriaSource is full" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++) {
		if (this->_type[i] == type) {
			return (this->_materia[i]->clone());
		}
	}
	return (NULL);
}
