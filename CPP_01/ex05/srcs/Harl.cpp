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

	void (Harl::*f[4])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error}; // array of pointers to member functions

	for (std::string::size_type i = 0; i < level.length(); ++i)
		level[i] = std::tolower(level[i]); // convert to lowercase

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*f[i])(); // call the function
			return ;
		};
	};
	std::cout << "Invalid level" << std::endl;
};