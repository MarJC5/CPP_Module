/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:18:43 by jmartin           #+#    #+#             */
/*   Updated: 2022/10/25 09:18:43 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields[5] = {
	"first name",
	"Last name",
	"nickname",
	"phone number",
	"darkest secret"
};

int Contact::_NbContact = 0;

void    Contact::Contact(){
	std::cout << "Contact constructor called" << std::endl;
	Contact::_NbContact += 1;
	return;
}

void    Contact::~Contact(void) {
	std::cout << "Contact destructor called" << std::endl;
	Contact::_NbContact -= 1;
	return;
}

bool    Contact::saveContact() {
	std::cout << "# Please fill the following: " << std::endl;
	for (int i = this->_user::firstName; i < this->_user::darkestSecret; i++) {
		std::cout << "# " << this->_fields[i] << ":" << std::endl;
		std::getline(std::cin, this->_details[i]);
	}
	std::cout << "Contact added to phonebook." << std::endl;
	return (true);
}

void    Contact::showContact() {

}

int Contact::getNbContact(void)
{
	return Contact::_NbContact;
}