/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:54 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:18:55 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl( void ) {};

Harl::~Harl( void ) {};

void    Harl::_debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << " I really do!" << std::endl;
};

void	Harl::_info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void    Harl::_warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
};

void    Harl::_error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
};

void    Harl::complain( std::string level ) {
	std::string levels[4] = {"debug", "info", "warning", "error"};

	for (std::string::size_type i = 0; i < level.length(); ++i)
		level[i] = std::tolower(level[i]); // convert to lowercase

	for (this->_index = 0; level != levels[this->_index]; ++this->_index);

	switch (this->_index) {
		case 0:
			this->_debug();
			break;
		case 1:
			this->_info();
			break;
		case 2:
			this->_warning();
			break;
		case 3:
			this->_error();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problem]" << std::endl;
			break;
	} // Switch can run multiple condition (expression must be an int)
};