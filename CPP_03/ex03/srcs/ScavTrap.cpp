/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:40 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:40 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

int ScavTrap::hitPointsInit = 100;
int ScavTrap::energyPointsInit = 50;
int ScavTrap::attackDamageInit = 20;

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->setHitPoints(ScavTrap::hitPointsInit);
	this->setEnergyPoints(ScavTrap::energyPointsInit);
	this->setAttackDamage(ScavTrap::attackDamageInit);
	return ;
};

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap "
				<< name
	            << " is created."
	            << std::endl;
	this->setHitPoints(ScavTrap::hitPointsInit);
	this->setEnergyPoints(ScavTrap::energyPointsInit);
	this->setAttackDamage(ScavTrap::attackDamageInit);
	return ;
};

ScavTrap::ScavTrap(ScavTrap const &instance): ClapTrap(instance)
{
	std::cout << "ScavTrap"
	          << " is a copy of "
	          << instance.getName()
	          << std::endl;
	return ;
};

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap "
				<< this->getName()
				<< " is destroyed."
				<< std::endl;
	return ;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
};

/******************************************************************************
 * FUNCTION MEMBER
 */

void	ScavTrap::attack(std::string const &target) {
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
	{
		std::cout << this->getName()
		          << " has no energy left. No attack possible."
		          << std::endl;
		return ;
	}
	energyCost();
	std::cout << this->getName()
	          << " attacks "
	          << target
			  << ", causing critical damage of "
			  << this->getAttackDamage()
	          << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << this->getName()
	          << " has entered in Gate keeper mode."
	          << std::endl;
}