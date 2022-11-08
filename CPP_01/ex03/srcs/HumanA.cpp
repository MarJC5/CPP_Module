/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:20 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:21 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

/**
 * @brief Construct a new Human A:: Human A object
 * @note
 * - The weapon is mandatory, so it is initialized in the constructor.
 */

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) {
	std::cout << "HumanA constructor called." << std::endl;
}

HumanA::~HumanA( void ) {
	std::cout << "HumanA destructor called." << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}