/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:34 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:16:55 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie( std::string name ): _name(name) {
	std::cout << GREEN << "Zombie "  << this->_name << " is born." << NC << std::endl;
};

Zombie::~Zombie( void ) {
	std::cout << RED << this->_name << " is dead." << NC << std::endl;
};

void Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};