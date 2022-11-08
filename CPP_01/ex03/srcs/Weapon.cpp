/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:45 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:17:46 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->setType(type);
};

Weapon::~Weapon( void ) {
	std::cout << "Weapon destructor called." << std::endl;
}

std::string const &Weapon::getType(void) { // const & is a reference to a const object (can't be modified)
	return (this->_type);
};

void    Weapon::setType(std::string type) {
	this->_type = type;
};