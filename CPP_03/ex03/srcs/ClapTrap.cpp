/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:21:31 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:21:32 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

ClapTrap::ClapTrap(void): _name(), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap "
				<< this->getName()
				<< " is created."
				<< std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap "
				<< this->getName()
				<< " is destroyed."
				<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &instance): _name(instance.getName()), _hitPoints(instance.getHitPoints()), _energyPoints(instance.getEnergyPoints()), _attackDamage(instance.getAttackDamage())
{
	*this = instance; // *this = ClapTrap instance
	std::cout << "ClapTrap"
				<< " is a copy of "
				<< instance.getName()
				<< std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (&rhs != this) // self-assignment check expected
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

/******************************************************************************
 * FUNCTION MEMBER
 */

void    ClapTrap::attack(std::string const &target) {
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
	{
		std::cout << this->getName()
					<< " has no energy left."
					<< std::endl;
		return ;
	}
	energyCost();
	std::cout << this->getName()
				<< " attacks "
	            << target
				<< ", causing "
				<< this->getAttackDamage()
	            << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() < 1)
	{
		std::cout << this->getName()
					<< " has no hit points left."
					<< std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() - amount);
	if (this->getHitPoints() < 0)
		this->setHitPoints(0);
	std::cout << this->getName()
				<< " takes "
				<< amount
		        << " points of damage!"
		        << "\nCurrent hit points: "
		        << this->getHitPoints()
		        << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
	if (energyCost() == 0) {
		std::cout << this->getName()
		            << " has no energy left."
		            << std::endl;
		return ;
	}
	if (this->getHitPoints() < 1)
	{
		std::cout << this->getName()
					<< " has no hit points left."
					<< std::endl;
		return ;
	}
	if (amount < 1) {
		std::cout << "Wrong amount of hit points to repair."
		          << std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << this->getName()
		        << " is repaired by "
		        << amount
		        << " points!"
				<< "\nCurrent hit points: "
				<< this->getHitPoints()
		        << std::endl;
}

int    ClapTrap::energyCost(void) {
	if (this->getEnergyPoints() < 1)
		this->setEnergyPoints(0);
	else
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	return (this->getEnergyPoints());
}

/******************************************************************************
 * GETTERS / SETTERS
 */

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int			ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

int			ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

int			ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void		ClapTrap::setName(std::string name) {
	this->_name = name;
}

void		ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->_hitPoints = hitPoints;
}

void		ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->_energyPoints = energyPoints;
}

void		ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->_attackDamage = attackDamage;
}

