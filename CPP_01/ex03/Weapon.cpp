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

#include "Weapon.hpp"

Weapon::Weapon() {
	std::cout << "Weapon constructor called." << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon destructor called." << std::endl;
}

Weapon::Weapon(std::string type) {
	this->_type = type;
};

std::string Weapon::getType(void) {
	return (this->_type);
};

void    Weapon::setType(std::string typePTR) {
	this->_type = typePTR;
};