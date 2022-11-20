/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:24 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:25 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Character::Character(void): _name(), _inventory()
{
	std::cout << "Character Default constructor called" << std::endl;
	return ;
}

Character::Character(std::string const & name) : _name(name), _inventory()
{
	std::cout << "Character "
				<< GREY
				<< name
				<< NC
				<< " is alive"
				<< std::endl;
	return ;
}

Character::Character(Character const &instance) {
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = instance.getName();
	// copy the inventory
	for (int i = 0; i < 4; i++)
	{
		if (instance._inventory[i])
			this->_inventory[i] = instance._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return ;
}

Character::~Character(void) {
	std::cout << "Character "
				<< GREY
				<< this->getName()
				<< NC
				<< " is dead." << std::endl;
	// Delete all the inventory items before leaving the destructor (if any)
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Character	&Character::operator=(Character const &rhs) {
	if (&rhs != this) // self-assignment check expected
	{
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i] != NULL) {
				delete this->_inventory[i];
				_inventory[i] = NULL;
			}
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << "Materia "
						<< GREY
						<< m->getType()
						<< NC
						<< " equipped"
						<< std::endl;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		std::cout << "Unequipped slot "
					<< GREY
					<< this->_inventory[idx]->getType()
					<< NC
					<< std::endl;
		if (this->_inventory[idx] != NULL) {
			delete this->_inventory[idx];
			this->_inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4)
		this->_inventory[idx]->use(target);
	else
		std::cout << "No materia at this index" << std::endl;
}
