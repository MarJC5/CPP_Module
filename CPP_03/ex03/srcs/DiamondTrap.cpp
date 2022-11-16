/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:56 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:56 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->setHitPoints(FragTrap::hitPointsInit);
	this->setEnergyPoints(ScavTrap::energyPointsInit);
	this->setAttackDamage(FragTrap::attackDamageInit);
	std::cout << "DiamondTrap "
	          << this->getName()
	          << " is created."
	          << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &instance) : ClapTrap(instance), ScavTrap(instance), FragTrap(instance)
{
	this->setName(instance.getName());
	std::cout << "DiamondTrap"
	          << " is a copy of "
	          << instance.getName()
	          << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap "
	          << this->getName()
	          << " is destroyed."
	          << std::endl;
	return ;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->_name = rhs.getName();
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << this->_name
				<< " is a "
				<< ClapTrap::getName()
	            << std::endl;
}
