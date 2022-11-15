/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:47 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:48 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

int FragTrap::hitPointsInit = 100;
int FragTrap::energyPointsInit = 100;
int FragTrap::attackDamageInit = 30;

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setHitPoints(FragTrap::hitPointsInit);
	this->setEnergyPoints(FragTrap::energyPointsInit);
	this->setAttackDamage(FragTrap::attackDamageInit);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap "
				<< name
	            << " is created."
	            << std::endl;
	this->setHitPoints(FragTrap::hitPointsInit);
	this->setEnergyPoints(FragTrap::energyPointsInit);
	this->setAttackDamage(FragTrap::attackDamageInit);
}

FragTrap::FragTrap(FragTrap const &instance): ClapTrap(instance)
{
	std::cout << "FragTrap"
	          << " is a copy of "
	          << instance.getName()
	          << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap "
				<< this->getName()
				<< " is destroyed."
				<< std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

/******************************************************************************
 * FUNCTION MEMBER
 */

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap "
				<< this->getName()
				<< " is giving high fives to everyone."
				<< std::endl;
}
