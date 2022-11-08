/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:32 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:33 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/HumanB.hpp"

/**
 * @brief Construct a new Human B:: Human B object
 * @note
 * 	- The weapon is not initialized here, but in the setWeapon method.
 * 	- The weapon is a pointer to a Weapon object.
 */

HumanB::HumanB( std::string name ) : _name(name) {
	std::cout << "HumanB constructor called." << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "HumanB destructor called." << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}